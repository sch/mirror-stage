
/**************************
 * Rendering Functions
 *
 **************************/

#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#else
#include <SDL.h>
#include <SDL_opengl.h>
#endif

#include <string>
#include <math.h>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <stdexcept>

const GLfloat Pi = 3.1415926535f;

inline GLfloat min(GLfloat a, GLfloat b)
{
  return(a < b ? a : b);
}

inline GLfloat max(GLfloat a)
{
  return a;
}
inline GLfloat max(GLfloat a, GLfloat b)
{
  return(a > b ? a : b);
}
inline GLfloat max(GLfloat a, GLfloat b, GLfloat c)
{
  return max(a, max(b, c));
}

inline GLfloat square(GLfloat x)
{
  return x * x;
}

inline GLfloat hypotenuse(GLfloat a, GLfloat b)
{
  return sqrt(square(a) + square(b));
}

const GLfloat flip_y[4][4]  =
{
  {1.0f,0.0f,0.0f,0.0f},
  {0.0f,-1.0f,0.0f,0.0f},
  {0.0f,0.0f,1.0f,0.0f},
  {0.0f,0.0f,0.0f,1.0f}
};

const GLfloat flip_x[4][4]  =
{
  {-1.0f, 0.0f, 0.0f, 0.0f},
  {0.0f, 1.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 1.0f, 0.0f},
  {0.0f, 0.0f, 0.0f, 1.0f}
};

class CVector3
{
  public:
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

std::string stringify(int x)
{
  std::ostringstream o;
  o << x;
  return o.str();
}

GLfloat
lengthsq(GLfloat x, GLfloat y)
{
  return square(x) + square(y);
}

GLfloat
length(GLfloat x, GLfloat y)
{
  return sqrt(lengthsq(x, y));
}

//returns relative orientation of two vectors
int
parity(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
  return (((x1 * y2) - (x2 * y1)) > 0) ? -1 : +1;
}

GLfloat
angle(GLfloat x, GLfloat y)
{
  return -atan2f(y, x);
{
  return (atan2f(y2,x2) - atan2f(y1,x1));
}

GLfloat
MidpointRatio(GLfloat p1, GLfloat p2, GLfloat q1, GLfloat q2, GLfloat r1, GLfloat r2)
{
  GLfloat as = lengthsq(p1-r1, p2-r2);
  GLfloat bs = lengthsq(q1-p1, q2-p2);
  GLfloat cs = lengthsq(q1-r1, q2-r2);

  return 0.5 * (((as - cs) / bs) + 1);
}

/*
   entity movement stuff
   */
inline GLfloat slope(GLfloat x, GLfloat y)
{
  return y / x;
}

GLfloat
distfromline(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x, GLfloat y)
{
  GLfloat A = x - x1;
  GLfloat B = y - y1;
  GLfloat C = x2 - x1;
  GLfloat D = y2 - y1;

  GLfloat dot = A * C + B * D;
  GLfloat len_sq = C * C + D * D;
  GLfloat len_sq = lengthsq(C, D);
  GLfloat param = dot / len_sq;

  GLfloat xx,yy;

  if (param < 0)
  {
    xx = x1;
    yy = y1;
  }
  else if (param > 1)
  {
    xx = x2;
    yy = y2;
  }
  else
  {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  return length(yy-y, xx-x);//your distance function
}

GLfloat
distfromlinesq(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x, GLfloat y)
{
  GLfloat A = x - x1;
  GLfloat B = y - y1;
  GLfloat C = x2 - x1;
  GLfloat D = y2 - y1;

  GLfloat dot = A * C + B * D;
  GLfloat len_sq = lengthsq(C, D);
  GLfloat param = dot / len_sq;

  GLfloat xx, yy;

  if (param < 0)
  {
    xx = x1;
    yy = y1;
  }
  else if(param > 1)
  {
    xx = x2;
    yy = y2;
  }
  else
  {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  return lengthsq(yy-y, xx-x);//your distance function
}

//replaces the fourth point with the point on the segment P1-P2 closest to P3
void
closest_point(GLfloat x1 ,GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat* x4, GLfloat* y4)
{
  GLfloat u = ((x3-x1)*(x2-x1)+(y3-y1)*(y2-y1))/lengthsq(x2-x1,y2-y1);
  *x4 = x1+u*(x2-x1);
  *y4 = y1+u*(y2-y1);
}


bool
segmentsIntersect(GLfloat Ax, GLfloat Ay,
                  GLfloat Bx, GLfloat By,
                  GLfloat Cx, GLfloat Cy,
                  GLfloat Dx, GLfloat Dy)
{
  GLfloat distAB, theCos, theSin, newX, ABpos;

  //  (1) Translate the system so that point A is on the origin.
  Bx -= Ax; By -= Ay;
  Cx -= Ax; Cy -= Ay;
  Dx -= Ax; Dy -= Ay;

  //  Discover the length of segment A-B.
  distAB = sqrt(Bx*Bx + By*By);

  //  (2) Rotate the system so that point B is on the positive X axis.
  theCos = Bx / distAB;
  theSin = By / distAB;
  newX = Cx * theCos + Cy * theSin;
  Cy = Cy * theCos - Cx * theSin; Cx = newX;
  newX = Dx * theCos + Dy * theSin;
  Dy = Dy * theCos - Dx * theSin; Dx = newX;

  //  Fail if segment C-D doesn't cross line A-B.
  if (Cy < 0.0f && Dy < 0.0f || Cy >= 0.0f && Dy >= 0.0f) return false;

  //  (3) Discover the position of the intersection point along line A-B.
  ABpos = Dx + (Cx - Dx) * Dy / (Dy - Cy);

  //  Fail if segment C-D crosses line A-B outside of segment A-B.
  if (ABpos < 0.0f || ABpos > distAB) return false;

  //  Success.
  return true;
}


bool
lineSegmentIntersection(GLfloat Ax, GLfloat Ay,
                        GLfloat Bx, GLfloat By,
                        GLfloat Cx, GLfloat Cy,
                        GLfloat Dx, GLfloat Dy,
                        GLfloat *X, GLfloat *Y)
{

  GLfloat distAB, theCos, theSin, newX, ABpos;

  //  (1) Translate the system so that point A is on the origin.
  Bx -= Ax; By -= Ay;
  Cx -= Ax; Cy -= Ay;
  Dx -= Ax; Dy -= Ay;

  //  Discover the length of segment A-B.
  distAB = length(Bx, By);

  //  (2) Rotate the system so that point B is on the positive X axis.
  theCos = Bx/distAB;
  theSin = By/distAB;
  newX = Cx*theCos + Cy*theSin;
  Cy   = Cy*theCos - Cx*theSin;
  Cx   = newX;
  newX = Dx*theCos + Dy*theSin;
  Dy   = Dy*theCos - Dx*theSin;
  Dx   = newX;

  //  Fail if segment C-D doesn't cross line A-B.
  if (Cy<0.0f && Dy<0.0f || Cy >= 0.0f && Dy >= 0.0f) return false;

  //  (3) Discover the position of the intersection point along line A-B.
  ABpos = Dx+(Cx-Dx)*Dy/(Dy-Cy);

  //  Fail if segment C-D crosses line A-B outside of segment A-B.
  if (ABpos<0.0f || ABpos>distAB) return false;

  //  (4) Apply the discovered position to line A-B in the original coordinate system.
  *X=Ax+ABpos*theCos;
  *Y=Ay+ABpos*theSin;

  //  Success.
  return true;
}

typedef struct GL_Point {
  GLfloat x;
  GLfloat y;
}

typedef struct GL_Triangle {
  GL_Point p1;
  GL_Point p2;
  GL_Point p3;
}

typedef struct GL_Rectangle {
  GL_Point p1;
  GL_Point p2;
  GL_Point p3;
  GL_Point p4;
}

bool
point_intersects_triangle(GL_Point point, GL_Triangle triangle) {
  if (!point_in_triangle_bounding_box(triangle, point)) return false;
  return false;
}

//test if either of two points is in a triangle
bool
triangleintersect(GLfloat tx1, GLfloat ty1, GLfloat tx2, GLfloat ty2, GLfloat tx3, GLfloat ty3, GLfloat px, GLfloat py, GLfloat qx, GLfloat qy)
{

  // Compute vectors
  GLfloat vx0 = tx3 - tx1;
  GLfloat vy0 = ty3 - ty1;
  GLfloat vx1 = tx2 - tx1;
  GLfloat vy1 = ty2 - ty1;
  GLfloat vx2a = px - tx1;
  GLfloat vy2a = py - ty1;
  GLfloat vx2b = qx - tx1;
  GLfloat vy2b = qy - ty1;

  // Compute dot products
  GLfloat dot00 = vx0*vx0+vy0*vy0;
  GLfloat dot01 = vx0*vx1+vy0*vy1;
  GLfloat dot02a = vx0*vx2a+vy0*vy2a;
  GLfloat dot02b = vx0*vx2b+vy0*vy2b;
  GLfloat dot11 = vx1*vx1+vy1*vy1;
  GLfloat dot12a = vx1*vx2a+vy1*vy2a;
  GLfloat dot12b = vx1*vx2b+vy1*vy2b;

  // Compute barycentric coordinates
  GLfloat invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
  GLfloat ua = (dot11 * dot02a - dot01 * dot12a) * invDenom;
  GLfloat ub = (dot11 * dot02b - dot01 * dot12b) * invDenom;
  GLfloat va = (dot00 * dot12a - dot01 * dot02a) * invDenom;
  GLfloat vb = (dot00 * dot12b - dot01 * dot02b) * invDenom;

  // Check if point is in triangle
  return ((ua > 0) && (va > 0) && ((ua + va) < 1)) || ((ub > 0) && (vb > 0) && ((ub + vb) < 1)) ;

  GL_Point point1 = { px, py };
  GL_Point point2 = { qx, qy };
  GL_Triangle triangle = {
    GL_Point { tx1, ty1 };
    GL_Point { tx2, ty2 };
    GL_Point { tx3, ty3 };
  }

  return point_intersects_triangle(point1, triangle) || point_intersects_triangle(point2, triangle);
}


/* fast computation to see if point is inside of a triangle's bounding box
 * used to break out of a more expensive check for being within the confines of
 * a triangle
 * return bool;
 */
bool
point_in_triangle_bounding_box(GL_Point point, GL_Triangle triangle) {
  GLfloat epsilon = 0.01;
  GL_Rect triangle_rect = triangle_bounding_box_rect(triangle);
  bool point_is_within_width  = within(triangle_rect.x, point.x, (triangle_rect.w - triangle_rect.x));
  bool point_is_within_height = within(triangle_rect.y, point.y, (triangle_rect.h - triangle_rect.y));
  return point_is_within_width && point_is_within_height;
}

GL_Rectangle
SDL_rect_to_GL_Rectangle(SDL_Rect rect) {
  GL_Point top_left = {rect.x, rect.y};
  GL_Point top_right = {rect.x, (rect.w - rect.y)};
  GL_Rectangle rectangle = {top_left, top_right, bottom_right, bottom_left};
  return rectangle;
}

SDL_Rect
SDL_Rect_to_GL_Rectangle(GL_Rectangle rect) {
}

bool
point_is_within_sdl_rect(GL_Point point, SDL_rect rect) {
  bool point_is_within_width = within(triangle_rect.x, point.x, (triangle_rect.w - triangle_rect.x));
  bool point_is_within_height = within(triangle_rect.y, point.y, (triangle_rect.h - triangle_rect.y));
  return point_is_within_width && point_is_within_height;
}

bool
point_is_within_GL_Rectangle(GL_Point point, GL_Rectangle rectangle) {
  return (within(rectangle.p1.x, point.x, rectangle.p2.x) &&
          within(rectangle.p1.y, point.y, rectangle.p4.y));
}

bool
within(GLfloat lower_bound, GLfloat candidate, GLfloat upper_bound) {
  return lower_bound <= candidate && candidate <= upper_bound;
}

/*
 * Returns an SDL_Rect that contains the triangle
 */
SDL_Rect
triangle_bounding_box_rect(GL_Triangle triangle) {
  GLfloat min_x, max_x, min_y, max_y;

  min_x = min(triangle.p1.x, triangle.p2.x, triangle.p3.x);
  max_x = max(triangle.p1.x, triangle.p2.x, triangle.p3.x);
  min_y = min(triangle.p1.y, triangle.p2.y, triangle.p3.y);
  max_y = max(triangle.p1.y, triangle.p2.y, triangle.p3.y);

  SDL_Rect rectangle;
  rectangle.x = min_x;
  rectangle.y = min_y;
  rectangle.w = max_x - min_x;
  rectangle.h = max_y - min_y;

  return rectangle;
}

/*
 * Returns an SDL_Rect that contains the triangle with an epsilon padding
 */
SDL_Rect
triangle_bounding_box_rect(GL_Triangle triangle, GLfloat epsilon) {
  SDL_Rect unpadded_rect, padded_rect;

  unpadded_rect = triangle_bounding_box_rect(triangle);

  padded_rect.x = unpadded_rect.x - epsilon;
  padded_rect.y = unpadded_rect.y - epsilon;
  padded_rect.w = unpadded_rect.w + epsilon;
  padded_rect.h = unpadded_rect.h + epsilon;

  return padded_rect;
}



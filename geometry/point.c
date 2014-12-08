#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#else
#include <SDL.h>
#include <SDL_opengl.h>
#endif

#include <math.h>

struct GL_Point {
    GLfloat x;
    GLfloat y;
};

GLfloat
point_width(GL_Point a, GL_Point b)
{
    return abs(point_dx(a, b));
}

GLfloat
point_height(GL_Point a, GL_Point b)
{
    return abs(point_dy(a, b));
}

GLfloat
point_dx(GL_Point a, GL_Point b)
{
    return a.x - b.x;
}

GLfloat
point_dy(GL_Point a, GL_Point b)
{
    return a.y - b.y;
}

GLfloat
point_square_distance(GL_Point a, GL_Point b)
{
    return square_distance(width(a, b), height(a, b));
}

GLfloat
point_distance(GL_Point a, GL_Point b)
{
    return hypot(width(a, b), height(a, b));
}

GL_Point
new_point(GLfloat x, GLfloat y)
{
    return GL_Point {x, y};
}

GL_Point
sum_points(GL_Point a, GL_Point b)
{
    return new_point(a.x + b.x, a.y + b.y);
}

GL_Point
midpoint(GL_Point a, GL_Point b)
{
    GLfloat x = (a.x + b.x) / 2;
    GLfloat y = (a.y + b.y) / 2;
    return new_point(x, y);
}

double
point_dot_product(GL_Point a, GL_point b)
{
    return dot_product(a.x, a.y, b.x, b.y);
}

double
point_cross_product(GL_Point a, GL_point b)
{
    return cross_product(a.x, a.y, b.x, b.y);
}

#include "point.c"

struct Triangle {
    Point p1;
    Point p2;
    Point p3;
}

bool
point_intersects_triangle(Point point, Triangle triangle) {
    if (!point_in_triangle_bounding_box(triangle, point)) return false;
    return false;
}

/* fast computation to see if point is inside of a triangle's bounding box
 * used to break out of a more expensive check for being within the confines of
 * a triangle
 */
bool
point_in_triangle_bounding_box(GL_Point point, GL_Triangle triangle) {
    GLfloat epsilon = 0.01;
    Rectangle bounds = triangle_bounding_box_rect(triangle);
    return point_is_within_rectangle(point, bounds);
}


/*
 * Returns a Rectangle that contains the triangle
 */
Rectangle
triangle_bounding_box(Triangle triangle)
{
    GLfloat min_x = min(triangle.p1.x, triangle.p2.x, triangle.p3.x);
    GLfloat max_x = max(triangle.p1.x, triangle.p2.x, triangle.p3.x);
    GLfloat min_y = min(triangle.p1.y, triangle.p2.y, triangle.p3.y);
    GLfloat max_y = max(triangle.p1.y, triangle.p2.y, triangle.p3.y);

    return new_rectangle(min_x, min_y, max_x, max_y);
}

/*
 * Returns a Rectangle that contains the triangle with an epsilon padding
 */
Rectangle
triangle_bounding_box(Triangle triangle, double epsilon)
{
    Rectangle unpadded_rect, padded_rect;

    unpadded_rect = triangle_bounding_box_rect(triangle);

    padded_rect.p1.x = unpadded_rect.p1.x - epsilon;
    padded_rect.p1.y = unpadded_rect.p1.y - epsilon;
    padded_rect.p2.x = unpadded_rect.p2.x + epsilon;
    padded_rect.p2.y = unpadded_rect.p2.y + epsilon;

    return padded_rect;
}

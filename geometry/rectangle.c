#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#else
#include <SDL.h>
#include <SDL_opengl.h>
#endif

#include "point.c"

/* p1────────┐
 * │          │
 * │          │
 * └────────p2
 */
struct Rectangle {
    Point p1;
    Point p2;
};

Rectangle
new_rectangle(double p1x, double p1y, double p2x, double p2y)
{
    return Rectangle {Point {p1x, p1y}, Point {p2x, p2y}};
}

Rectangle
rectangle_from_SDL_Rect(SDL_Rect rect)
{
    return new_rectangle(rect.x, rect.y, rect.x + rect.width, rect.y + rect.height);
}

bool
point_is_within_rectangle(Point point, Rectangle rectangle) {
    return (point_is_within_rectangle_width(point, rectangle) &&
            point_is_within_rectangle_height(point, rectangle));
}

bool
point_is_within_rectangle_width(Point point, Rectangle rectangle)
{
    return within(rectangle.p1.x, point.x, rectangle.p2.x);
}

bool
point_is_within_rectangle_height(Point point, Rectangle rectangle)
{
    return within(rectangle.p1.y, point.y, rectangle.p2.y);
}

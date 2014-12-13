#include <stdlib.h>
#include <math.h>
#include "../moremath.c"

struct Point {
    double x;
    double y;
};

struct Point
new_point(double x, double y)
{
    struct Point point;
    point.x = x;
    point.y = y;
    return point;
}

double
point_dx(struct Point a, struct Point b)
{
    return a.x - b.x;
}

double
point_dy(struct Point a, struct Point b)
{
    return a.y - b.y;
}

double
point_width(struct Point a, struct Point b)
{
    return abs(point_dx(a, b));
}

double
point_height(struct Point a, struct Point b)
{
    return abs(point_dy(a, b));
}

double
point_distance(struct Point a, struct Point b)
{
    return hypot(point_width(a, b), point_height(a, b));
}

double
point_square_distance(struct Point a, struct Point b)
{
    return square_distance(point_width(a, b), point_height(a, b));
}

struct Point
sum_points(struct Point a, struct Point b)
{
    return new_point(a.x + b.x, a.y + b.y);
}

struct Point
midpoint(struct Point a, struct Point b)
{
    double x = (a.x + b.x) / 2;
    double y = (a.y + b.y) / 2;
    return new_point(x, y);
}

double
point_dot_product(struct Point a, struct Point b)
{
    return dot_product(a.x, a.y, b.x, b.y);
}

double
points_slope(struct Point a, struct Point b)
{
    return (b.y - a.y) / (b.x - a.x);
}

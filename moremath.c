#include <math.h>
#include <stdbool.h>

double
square(double x)
{
    return x * x;
}

double
square_distance(double x, double y)
{
    return square(x) + square(y);
}

double
dot_product(double ax, double ay, double bx, double by)
{
    return ax * bx + ay * by;
}

double
cross_product(double ax, double ay, double bx, double by)
{
    return ax * by + ay * bx;
}

bool
within(double lower_bound, double candidate, double upper_bound) {
    return lower_bound <= candidate && candidate <= upper_bound;
}

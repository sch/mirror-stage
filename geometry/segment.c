#include "point.c"

struct Segment {
    struct Point start;
    struct Point end;
};

struct Segment
new_segment(double p1x, double p1y, double p2x, double p2y)
{
    struct Segment segment;
    segment.start = new_point(p1x, p1y);
    segment.end = new_point(p2x, p2y);
    return segment;
}

double
segment_length_squared(struct Segment segment)
{
    return point_square_distance(segment.start, segment.end);
}

double
segment_dot_product(struct Segment segment)
{
    return point_dot_product(segment.start, segment.end);
}

double
segment_dx(struct Segment segment)
{
    return point_dx(segment.start, segment.end);
}

double
segment_dy(struct Segment segment)
{
    return point_dy(segment.start, segment.end);
}


double
segment_length(struct Segment segment)
{
    return point_distance(segment.start, segment.end);
}

double
distance_from_segment(struct Point point, struct Segment segment)
{
    double square_length = segment_length_squared(segment);
    if (square_length == 0.0) return point_distance(point, segment.start);
    double t = dot_product(point_dx(segment.end, segment.start),
                           point_dy(segment.start, segment.end),
                           point_dx(point, segment.start),
                           point_dy(point, segment.start) / square_length);
    if (t < 0) return point_square_distance(point, segment.start);
    if (1 < t) return point_square_distance(point, segment.end);
    return point_square_distance(point, new_point((segment.start.x + t) * point_dx(segment.start, segment.end),
                                                  (segment.start.y + t) * point_dy(segment.start, segment.end)));
}

bool
point_falls_on_segment(struct Point point, struct Segment segment)
{
    return false;
}

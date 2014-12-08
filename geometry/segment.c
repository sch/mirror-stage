#include "point.c";

struct Segment {
    GL_Point start;
    GL_Point end;
};

GLfloat
segment_length(Segment segment)
{
    return point_distance(segment.start, segment.end);
}

double
distance_from_segment(GL_Point point, Segment segment)
{
    double square_length = point_square_distance(segment.start, segment.end);
    if (square_length == 0.0) return point_distance(point, segment.start);
}

bool
point_lies_along_segment_line(Point point, Segment segment)
{
    return false;
}

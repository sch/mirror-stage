#include "../test_helper.c"
#include "../../geometry/segment.c"

void print_distance(double distance)
{
    printf("\n\ndistance was: %f\n\n", distance);
}

void test_segment_length()
{
    struct Segment segment = new_segment(3, 3, 7, 6);
    assert(5 == segment_length(segment));
}

void test_distance_from_segment()
{
    struct Segment segment  = new_segment(-3, 3, 6, 0);
    struct Point   point    = new_point(-2, -4);
    double         distance = distance_from_segment(point, segment);
    print_distance(distance);
    assert(6.32 < distance && distance < 6.33);
}

void test_point_falls_on_segment()
{
    struct Segment segment  = new_segment(-3, 3, 6, 0);
    struct Point   point    = new_point(-2, -4);
    assert(point_falls_on_segment(point, segment));
}

int main()
{
    printf("\nSegment tests:\n");
    run_test(test_segment_length);
    pending_test(test_distance_from_segment);
    run_test(test_point_falls_on_segment);
}

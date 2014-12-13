#include "../test_helper.c"
#include "../../geometry/point.c"

#define run_test(function_name)\
    printf("  %s\n", #function_name);\
    function_name();


void test_create_point() {
    struct Point p = new_point(1, 2);
    assert(1 == p.x);
    assert(2 == p.y);
}

void test_point_dx() {
    struct Point p1 = new_point(1, 2);
    struct Point p2 = new_point(2, 4);
    assert(-1 == point_dx(p1, p2));
}

void test_point_dy() {
    struct Point p1 = new_point(1, 2);
    struct Point p2 = new_point(2, 4);
    assert(-2 == point_dy(p1, p2));
}

void test_point_width() {
    struct Point p1 = new_point(1, 2);
    struct Point p2 = new_point(2, 4);
    assert(1 == point_width(p1, p2));
}

void test_point_height() {
    struct Point p1 = new_point(1, 2);
    struct Point p2 = new_point(2, 4);
    assert(2 == point_height(p1, p2));
}

void test_point_distance() {
    struct Point p1 = new_point(0, 0);
    struct Point p2 = new_point(4, 3);
    assert(5 == point_distance(p1, p2));
}

void test_point_square_distance() {
    struct Point p1 = new_point(0, 0);
    struct Point p2 = new_point(4, 3);
    assert(25 == point_square_distance(p1, p2));
}

void test_sum_points() {
    struct Point p1 = new_point(3, 4);
    struct Point p2 = new_point(4, 3);
    struct Point candidate = sum_points(p1, p2);
    assert(7 == candidate.x);
    assert(7 == candidate.y);
}

void test_midpoint() {
    struct Point p1 = new_point(-1, 2);
    struct Point p2 = new_point(3, -6);
    struct Point point = midpoint(p1, p2);
    assert(1 == point.x);
    assert(-2 == point.y);
}

void test_dot_product() {
    struct Point p1 = new_point(5, 12);
    struct Point p2 = new_point(-6, 8);
    assert(66 == point_dot_product(p1, p2));
}

void test_point_slope() {
    struct Point p1 = new_point(-2, -1);
    struct Point p2 = new_point(4, 3);
    double slope = points_slope(p1, p2);
    assert(0.666 < slope && slope < 0.667);
}

int main() {
    printf("\nPoint tests:\n");
    run_test(test_create_point);
    run_test(test_point_dx);
    run_test(test_point_dy);
    run_test(test_point_width);
    run_test(test_point_height);
    run_test(test_point_distance);
    run_test(test_point_square_distance);
    run_test(test_sum_points);
    run_test(test_midpoint);
    run_test(test_dot_product);
    run_test(test_point_slope);
}

#include "../test_helper.c"
#include "../../geometry/rectangle.c"

void print_rectangle(double distance)
{
    printf("\n\ndistance was: %f\n\n", distance);
}

void test_new_rectangle()
{
    struct Rectangle rectangle = new_rectangle(2, 3, 8, 9);
    assert(5 );
}

int main()
{
}

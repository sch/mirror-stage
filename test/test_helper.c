#include <stdio.h>
#include <assert.h>

// Macros for running tests. Usage:
//     run_test(test_name_of_test);
//     pending_test(test_name_of_test);

#define run_test(function_name)                 \
    printf("  %s\n", #function_name);           \
    function_name();

#define pending_test(function_name)             \
    printf("  %s (pending)\n", #function_name);

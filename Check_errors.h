#ifndef CHECK_ERRORS_H
#define CHECK_ERRORS_H

#define TEST_ON

#include "ANSI_colours.h"
#include "Input_output.h"

#ifndef NDEBUG
#define ASSERT(x)\
        if (!(x)) {\
                printf(ANSI_LIGHT_RED "Text in assert: (%s)\n", #x);\
                printf("File: %s\n", __FILE__);\
                printf("Function: %s\n", __PRETTY_FUNCTION__);\
                printf("Line: %d\n" ANSI_DEFAULT_COLOR, __LINE__);\
                exit(0);\
        }
#else
#define ASSERT(...)
#endif

void test(cmd_input_data cmd_data);

int check_test(coefs_roots *test_data);

#endif // CHECK_ERRORS_H

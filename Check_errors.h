#ifndef CHECK_ERRORS_H
#define CHECK_ERRORS_H

#define TEST_ON

#include "ANSI_colours.h"
#include "Input_output.h"

#ifndef NDEBUG
#define ASSERT(x)                                                   \
        if (!(x)) {                                                 \
                printf(ANSI_LIGHT_RED "Text in assert: (%s)\n", #x);\
                printf("File: %s\n", __FILE__);                     \
                printf("Function: %s\n", __PRETTY_FUNCTION__);      \
                printf("Line: %d\n" ANSI_DEFAULT_COLOR, __LINE__);  \
                exit(0);                                            \
        }
#else
#define ASSERT(...)
#endif

const int nTests = 5;

/*!
@brief Function checks if test_on and testing.
@param[in] cmd_data struct of data from cmd
@details Function checks if file of test correct and run check_test.
*/
void test(cmd_input_data *cmd_data);

/*!
@brief Function compares reference roots and number of them with calculated roots and number of them.
@param[in] test_data struct for compare, include reference roots, number of roots and coefficients
@details Function return 1 if test is OK or 0 if test failed.
*/
int check_test(coefficients *coefs_t, roots_struct *roots_t);

#endif // CHECK_ERRORS_H

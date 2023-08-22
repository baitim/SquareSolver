#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

#include "Names.h"

void check_test(double a_, double b_, double c_, double root1_, double root2_, number_roots roots);

// the function tests calculation
void test() {
        check_test(1.0f, 2.0f, 2.0f, 0.0f, 0.0f, ROOT_0);
        check_test(1.0f, 2.0f, 1.0f, -1.0f, -1.0f, ROOT_1_QUAD);
        check_test(1.0f, -3.0f, 2.0f, 1.0f, 2.0f, ROOT_2_QUAD);
        check_test(0.0f, 2.0f, 3.0f, -1.5f, -1.5f, ROOT_1_LINE);
        check_test(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_INF);
        printf(ANSI_LIGHT_GREEN "ALL TESTS ACCETPTED\n\n" ANSI_DEFAULT_COLOUR);
}

void check_test(double a_, double b_, double c_, double root1_, double root2_, number_roots roots) {
        coefs_roots data_ = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };

        data_.a = a_;
        data_.b = b_;
        data_.c = c_;

        calculation_of_roots(&data_);

        assert(is_double_equal(data_.root1, root1_) && is_double_equal(data_.root2, root2_) && data_.count_root == roots);
}

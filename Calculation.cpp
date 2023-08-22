#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#include "Names.h"

// the function calculates the roots
void calculation_of_roots(coefs_roots *data)
{
        assert(data != NULL);

        double a_ = data->a;
        double b_ = data->b;
        double c_ = data->c;

        if (is_double_equal(a_, 0)) { // equation is not square a = 0
                calculation_linear(data);
                return;
        }

        double discriminant = b_ * b_ - 4 * a_ * c_;
        if (discriminant < -EPS) {
                data->count_root = ROOT_0;
                return;
        }

        double discriminant_sqrt = sqrt(discriminant);
        if (is_double_equal(discriminant, 0)) {
                data->root1 = data->root2 = -b_ / 2 / a_;
                data->count_root = ROOT_1_QUAD;
                return;
        }
        if (discriminant > EPS) {
                data->root1 = (-b_ - discriminant_sqrt) / 2 / a_;
                data->root2 = (-b_ + discriminant_sqrt) / 2 / a_;
                data->count_root = ROOT_2_QUAD;
                return;
        }
        data->count_root = ROOT_ERR;
}

// the function calculates the roots if the equation is linear
void calculation_linear(coefs_roots *data)
{
        assert(data != NULL);

        double b_ = data->b;
        double c_ = data->c;

        if (!is_double_equal(b_, 0)) {
                data->root1 = data->root2 = -c_ / b_;
                data->count_root = ROOT_1_LINE;
        } else {
                data->count_root = (is_double_equal(c_, 0)) ? ROOT_INF : ROOT_0;
        }
}

// the function compares doubles
bool is_double_equal(double x, double y)
{
        return (fabs(x - y) <= EPS);
}

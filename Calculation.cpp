#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#include "Names.h"

// the function calculates the roots
cases_numbers_roots calculation_of_roots(coefs_roots *data)
{
        double a_ = data->a, b_ = data->b, c_ = data->c;

        if (is_double_equal(a_, 0)) // equation is not square a = 0
                return calculation_linear(data);

        double discriminant = b_ * b_ - 4 * a_ * c_;
        if (discriminant < 0)
                return ROOT_0;

        double discriminant_sqrt = sqrt(discriminant); // for optimization
        if (is_double_equal(discriminant, 0)) {
                data->root1 = -b_ / 2 / a_;
                return ROOT_1_QUAD;
        }
        if (discriminant > 0) {
                data->root1 = (-b_ - discriminant_sqrt) / 2 / a_;
                data->root2 = (-b_ + discriminant_sqrt) / 2 / a_;
                return ROOT_2_QUAD;
        }
        return ROOT_ERR;
}

// the function calculates the roots if the equation is linear
cases_numbers_roots calculation_linear(coefs_roots *data)
{
        double b_ = data->b, c_ = data->c;

        if (!is_double_equal(b_, 0)) {
                data->root1 = -c_ / b_;
                return ROOT_1_LINE;
        } else {
                if (is_double_equal(c_, 0))
                        return ROOT_INF;
                else
                        return ROOT_0;
        }
}

// the function compares doubles
bool is_double_equal(double x, double y)
{
        return (fabs(x - y) <= (double)1e-6);
}

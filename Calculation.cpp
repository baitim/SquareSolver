#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "Check_errors.h"
#include "Calculation.h"
#include "Input_output.h"

// the function calculates the roots
void calculation_of_roots(coefs_roots *data)
{
        ASSERT(data && isfinite(data->a) && isfinite(data->b) && isfinite(data->c));

        double a = data->a;
        double b = data->b;
        double c = data->c;

        if (is_double_equal(a, 0)) { // equation is not square a = 0
                calculation_linear(data);
                return;
        }

        double discriminant = b * b - 4 * a * c;
        if (is_double_less(discriminant, 0)) {
                data->count_root = ROOT_0;
                return;
        }

        double discriminant_sqrt = sqrt(discriminant);
        if (is_double_equal(discriminant, 0)) {
                data->root1 = data->root2 = -b / (2 * a);
                data->count_root = ROOT_1_QUAD;
                return;
        }
        if (is_double_greater(discriminant, 0)) {
                data->root1 = (-b - discriminant_sqrt) / (2 * a);
                data->root2 = (-b + discriminant_sqrt) / (2 * a);
                data->count_root = ROOT_2_QUAD;
                return;
        }
        data->count_root = ROOT_ERR;
}

// the function calculates the roots if the equation is linear
void calculation_linear(coefs_roots *data)
{
        ASSERT(data && isfinite(data->b) && isfinite(data->c));

        double b = data->b;
        double c = data->c;

        if (!is_double_equal(b, 0)) {
                data->root1 = data->root2 = -c / b;
                data->count_root = ROOT_1_LINE;
        } else {
                data->count_root = (is_double_equal(c, 0)) ? ROOT_INF : ROOT_0;
        }
}

// the function compares doubles
bool is_double_equal(double x, double y)
{
        return (fabs(x - y) <= EPSILON);
}

bool is_double_greater(double x, double y)
{
        return ((x - y) >= EPSILON);
}

bool is_double_less(double x, double y)
{
        return ((x - y) <= -EPSILON);
}

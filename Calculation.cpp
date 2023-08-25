#include <stdio.h>
#include <math.h>

#include "Check_errors.h"
#include "Calculation.h"
#include "Input_output.h"

// the function calculates the roots
void calculation_of_roots(const coefficients *coefs, roots_struct *roots)
{
        ASSERT(coefs && roots && isfinite(coefs->a) && isfinite(coefs->b) && isfinite(coefs->c));

        double a = coefs->a;
        double b = coefs->b;
        double c = coefs->c;

        if (is_double_equal(a, 0)) { // equation is not square a = 0
                calculation_linear(coefs, roots);
                return;
        }

        double discriminant = b * b - 4 * a * c;
        if (is_double_less(discriminant, 0)) {
                roots->count_root = ROOT_0;
                return;
        }

        double discriminant_sqrt = sqrt(discriminant);
        if (is_double_equal(discriminant, 0)) {
                roots->root1 = roots->root2 = -b / (2 * a);
                roots->count_root = ROOT_1_QUAD;
                return;
        }
        if (is_double_greater(discriminant, 0)) {
                roots->root1 = (-b - discriminant_sqrt) / (2 * a);
                roots->root2 = (-b + discriminant_sqrt) / (2 * a);
                roots->count_root = ROOT_2_QUAD;
                return;
        }
        roots->count_root = ROOT_ERR;
}

// the function calculates the roots if the equation is linear
void calculation_linear(const coefficients *coefs, roots_struct *roots)
{
        ASSERT(coefs && roots && isfinite(coefs->b) && isfinite(coefs->c));

        double b = coefs->b;
        double c = coefs->c;

        if (!is_double_equal(b, 0)) {
                roots->root1 = roots->root2 = -c / b;
                roots->count_root = ROOT_1_LINE;
        } else {
                roots->count_root = (is_double_equal(c, 0)) ? ROOT_INF : ROOT_0;
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

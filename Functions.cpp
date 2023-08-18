#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#include "Header.h"

// the function prints the number of roots and the roots
void print_roots(coefs_roots data, cases_numbers_roots roots)
{
        switch (roots) {
        case ROOT_0: // square || (a = 0 && b = 0 && c != 0)
                printf(LIGHT_YELLOW "Total roots: 0\n" DEFAULT_COLOUR);
                break;
        case ROOT_1_QUAD:
                printf(LIGHT_YELLOW "Total roots: 1\nx = " LIGHT_CYAN "%.2lf\n" DEFAULT_COLOUR, data.root1);
                break;
        case ROOT_2_QUAD:
                printf(LIGHT_YELLOW "Total roots: 2\nx1 = " LIGHT_CYAN "%.2lf  " LIGHT_YELLOW "x2 = " LIGHT_CYAN "%.2lf\n" DEFAULT_COLOUR, data.root1, data.root2);
                break;
        case ROOT_1_LINE:
                printf(LIGHT_YELLOW "The equation is not square, the root = " LIGHT_CYAN "%.2lf\n" DEFAULT_COLOUR, data.root1);
                break;
        case ROOT_INF:
                printf(LIGHT_BLUE "The equation is not square, " LIGHT_RED "infinitely" LIGHT_BLUE " many roots\n" DEFAULT_COLOUR);
                break;
        case ROOT_ERR:
                printf(LIGHT_RED "ERROR\n" DEFAULT_COLOUR);
                assert(0);
                break;
        default:
                assert(0);
                break;
        }
}

// the function reads the coefficients and sends them for verification
bool input_coefficients(coefs_roots *data)
{
        while (true) {
                int count_input = scanf("%lf%lf%lf", &data->a, &data->b, &data->c);
                switch (check_input(count_input)) {
                case USER_CONTINUE:
                        break;
                case USER_CORRECT:
                        return false;
                        break;
                case USER_EXIT:
                        return true;
                        break;
                default:
                        assert(0);
                        break;
                }
        }
}

// the function checks the correctness of the input
USER_CHOICE check_input(int count_input)
{
        bool is_input_empty = false;
        char c = '$';
        while ((c = (char)getchar()) != '\n') {
                if (c != ' ' and c != '\t')
                        is_input_empty = true;
        }

        if (is_input_empty or count_input != 3 or count_input == EOF) {
                printf ("\033[92mincorrect input, input: 0 - to exit, another integer - to continue\n" DEFAULT_COLOUR);
                int x = 1;
                scanf("%d", &x);
                while (getchar() != '\n')
                        ;

                if (x == 0)
                        return USER_EXIT;
                return USER_CONTINUE;
        } else {
                return USER_CORRECT;
        }
}

// the function calculates the roots
cases_numbers_roots calculation_of_roots(coefs_roots *data)
{
        double a_ = data->a, b_ = data->b, c_ = data->c;

        if (is_double_equal(a_, 0)) // equation is not square a = 0
                return calculating_linear(data);

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
cases_numbers_roots calculating_linear(coefs_roots *data)
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
        return (fabs(x - y) <= EPS);
}

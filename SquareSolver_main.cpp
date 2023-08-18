#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#define eps 1e-6

struct coefs {
        double a = 0;
        double b = 0;// coefficients
        double c = 0;
};

enum cases { root_0, root_1_quad, roots_2_quad, root_1_line, root_inf, err };

void print_roots(double x1, double x2, cases roots);

void input_coefficients(coefs *coef);

bool check_input(int count_input);

cases calculation_of_roots(coefs coef, double *x1, double *x2);

bool is_double_equal(double x, double y);

int main (void)
{
        coefs coef;
        printf ("Enter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\n");

        input_coefficients(&coef); // input

        double x1 = 0, x2 = 0; // roots
        cases roots = root_0;
        roots = calculation_of_roots(coef, &x1, &x2);
        print_roots(x1, x2, roots); // answer
        return 0;
}

void print_roots(double x1, double x2, cases roots)
{
        switch (roots) {
        case root_0: // 0 roots, the equation is square or a = 0, b = 0, c != 0
                printf ("Total roots: 0");
                break;
        case root_1_quad: // 1 root, quadratic equation
                printf ("Total roots: 1\nx = %lf\n", x1);
                break;
        case roots_2_quad: // 2 roots, the equation is square
                printf ("Total roots: 2\nx1 = %lf  x2 = %lf\n", x1, x2);
                break;
        case root_1_line: // 1 root, linear equation
                printf ("The equation is not square, the root = %lf\n", x1);
                break;
        case root_inf: // infinitely many roots
                printf ("The equation is not square, infinitely many roots");
                break;
        default:
                printf ("ERROR");
                break;
        }
}

void input_coefficients(coefs *coef)
{
        while (true) {
                int count_input = scanf ("%lf%lf%lf", &coef->a, &coef->b, &coef->c);
                if (check_input(count_input))
                        break;
        }
}

bool check_input(int count_input)
{
        bool rest_of_input = false;
        char c = '$';
        while ((c = (char)getchar()) != '\n')
                if (c != ' ' and c != '\t')
                        rest_of_input = true; // check rest of input

        if (rest_of_input or count_input != 3 or count_input == EOF) {
                printf ("incorrect input, input: 0 - to exit, another integer - to continue\n");
                int x = 1;
                scanf ("%d", &x);
                while (getchar() != '\n')
                        ;
                if (x == 0)
                        exit(0); // exit
                return false; // continue input
        } else
                return true; // correct input

}

cases calculation_of_roots(coefs coef, double *x1, double *x2)
{
        if (is_double_equal(coef.a, 0)) { // equation is not square a = 0
                if (!is_double_equal(coef.b, 0)) { // b = 0
                        *x1 = -coef.c / coef.b;// linear equation  a = 0, x = -c/b
                        return root_1_line;
                } else {                           // b != 0
                        if (is_double_equal(coef.c, 0)) // infinitely many roots a = b = c = 0
                                return root_inf;
                        else
                                return root_0; // 0 roots a = b = 0, c != 0
                }
        }

        double D = coef.b * coef.b - 4 * coef.a * coef.c; // equation is square a != 0
        if (D < 0)
                return root_0; // 0 roots D < 0

        double Dsqrt = sqrt(D); // for optimization
        if (is_double_equal(D, 0)) {
                *x1 = -coef.b / 2 / coef.a;
                return root_1_quad; // 1 root D == 0
        }
        if (D > 0) {
                *x1 = (-coef.b - Dsqrt) / 2 / coef.a;
                *x2 = (-coef.b + Dsqrt) / 2 / coef.a;
                return roots_2_quad; // 2 roots D > 0
        }
        return err; // default
}

bool is_double_equal(double x, double y)
{
        return ((y - x) >= -eps and (x - y) <= eps);
}

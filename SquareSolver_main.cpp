#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#define eps 1e-6

struct coefs {
        double a = 0;
        double b = 0; // coefficients
        double c = 0;
};

enum cases {
        root_0,
        root_1_quad,
        roots_2_quad,
        root_1_line,
        root_inf,
        err
};

void print_roots(double x1, double x2, cases roots);

void input_coefficients(coefs *coef);

bool check_input(int count_input);

cases calculation_of_roots(coefs coef, double *x1, double *x2);

cases linear_equation(coefs coef, double *x1, double *x2);

bool is_double_equal(double x, double y);

int main (void)
{    //     \033[96m ------ \033[0m
        coefs coef;
        printf ("\033[33mEnter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\033[0m\n");

        input_coefficients(&coef); // input

        double x1 = 0, x2 = 0; // roots
        cases roots = root_0;
        roots = calculation_of_roots(coef, &x1, &x2);
        print_roots(x1, x2, roots); // answer
        return 0;
}

// the function prints the number of roots and the roots
void print_roots(double x1, double x2, cases roots)
{
        switch (roots) {
        case root_0: // 0 roots, the equation is square or a = 0, b = 0, c != 0
                printf ("\033[93mTotal roots: 0\033[0m");
                break;
        case root_1_quad: // 1 root, quadratic equation
                printf ("\033[93mTotal roots: 1\nx = \033[96m%.2lf\033[0m\n", x1);
                break;
        case roots_2_quad: // 2 roots, the equation is square
                printf ("\033[93mTotal roots: 2\nx1 = \033[96m%.2lf  \033[93mx2 = \033[96m%.2lf\033[0m\n", x1, x2);
                break;
        case root_1_line: // 1 root, linear equation
                printf ("\033[93mThe equation is not square, the root = \033[96m%.2lf\033[0m\n", x1);
                break;
        case root_inf: // infinitely many roots
                printf ("\033[94mThe equation is not square, \033[91minfinitely \033[94mmany roots\033[0m\n");
                break;
        default:
                printf ("\033[91mERROR\033[0m\n");
                break;
        }
}

// the function reads the coefficients and sends them for verification
void input_coefficients(coefs *coef)
{
        while (true) {
                int count_input = scanf ("%lf%lf%lf", &coef->a, &coef->b, &coef->c);
                if (check_input(count_input))
                        break;
        }
}

// the function checks the correctness of the input
bool check_input(int count_input)
{
        bool rest_of_input = false;
        char c = '$';
        while ((c = (char)getchar()) != '\n')
                if (c != ' ' and c != '\t')
                        rest_of_input = true; // check rest of input

        if (rest_of_input or count_input != 3 or count_input == EOF) {
                printf ("\033[92mincorrect input, input: 0 - to exit, another integer - to continue\033[0m\n");
                int x = 1;
                scanf ("%d", &x);
                while (getchar() != '\n')
                        ;
                if (x == 0)
                        exit(0);
                return false; // continue input
        } else
                return true; // correct input

}

// the function calculates the roots
cases calculation_of_roots(coefs coef, double *x1, double *x2)
{
        if (is_double_equal(coef.a, 0)) // equation is not square a = 0
                return linear_equation(coef, x1, x2);

        double D = coef.b * coef.b - 4 * coef.a * coef.c;
        if (D < 0)
                return root_0;

        double Dsqrt = sqrt(D); // for optimization
        if (is_double_equal(D, 0)) {
                *x1 = -coef.b / 2 / coef.a;
                return root_1_quad;
        }
        if (D > 0) {
                *x1 = (-coef.b - Dsqrt) / 2 / coef.a;
                *x2 = (-coef.b + Dsqrt) / 2 / coef.a;
                return roots_2_quad;
        }
        return err;
}

// the function calculates the roots if the equation is linear
cases linear_equation(coefs coef, double *x1, double *x2)
{
        if (!is_double_equal(coef.b, 0)) {
                *x1 = -coef.c / coef.b;
                return root_1_line;
        } else {
                if (is_double_equal(coef.c, 0))
                        return root_inf;
                else
                        return root_0;
        }
}

// the function compares doubles
bool is_double_equal(double x, double y)
{
        return ((y - x) >= -eps and (x - y) <= eps);
}

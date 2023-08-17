#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#define eps 1e-6

enum cases { root_0, root_1_quad, roots_2_quad, root_1_line, root_inf };

void print_roots(double x1, double x2, cases roots);

void input_coefficients(double* a, double* b, double* c);

bool check_input(int count_input);

cases calculation_of_roots(double a, double b, double c, double* x1, double* x2);

bool is_double_equal(double x, double y);

int main (void) {
    double a = 0, b = 0, c = 0; // coefficients
    printf ("Enter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\n");

    input_coefficients(&a, &b, &c); // input

    double x1 = 0, x2 = 0; // roots
    cases roots;
    roots = calculation_of_roots(a, b, c, &x1, &x2);
    print_roots(x1, x2, roots); // answer
    return 0;
}

void print_roots(double x1, double x2, cases roots) {
    switch (roots) {
        case root_0: // 0 roots, the equation is square or a = 0, b = 0, c != 0
            break;
        case root_1_quad: // 1 root, quadratic equation
            printf ("Total roots: 1\nx = %lf\n", x1);
            break;
        case roots_2_quad: // 2 roots, the equation is square
            printf ("Total roots: 2\nx1 = %lf  x2 = %lf\n", x1, x2);
            break;
        case root_1_line: // 1 root, linear equation
            printf ("The equation is not square, the root = %lf\n", x1);
        case root_inf: // infinitely many roots
            printf ("The equation is not square, infinitely many roots");
    }
}

void input_coefficients(double* a, double* b, double* c) {
    while (true) {
        int count_input = scanf ("%lf%lf%lf", a, b, c);
        bool f = check_input(count_input);
        if (f) break;
    }
}

bool check_input(int count_input) {
    bool rest_of_input = false;
    char c;
    while ((c = getchar()) != '\n')
        if (c != ' ' and c != '\t')
            rest_of_input = true; // check rest of input

    if (rest_of_input or count_input != 3 or count_input == EOF) {
        printf ("incorrect input, input: 0 - to exit, another integer - to continue\n");
        int x;
        while (getchar() != '\n');
        scanf ("%d", &x);
        while (getchar() != '\n');
        if (x == 0) exit(0); // exit
        return false; // continue input
    }
    else
        return true;
}

cases calculation_of_roots(double a, double b, double c, double* x1, double* x2) {
    if (is_double_equal(a, 0)) {
        if (b != 0) { *x1 = -c/b; return root_1_line; }
        if (b == 0) {
            if (c == 0) return root_inf;
            if (c != 0) return root_0;
        }
    }
    double D = b*b - 4*a*c;
    double Dsqrt = sqrt(D);
    if (D < 0) return root_0;
    if (is_double_equal(D, 0)) { *x1 = -b/2/a; return root_1_quad; }
    if (D > 0) { *x1 = (-b-Dsqrt)/2/a; *x2 = (-b+Dsqrt)/2/a; return roots_2_quad; }
}

bool is_double_equal(double x, double y) {
    if (abs(x-y) <= eps) return true;
    else return false;
}

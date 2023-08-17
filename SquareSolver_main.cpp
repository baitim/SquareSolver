#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#define eps 1e-6

void output(double x1, double x2, int roots);

void input_coefficients(double* a, double* b, double* c);

bool is_in_input_flush();

int calculation_of_roots(double a, double b, double c, double* x1, double* x2);

bool is_double_equal(double x, double y);

int main (void) {
    double a = 0, b = 0, c = 0; //coefficients
    printf ("Enter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\n");

    input_coefficients(&a, &b, &c); // input

    double x1 = 0, x2 = 0; // roots
    int roots = calculation_of_roots(a, b, c, &x1, &x2);
    output(x1, x2, roots); // answer
    return 0;
}

void output(double x1, double x2, int roots) {
    if (roots >= 0 and roots <= 2)
        printf ("Total roots: %d\n", roots);
    if (roots == 3)
        printf ("Total roots: 1\n");

    switch (roots) {
        case 0: // 0 roots, the equation is square or a = 0, b = 0, c != 0
            break;
        case 1: // 1 root, quadratic equation
            printf ("x = %lf\n", x1);
            break;
        case 2: // 2 roots, the equation is square
            printf ("x1 = %lf  x2 = %lf\n", x1, x2);
            break;
        case 3: // 1 root, linear equation
            printf ("The equation is not square, the root = %lf\n", x1);
        case 4: // infinitely many roots
            printf ("The equation is not square, infinitely many roots");
    }
}

void input_coefficients(double* a, double* b, double* c) {
    while (true) {
        int count_input = scanf ("%lf%lf%lf", a, b, c);
        if (is_in_input_flush() or count_input != 3 or count_input == EOF) {
            printf ("incorrect input, input: 0 - to exit, another integer - to continue\n");
            int x;
            while (getchar() != '\n');
            scanf ("%d", &x);
            if (x == 0) exit(0);
        }
        else
            break;
    }
}

bool is_in_input_flush() {
    char c;
    while ((c = getchar()) != '\n')
        if (c != ' ' and c != '\t')
            return true;
    return false;
}

int calculation_of_roots(double a, double b, double c, double* x1, double* x2) {
    if (is_double_equal(a, 0)) {
        if (b != 0) { *x1 = -c/b; return 3; }
        if (b == 0) {
            if (c == 0) return 4;
            if (c != 0) return 0;
        }
    }
    double D = b*b - 4*a*c;
    double Dsqrt = sqrt(D);
    if (D < 0) return 0;
    if (is_double_equal(D, 0)) { *x1 = -b/2/a; return 1; }
    if (D > 0) { *x1 = (-b-Dsqrt)/2/a; *x2 = (-b+Dsqrt)/2/a; return 2; }
}

bool is_double_equal(double x, double y) {
    if (abs(x-y) <= eps) return true;
    else return false;
}

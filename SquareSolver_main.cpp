#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#define eps 1e-6

int sol(double a, double b, double c);

int main (void) {
    double a = 0, b = 0, c = 0;
    printf ("Enter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\n");
    while (true) {
        int count_input = scanf ("%lf%lf%lf", &a, &b, &c);
        if (count_input != 3 or count_input == EOF) {
            printf ("incorrect input, input: 0 - to exit, another integer - to continue\n");
            while (getchar() != '\n');
            int x;
            scanf ("%d", &x);
            if (x == 0) return 0;
        }
        else
            break;
    }
    int roots = sol(a, b, c);
    if (roots >= 0)
        printf ("Total roots: %d\n", roots);
    double x = 0, x1 = 0, x2 = 0;
    double D = b*b - 4*a*c, Dsqrt = sqrt(D);
    switch (roots) {
        case 0:
            break;
        case 1:
            x = (-b+Dsqrt)/2/a;
            printf ("x = %lf\n", x);
            break;
        case 2:
            x1 = (-b-Dsqrt)/2/a;
            x2 = (-b+Dsqrt)/2/a;
            printf ("x1 = %lf  x2 = %lf\n", x1, x2);
            break;
        default:
            printf ("The equation is not square, the root = %lf\n", -c/b);
    }
    return 0;
}

int sol(double a, double b, double c) {
    if (a >= -eps and a <= eps) return -1;
    double D = b*b - 4*a*c;
    if (D < 0) return 0;
    if (D >= -eps and D <= eps) return 1;
    if (D > 0) return 2;
}

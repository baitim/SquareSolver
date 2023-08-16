#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include "sol.cpp"
#define eps 1e-7

double D;

int main () {
    double a, b, c;
    printf ("Enter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\n");
    scanf ("%lf%lf%lf", &a, &b, &c);
    int roots = sol(a, b, c);
    printf ("Total roots: %d\n", roots);
    double x, x1, x2;
    switch (roots) {
        case 0:
            break;
        case 1:
            x = (-b+sqrt(D))/2/a;
            printf ("x = %lf", x);
            break;
        case 2:
            x1 = (-b-sqrt(D))/2/a;
            x2 = (-b+sqrt(D))/2/a;
            printf ("x1 = %lf  x2 = %lf", x1, x2);
            break;
    }
    return 0;
}

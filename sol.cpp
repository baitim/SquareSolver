#include <stdio.h>
#include <math.h>
#define eps 1e-6

extern double D; // из main

int sol(double a, double b, double c) {
    D = b*b - 4*a*c;
    if (D < 0) return 0;
    if (D >= -eps and D <= eps) return 1;
    if (D > 0) return 2;
}

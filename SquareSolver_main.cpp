#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>

#include "SquareSolver.h"
#include "SquareSolver.cpp"

int main (void)
{
        coefs coef;
        printf ("\033[33mEnter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\033[0m\n");

        input_coefficients(&coef); // input

        double x1 = 0, x2 = 0; // roots
        cases roots = root_0;
        roots = calculation_of_roots(coef, &x1, &x2);
        print_roots(x1, x2, roots); // answer
        return 0;
}

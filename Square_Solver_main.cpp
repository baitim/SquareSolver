#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>

#include "Header.h"

int main (void)
{
        coefs_roots data = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
        printf(YELLOW "Enter the coefficients for the quadratic equation a*x^2 + b*x + c = 0 separated by a space\n" DEFAULT_COLOUR);

        input_coefficients(&data);

        print_roots(data, calculation_of_roots(&data));
        return 0;
}

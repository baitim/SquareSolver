#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>

#include "Names.h"
#include "Input.cpp"
#include "Calculation.cpp"
#include "Output.cpp"

int main (void)
{
        coefs_roots data = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

        while (input_coefficients_or_exit(&data))
                print_roots(data, calculation_of_roots(&data));

        printf(ANSI_LIGHT_BLUE "Bye\n" ANSI_DEFAULT_COLOUR);

        return 0;
}

#include <TXLib.h>
#include <stdio.h>

#include "Defines_enums_structs_const.h"
#include "Prototypes_functions.h"

void calculate_equation_from_cmd(cmd_input_data cmd_data)
{
        coefs_roots data_start = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };
        data_start.a = cmd_data.a;
        data_start.b = cmd_data.b;
        data_start.c = cmd_data.c;

        if (cmd_data.is_coeffs_input) {
                calculation_of_roots(&data_start);
                printf(ANSI_YELLOW "First data processed:\n" ANSI_DEFAULT_COLOUR);

                printf(ANSI_LIGHT_YELLOW "Coefficients: a = %.6lg, b = %.6lg, c = %.6lg\n"
                       ANSI_DEFAULT_COLOUR, data_start.a, data_start.b, data_start.c);

                print_roots(data_start);
        }
}

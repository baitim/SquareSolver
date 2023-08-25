#include "ANSI_colors.h"
#include "Calculation.h"
#include "Check_errors.h"

#include <stdio.h>

void calculate_equation_from_cmd(cmd_input_data *cmd_data)
{
        ASSERT(cmd_data);

        coefficients coefs = { 0.0f, 0.0f, 0.0f };
        roots_struct roots = { 0.0f, 0.0f, ROOT_ERR };

        coefs.a = cmd_data->a;
        coefs.b = cmd_data->b;
        coefs.c = cmd_data->c;

        if (cmd_data->is_coeffs_input) {
                calculation_of_roots(&coefs, &roots);
                printf(ANSI_YELLOW "First data processed:\n" ANSI_DEFAULT_COLOR);

                printf(ANSI_LIGHT_YELLOW "Coefficients: a = %.6lg, b = %.6lg, c = %.6lg\n"
                       ANSI_DEFAULT_COLOR, coefs.a, coefs.b, coefs.c);

                print_roots(&roots);
        }
}

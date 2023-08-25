#include "ANSI_colors.h"
#include "Calculation.h"
#include "Check_errors.h"
#include "Input_output.h"

#include <stdio.h>

int main (int argc, char *argv[])
{
        printf(ANSI_LIGHT_BLUE "# Square equation solver\n"
                               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOR);


        cmd_input_data cmd_data = { false, false, false, 0.0f, 0.0f, 0.0f, false, nullptr, false };
        input_cmd(argc, argv, &cmd_data);

        if (cmd_data.is_help)
                print_help();

#ifdef TEST_ON
        if (cmd_data.is_test_on)
                test(&cmd_data);
#endif

        if (cmd_data.is_a && cmd_data.is_b && cmd_data.is_c)
                calculate_equation_from_cmd(&cmd_data);

        coefficients coefs = { 0.0f, 0.0f, 0.0f };
        roots_struct roots = { 0.0f, 0.0f, ROOT_ERR };

        while (input_coefficients_or_exit(&coefs)) {
                calculation_of_roots(&coefs, &roots);
                print_roots(&roots);
        }

        printf(ANSI_LIGHT_BLUE "Bye\n" ANSI_DEFAULT_COLOR);

        return 0;
}

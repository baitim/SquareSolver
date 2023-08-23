#include <TXLib.h>
#include <stdio.h>

#include "Names.h"

int main (int argc, char *argv[])
{
        printf(ANSI_LIGHT_BLUE "# Square equation solver\n"
               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOUR);


        cmd_input_data cmd_data = { false, 0.0f, 0.0f, 0.0f, false };
        input_cmd(argc, argv, &cmd_data);

        #ifdef TEST_ON
                if (cmd_data.is_coeffs_input)
                        test(cmd_data);
        #endif

        process_coefs_in_cmd(cmd_data);

        coefs_roots data = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };

        while (input_coefficients_or_exit(&data)) {
                calculation_of_roots(&data);
                print_roots(data);
        }

        printf(ANSI_LIGHT_BLUE "Bye\n" ANSI_DEFAULT_COLOUR);

        return 0;
}

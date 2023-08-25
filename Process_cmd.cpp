#include "Check_errors.h"
#include "Input_output.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_cmd(int argc, char *argv[], cmd_input_data *cmd_data)
{
        ASSERT(argv && cmd_data);

        bool has_a = false;
        bool has_b = false;
        bool has_c = false;

        double a = 0;
        double b = 0;
        double c = 0;

        for (int i = 0; i < argc; i++) {
                if (i < argc - 1) {
                        check_flags_coeffs_cmd(argv[i], argv[i+1], "-a", &a, &has_a);
                        check_flags_coeffs_cmd(argv[i], argv[i+1], "-b", &b, &has_b);
                        check_flags_coeffs_cmd(argv[i], argv[i+1], "-c", &c, &has_c);
                }

                if (strcmp(argv[i], "-test_on") == 0) {
                        cmd_data->is_test_on = true;
                        if (i < argc - 1)
                                cmd_data->name_test_file = argv[i+1];
                }
        }

        if (has_a && has_b && has_c) {
                cmd_data->is_coeffs_input = true;
                cmd_data->a = a;
                cmd_data->b = b;
                cmd_data->c = c;
        }
}

void check_flags_coeffs_cmd(char argv1[], char argv2[], const char *flag_coef, double *x, bool *has_x)
{
        if (strcmp(argv1, flag_coef) == 0) {
                char *stopstring;
                *x = strtod(argv2, &stopstring);
                if (*stopstring == '\0')
                        *has_x = true;
        }
}

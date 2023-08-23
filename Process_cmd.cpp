#include <TXLib.h>
#include <stdio.h>

#include "Defines_enums_structs_const.h"
#include "Prototypes_functions.h"

void input_cmd(int argc, char *argv[], cmd_input_data *cmd_data)
{
        bool has_a = false; double a_ = 0;
        bool has_b = false; double b_ = 0;
        bool has_c = false; double c_ = 0;

        for (int i = 0; i < argc; i++) {
                if ((strcmp(argv[i], "-a") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        a_ = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                break;
                        }
                        has_a = true;
                }
                if ((strcmp(argv[i], "-b") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        b_ = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                break;
                        }
                        has_b = true;
                }
                if ((strcmp(argv[i], "-c") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        c_ = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                break;
                        }
                        has_c = true;
                }
        }

        if (has_a && has_b && has_c) {
                cmd_data->is_coeffs_input = true;
                cmd_data->a = a_;
                cmd_data->b = b_;
                cmd_data->c = c_;
        }

        //-----------------------------------------------------
        for (int i = 0; i < argc; i++) {
                if (strcmp(argv[i], "-test_on") == 0) {
                        cmd_data->is_test_on = true;
                        if (i < argc - 1)
                                cmd_data->name_test_file = argv[i+1];
                }
        }
}

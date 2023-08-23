#include <TXLib.h>
#include <stdio.h>

#include "Names.h"

void input_cmd(int argc, char *argv[], cmd_input_data *cmd_data)
{
        int a = 0; double a_ = 0;
        int b = 0; double b_ = 0;
        int c = 0; double c_ = 0;

        for (int i = 0; i < argc; i++) {
                if ((strcmp(argv[i], "-a") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        a_ = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                break;
                        }
                        a = 1;
                }
                if ((strcmp(argv[i], "-b") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        b_ = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                break;
                        }
                        b = 1;
                }
                if ((strcmp(argv[i], "-c") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        c_ = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                break;
                        }
                        c = 1;
                }
        }

        if (a && b && c) {
                cmd_data->is_coeffs_input = true;
                cmd_data->a = a_;
                cmd_data->b = b_;
                cmd_data->c = c_;
        }

        //-----------------------------------------------------
        for (int i = 0; i < argc-1; i++) {
                if (strcmp(argv[i], "-test_on") == 0) {
                        cmd_data->is_test_on = true;
                        cmd_data->name_test_file = argv[i+1];
                }
        }
}

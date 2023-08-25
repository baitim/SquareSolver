#include "Check_errors.h"
#include "Input_output.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_cmd(int argc, const char *argv[], cmd_input_data *cmd_data)
{
        ASSERT(argv);
        ASSERT(cmd_data);

        for (int i = 0; i < argc; i++) {
                for (int j = 0; j < count_options; j++) {
                        if (strcmp(argv[i], options[j].name) == 0) {
                                (*options[j].callback)(&argv[i], cmd_data);
                                i += options[j].n_args;
                        }

                }
        }
}

void coef_a_callback(const char* argv[], cmd_input_data* data)
{
        char *stopstring;
        data->a = strtod(argv[1], &stopstring);
        if (*stopstring == '\0')
                data->is_a = true;
}

void coef_b_callback(const char* argv[], cmd_input_data* data)
{
        char *stopstring;
        data->b = strtod(argv[1], &stopstring);
        if (*stopstring == '\0')
                data->is_b = true;
}

void coef_c_callback(const char* argv[], cmd_input_data* data)
{
        char *stopstring;
        data->c = strtod(argv[1], &stopstring);
        if (*stopstring == '\0')
                data->is_c = true;
}

void test_on_callback(const char* argv[], cmd_input_data* data)
{
        data->is_test_on = true;
        data->name_test_file = argv[1];
}

void help_callback(const char* /*argv*/[], cmd_input_data* data)
{
        data->is_help = true;
}

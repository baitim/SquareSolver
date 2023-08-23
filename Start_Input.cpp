#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#include "Names.h"

//
void start_input(int argc, char *argv[])
{
        coefs_roots data_start = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };
        if (is_correct_start_input(argc, argv, &data_start)) {
                calculation_of_roots(&data_start);
                printf(ANSI_YELLOW "First data processed:\n" ANSI_DEFAULT_COLOUR);

                printf(ANSI_LIGHT_YELLOW "Coefficients: a = %.6lg, b = %.6lg, c = %.6lg\n"
                       ANSI_DEFAULT_COLOUR, data_start.a, data_start.b, data_start.c);

                print_roots(data_start);
        }
}

// check if "-a" && "-b" && "-c" in input and write them in data_start
bool is_correct_start_input(int argc, char *argv[], coefs_roots *data_start)
{
        int a = 0;
        int b = 0;
        int c = 0;

        for (int i = 0; i < argc; i++) {
                if ((strcmp(argv[i], "-a") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        data_start->a = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                return false;
                        }
                        a = 1;
                }
                if ((strcmp(argv[i], "-b") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        data_start->b = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                return false;
                        }
                        b = 1;
                }
                if ((strcmp(argv[i], "-c") == 0) && (i < argc - 1)) {
                        char *stopstring;
                        data_start->c = strtod(argv[i+1], &stopstring);
                        if (*stopstring != '\0') {
                                return false;
                        }
                        c = 1;
                }
        }

        if (a && b && c)
                return true;
        else
                return false;
}


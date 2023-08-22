#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#include "Names.h"

// the function reads the coefficients and sends them for verification
bool input_coefficients_or_exit(coefs_roots *data)
{
        assert(data != NULL);

        printf(ANSI_YELLOW "Enter e to exit or something else to continue\n" ANSI_DEFAULT_COLOUR);
        char c = '$';
        int count_c = scanf("%c", &c);
        if (is_input_empty() && count_c == 1 && c == 'e')
                return false;

        printf(ANSI_YELLOW "Enter the coefficients for the quadratic"
                           " equation a*x^2 + b*x + c = 0 separated by a space\n" ANSI_DEFAULT_COLOUR);

        while (true) {
                int count_input = scanf("%lf%lf%lf", &data->a, &data->b, &data->c);

                switch (check_input(count_input)) {
                case USER_CONTINUE:
                        break;
                case USER_CORRECT:
                        printf(ANSI_LIGHT_GREEN "Correct input\n" ANSI_DEFAULT_COLOUR);
                        return true;
                        break;
                case USER_EXIT:
                        return false;
                        break;
                default:
                        assert(0);
                        break;
                }
        }
}

// the function checks the correctness of the input
user_choice check_input(int count_input)
{
        if (!is_input_empty() or count_input != 3 or count_input == EOF) {
                int x = -1;
                while (true) {
                        printf (ANSI_LIGHT_RED "Incorrect input, input: "
                                                 "0 - to exit, 1 - to continue\n" ANSI_DEFAULT_COLOUR);
                        int count_x = scanf("%d", &x);

                        if (is_input_empty() && count_x == 1 && (x == 1 or x == 0)) {
                            break;
                        }
                }
                if (x == 0)
                        return USER_EXIT;
                return USER_CONTINUE;
        } else {
                return USER_CORRECT;
        }
}

bool is_input_empty()
{
        bool is_empty_ = true;
        char c = '$';
        while ((c = (char)getchar()) != '\n') {
                if (c != ' ' && c != '\t')
                        is_empty_ = false;
        }
        return is_empty_;
}

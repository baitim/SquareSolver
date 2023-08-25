#include "ANSI_colors.h"
#include "Check_errors.h"
#include "Input_output.h"

#include <stdio.h>
#include <ctype.h>

bool input_coefficients_or_exit(coefficients *coefs)
{
        ASSERT(coefs);

        printf(ANSI_YELLOW "Enter e to exit or something else to continue\n" ANSI_DEFAULT_COLOR);
        char c = '$';
        int count_c = scanf("%c", &c);
        if (is_input_empty() && count_c == 1 && c == 'e')
                return false;

        printf(ANSI_YELLOW "Enter the coefficients for the quadratic"
                           " equation a*x^2 + b*x + c = 0 separated by a space or enter\n" ANSI_DEFAULT_COLOR);

        while (true) {
                int count_input = scanf("%lg %lg %lg", &coefs->a, &coefs->b, &coefs->c);

                switch (check_input(count_input)) {
                case USER_CONTINUE:
                        break;
                case USER_CORRECT:
                        printf(ANSI_LIGHT_GREEN "Correct input\n" ANSI_DEFAULT_COLOR);
                        return true;
                        break; //?
                case USER_EXIT:
                        return false;
                        break;
                default:
                        ASSERT(0);
                        break;
                }
        }
}

user_choice check_input(int count_input)
{
        if (!is_input_empty() || count_input != 3 || count_input == EOF) {
                int x = -1;
                int count_x = 0;
                do {
                        printf (ANSI_LIGHT_RED "Incorrect input, input: "
                                               "0 - to exit, 1 - to continue\n" ANSI_DEFAULT_COLOR);
                        count_x = scanf("%d", &x);
                }
                while (!is_input_empty() || !(count_x == 1) || !(x == 1 || x == 0));

                if (x == 0)
                        return USER_EXIT;
                return USER_CONTINUE;
        } else {
                return USER_CORRECT;
        }
}

bool is_input_empty()
{
        bool is_empty = true;
        int c = 0;
        while ((c = getchar()) != '\n') {
                if (!isspace(c))
                        is_empty = false;
        }
        return is_empty;
}

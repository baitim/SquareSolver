#include "ANSI_colors.h"
#include "Check_errors.h"
#include "Input_output.h"

#include <stdio.h>

void print_help()
{
        for (int i = 0; i < count_options; i++)
                printf(ANSI_LIGHT_GREEN "%s\t\t%s\n" ANSI_DEFAULT_COLOR, options[i].name, options[i].description);
}

void print_roots(const roots_struct *roots)
{
        ASSERT(roots);

        number_roots roots_ = roots->count_root;
        switch (roots_) {
        case ROOT_0:
                printf(ANSI_LIGHT_YELLOW "Total roots: 0\n" ANSI_DEFAULT_COLOR);
                break;
        case ROOT_1_QUAD:
                printf(ANSI_LIGHT_YELLOW "Total roots: 1\nx = " ANSI_LIGHT_CYAN
                                         "%.*lg\n" ANSI_DEFAULT_COLOR, PRECISION, roots->root1);
                break;
        case ROOT_2_QUAD:
                printf(ANSI_LIGHT_YELLOW "Total roots: 2\nx1 = " ANSI_LIGHT_CYAN
                                         "%.*lg  " ANSI_LIGHT_YELLOW "x2 = " ANSI_LIGHT_CYAN
                                         "%.*lg\n" ANSI_DEFAULT_COLOR, PRECISION, roots->root1,
                                         PRECISION, roots->root2);
                break;
        case ROOT_1_LINE:
                printf(ANSI_LIGHT_YELLOW "The equation is not square, the root = " ANSI_LIGHT_CYAN
                                         "%.*lg\n" ANSI_DEFAULT_COLOR, PRECISION, roots->root1);
                break;
        case ROOT_INF:
                printf(ANSI_LIGHT_YELLOW "The equation is not square, " ANSI_LIGHT_RED
                                         "infinitely" ANSI_LIGHT_YELLOW
                                         " many roots\n" ANSI_DEFAULT_COLOR);
                break;
        case ROOT_ERR:
                printf(ANSI_LIGHT_RED "ERROR\n" ANSI_DEFAULT_COLOR);
                ASSERT(0);
        default:
                ASSERT(0);
        }
}

#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#include "Names.h"

// the function prints the number of roots and the roots
void print_roots(coefs_roots data, cases_numbers_roots roots)
{
        switch (roots) {
        case ROOT_0:
                printf(ANSI_LIGHT_YELLOW "Total roots: 0\n" ANSI_DEFAULT_COLOUR);
                break;
        case ROOT_1_QUAD:
                printf(ANSI_LIGHT_YELLOW "Total roots: 1\nx = " ANSI_LIGHT_CYAN "%.2lf\n" ANSI_DEFAULT_COLOUR, data.root1);
                break;
        case ROOT_2_QUAD:
                printf(ANSI_LIGHT_YELLOW "Total roots: 2\nx1 = " ANSI_LIGHT_CYAN "%.2lf  " ANSI_LIGHT_YELLOW "x2 = " ANSI_LIGHT_CYAN "%.2lf\n" ANSI_DEFAULT_COLOUR, data.root1, data.root2);
                break;
        case ROOT_1_LINE:
                printf(ANSI_LIGHT_YELLOW "The equation is not square, the root = " ANSI_LIGHT_CYAN "%.2lf\n" ANSI_DEFAULT_COLOUR, data.root1);
                break;
        case ROOT_INF:
                printf(ANSI_LIGHT_YELLOW "The equation is not square, " ANSI_LIGHT_RED "infinitely" ANSI_LIGHT_YELLOW " many roots\n" ANSI_DEFAULT_COLOUR);
                break;
        case ROOT_ERR:
                printf(ANSI_LIGHT_RED "ERROR\n" ANSI_DEFAULT_COLOUR);
                assert(0);
                break;
        default:
                assert(0);
                break;
        }
}

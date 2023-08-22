#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>

#include "Names.h"

int main (int argc, char *argv[])
{
        printf(ANSI_LIGHT_BLUE "# Square equation solver\n"
               "# (c) BAIDIUSENOV TIMUR, 2023\n\n" ANSI_DEFAULT_COLOUR);

#ifdef TEST_ON
        if (is_test_on(argc, argv))
                test();
#endif

        coefs_roots data = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };

        while (input_coefficients_or_exit(&data)) {
                calculation_of_roots(&data);
                print_roots(data);
        }

        printf(ANSI_LIGHT_BLUE "Bye\n" ANSI_DEFAULT_COLOUR);

        return 0;
}

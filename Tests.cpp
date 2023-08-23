#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

#include "Names.h"

#ifdef TEST_ON

// check if "-test_on" in input
bool is_test_on(int argc, char *argv[])
{
        for (int i = 0; i < argc; i++) {
                if (strcmp(argv[i], "-test_on") == 0)
                        return true;
        }
        return false;
}

// the function tests calculation
void test()
{
        char name_file[] = "Tests.txt";
        FILE *fp;
        if ((fp = fopen(name_file, "r")) == NULL)
        {
                printf(ANSI_LIGHT_RED "Empty file of tests\n" ANSI_DEFAULT_COLOUR);
                return;
        }

        while (true) {
                double a;
                double b;
                double c;
                double root1;
                double root2;
                int cases_of_roots;
                int count_input = fscanf(fp, "%lf %lf %lf %lf %lf %d", &a, &b, &c, &root1, &root2, &cases_of_roots);
                if (count_input != 6)
                        break;
                check_test(a, b, c, root1, root2, cases_of_roots);
        }

        fclose(fp);
        printf(ANSI_LIGHT_GREEN "ALL TESTS ACCEPTED\n\n" ANSI_DEFAULT_COLOUR);
}

// the function compares calculation and input
void check_test(double a_, double b_, double c_, double root1_, double root2_, int roots)
{
        coefs_roots data_ = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };

        data_.a = a_;
        data_.b = b_;
        data_.c = c_;

        calculation_of_roots(&data_);

        assert(is_double_equal(data_.root1, root1_) && is_double_equal(data_.root2, root2_) && (data_.count_root == roots));
}

#endif

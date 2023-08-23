#include <TXLib.h>
#include <stdio.h>

#include "Names.h"

#ifdef TEST_ON

// check if "-test_on" in input
int is_test_on(int argc, char *argv[])
{
        for (int i = 0; i < argc-1; i++) {
                if (strcmp(argv[i], "-test_on") == 0)
                        return (i+1);
        }
        return -1;
}

// the function tests calculation
void test(int number_name_file, char *argv[])
{
        FILE *fp;
        if ((fp = fopen(argv[number_name_file], "r")) == NULL)
        {
                printf(ANSI_LIGHT_RED "Empty file of tests\n" ANSI_DEFAULT_COLOUR);
                return;
        }

        int is_OK = 1;

        while (true) {
                double a;
                double b;
                double c;
                double root1;
                double root2;
                int cases_of_roots;
                int count_input = fscanf(fp, "%lg %lg %lg %lg %lg %d", &a, &b, &c, &root1, &root2, &cases_of_roots);
                if (count_input != 6)
                        break;
                is_OK = min(is_OK, check_test(a, b, c, root1, root2, cases_of_roots));
        }

        if (!is_OK)
                return;

        fclose(fp);
        printf(ANSI_LIGHT_GREEN "ALL TESTS ACCEPTED\n\n" ANSI_DEFAULT_COLOUR);
}

// the function compares calculation and input
int check_test(double a_, double b_, double c_, double root1_, double root2_, int roots)
{
        coefs_roots data_ = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };

        data_.a = a_;
        data_.b = b_;
        data_.c = c_;

        calculation_of_roots(&data_);

        if (!is_double_equal(data_.root1, root1_) || !is_double_equal(data_.root2, root2_) || !(data_.count_root == roots)) {
                printf(ANSI_LIGHT_RED "Failed: x1 = %lg, x2 = %lg, roots = %d; expected:"
                                      "x1ref = %lg, x2ref = %lg, roots_ref = %d\n\n" ANSI_DEFAULT_COLOUR,
                                      data_.root1, data_.root2, data_.count_root, root1_, root2_, roots);
                return 0;
        }
        return 1;
}

#endif

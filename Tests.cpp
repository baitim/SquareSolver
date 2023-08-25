#include <stdio.h>
#include <math.h>

#include "ANSI_colours.h"
#include "Check_errors.h"
#include "Calculation.h"
#include "Input_output.h"

#ifdef TEST_ON

void test(cmd_input_data *cmd_data)
{
        FILE *fp = nullptr;
        if ((fp = fopen(cmd_data->name_test_file, "r")) == NULL)
        {
                printf(ANSI_LIGHT_RED "Test file read error\n\n" ANSI_DEFAULT_COLOR);
                return;
        }

        int is_OK = 1;

        while (true) {
                coefficients coefs = { 0.0f, 0.0f, 0.0f };
                roots_struct roots = { 0.0f, 0.0f, ROOT_ERR };

                int count_root_ = 0;
                int count_input = fscanf(fp, "%lg %lg %lg %lg %lg %d", &coefs.a,
                                         &coefs.b, &coefs.c, &roots.root1,
                                         &roots.root2, &count_root_);
                ASSERT((count_root_ >= 0) && (count_root_ <= 4));
                roots.count_root = (number_roots)count_root_;

                if (count_input > nTests)
                        break;
                is_OK = (is_OK > check_test(&coefs, &roots)) ? check_test(&coefs, &roots) : is_OK;
        }

        if (!is_OK)
                return;

        fclose(fp);
        printf(ANSI_LIGHT_GREEN "ALL TESTS ACCEPTED\n\n" ANSI_DEFAULT_COLOR);
}

int check_test(coefficients *coefs_t, roots_struct *roots_t)
{
        coefficients coefs = { 0.0f, 0.0f, 0.0f };
        roots_struct roots = { 0.0f, 0.0f, ROOT_ERR };

        coefs.a = coefs_t->a;
        coefs.b = coefs_t->b;
        coefs.c = coefs_t->c;

        calculation_of_roots(&coefs, &roots);

        double x1_ref = roots_t->root1;
        double x2_ref = roots_t->root2;
        number_roots nRoots_ref = roots_t->count_root;

        double x1 = roots.root1;
        double x2 = roots.root2;
        number_roots nRoots = roots.count_root;

        if ((!(is_double_equal(x1_ref, x2) && is_double_equal(x2_ref, x1)) &&
               !(is_double_equal(x1_ref, x1) && is_double_equal(x2_ref, x2)))
                 || !(nRoots_ref == nRoots)) {
                printf(ANSI_LIGHT_RED "Failed: x1 = %lg, x2 = %lg, roots = %d; expected:"
                                      "x1ref = %lg, x2ref = %lg, roots_ref = %d\n\n" ANSI_DEFAULT_COLOR,
                                      roots.root1, roots.root2, roots.count_root, roots_t->root1,
                                      roots_t->root2, roots_t->count_root);
                return 0;
        }
        return 1;
}

#endif

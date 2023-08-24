#include <TXLib.h>
#include <stdio.h>

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
                coefs_roots test_data = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };

                int count_root_ = 0;
                int count_input = fscanf(fp, "%lg %lg %lg %lg %lg %d", &test_data.a,
                                         &test_data.b, &test_data.c, &test_data.root1,
                                         &test_data.root2, &count_root_);
                ASSERT((count_root_ >= 0) && (count_root_ <= 4));
                test_data.count_root = (number_roots)count_root_;

                if (count_input > nTests)
                        break;
                is_OK = min(is_OK, check_test(&test_data));
        }

        if (!is_OK)
                return;

        fclose(fp);
        printf(ANSI_LIGHT_GREEN "ALL TESTS ACCEPTED\n\n" ANSI_DEFAULT_COLOR);
}

int check_test(coefs_roots *test_data)
{
        coefs_roots data = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ROOT_ERR };

        data.a = test_data->a;
        data.b = test_data->b;
        data.c = test_data->c;

        calculation_of_roots(&data);

        double x1_ref = test_data->root1;
        double x2_ref = test_data->root2;
        number_roots nRoots_ref = test_data->count_root;

        double x1 = data.root1;
        double x2 = data.root2;
        number_roots nRoots = data.count_root;

        if ((!(is_double_equal(x1_ref, x2) && is_double_equal(x2_ref, x1)) &&
               !(is_double_equal(x1_ref, x1) && is_double_equal(x2_ref, x2)))
                 || !(nRoots_ref == nRoots)) {
                printf(ANSI_LIGHT_RED "Failed: x1 = %lg, x2 = %lg, roots = %d; expected:"
                                      "x1ref = %lg, x2ref = %lg, roots_ref = %d\n\n" ANSI_DEFAULT_COLOR,
                                      data.root1, data.root2, data.count_root, test_data->root1,
                                      test_data->root2, test_data->count_root);
                return 0;
        }
        return 1;
}

#endif

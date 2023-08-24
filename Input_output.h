#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

enum number_roots {
        ROOT_0,
        ROOT_1_QUAD,
        ROOT_2_QUAD,
        ROOT_1_LINE,
        ROOT_INF,
        ROOT_ERR
};

struct coefs_roots {
        double a, b, c;
        double root1, root2;
        number_roots count_root;
};

struct cmd_input_data {
        bool is_coeffs_input;
        double a, b, c;
        bool is_test_on;
        char *name_test_file;
};

enum user_choice {
        USER_CONTINUE,
        USER_CORRECT,
        USER_EXIT
};

void print_roots(coefs_roots data);

void input_cmd(int argc, char *argv[], cmd_input_data *cmd_data);

bool input_coefficients_or_exit(coefs_roots *data);

user_choice check_input(int count_input);

bool is_input_empty();

#endif // INPUT_OUTPUT_H

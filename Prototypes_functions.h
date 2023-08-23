#ifndef Prototypes_functions
#define Prototypes_functions

void input_cmd(int argc, char *argv[], cmd_input_data *cmd_data);

void calculate_equation_from_cmd(cmd_input_data cmd_data);

void test(cmd_input_data cmd_data);

int check_test(double a_, double b_, double c_, double root1_, double root2_, int roots);

void print_roots(coefs_roots data);

bool input_coefficients_or_exit(coefs_roots *data);

bool is_input_empty();

user_choice check_input(int count_input);

void calculation_of_roots(coefs_roots *data);

void calculation_linear(coefs_roots *data);

bool is_double_equal(double x, double y);

bool is_double_qreater(double x, double y);

bool is_double_less(double x, double y);

#endif

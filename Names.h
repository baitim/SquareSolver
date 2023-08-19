#ifndef solver1
#define solver1

#define ANSI_DEFAULT_COLOUR  "\033[0m"
#define ANSI_YELLOW          "\033[33m"
#define ANSI_LIGHT_RED       "\033[91m"
#define ANSI_LIGHT_GREEN     "\033[92m"
#define ANSI_LIGHT_YELLOW    "\033[93m"
#define ANSI_LIGHT_BLUE      "\033[94m"
#define ANSI_LIGHT_CYAN      "\033[96m"

struct coefs_roots {
        double a, b, c;
        double root1, root2;
};

enum cases_numbers_roots {
        ROOT_0,
        ROOT_1_QUAD,
        ROOT_2_QUAD,
        ROOT_1_LINE,
        ROOT_INF,
        ROOT_ERR
};

enum user_choice {
        USER_CONTINUE,
        USER_CORRECT,
        USER_EXIT
};

void print_roots(coefs_roots data, cases_numbers_roots roots);

bool input_coefficients_or_exit(coefs_roots *data);

bool is_input_empty();

user_choice check_input(int count_input);

cases_numbers_roots calculation_of_roots(coefs_roots *data);

cases_numbers_roots calculation_linear(coefs_roots *data);

bool is_double_equal(double x, double y);

#endif
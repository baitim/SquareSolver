#ifndef solver1
#define solver1

#define DEFAULT_COLOUR  "\033[0m"
#define YELLOW          "\033[33m"
#define LIGHT_RED       "\033[91m"
#define LIGHT_GREEN     "\033[92m"
#define LIGHT_YELLOW    "\033[93m"
#define LIGHT_BLUE      "\033[94m"
#define LIGHT_CYAN      "\033[96m"

#define EPS 1e-6

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

enum USER_CHOICE {
        USER_CONTINUE,
        USER_CORRECT,
        USER_EXIT
};

void print_roots(coefs_roots data, cases_numbers_roots roots);

bool input_coefficients(coefs_roots *data);

USER_CHOICE check_input(int count_input);

cases_numbers_roots calculation_of_roots(coefs_roots *data);

cases_numbers_roots calculating_linear(coefs_roots *data);

bool is_double_equal(double x, double y);

#endif

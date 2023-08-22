#ifndef solver1
#define solver1

#define ANSI_DEFAULT_COLOUR  "\033[0m"
#define ANSI_YELLOW          "\033[33m"
#define ANSI_LIGHT_RED       "\033[91m"
#define ANSI_LIGHT_GREEN     "\033[92m"
#define ANSI_LIGHT_YELLOW    "\033[93m"
#define ANSI_LIGHT_BLUE      "\033[94m"
#define ANSI_LIGHT_CYAN      "\033[96m"

#define TEST_ON

const double EPSILON = 1e-7;

enum number_roots {
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

struct coefs_roots {
        double a, b, c;
        double root1, root2;
        number_roots count_root;
};

void start_input(int argc, char *argv[]);

bool is_correct_start_input(int argc, char *argv[], coefs_roots *data_start);

bool is_test_on(int argc, char *argv[]);

void check_test(double a_, double b_, double c_, double root1_, double root2_, number_roots roots);

void test();

void print_roots(coefs_roots data);

bool input_coefficients_or_exit(coefs_roots *data);

bool is_input_empty();

user_choice check_input(int count_input);

void calculation_of_roots(coefs_roots *data);

void calculation_linear(coefs_roots *data);

bool is_double_equal(double x, double y);

#endif
//

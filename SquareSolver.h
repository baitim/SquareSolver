#ifndef solver1
#define solver1

#define eps 1e-6

struct coefs {
        double a = 0;
        double b = 0; // coefficients
        double c = 0;
};

enum cases {
        root_0,
        root_1_quad,
        roots_2_quad,
        root_1_line,
        root_inf,
        err
};

void print_roots(double x1, double x2, cases roots);

void input_coefficients(coefs *coef);

bool check_input(int count_input);

cases calculation_of_roots(coefs coef, double *x1, double *x2);

cases linear_equation(coefs coef, double *x1, double *x2);

bool is_double_equal(double x, double y);

#endif

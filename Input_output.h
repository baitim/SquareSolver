#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

const int PRECISION = 6;

/// Root number cases.
enum number_roots {
        ROOT_0, ///< 0 roots
        ROOT_1_QUAD, ///< 1 root, equation quadratic
        ROOT_2_QUAD, ///< 2 roots, equation quadratic
        ROOT_1_LINE, ///< 1 root, equation linear
        ROOT_INF, ///< infinite number of roots
        ROOT_ERR ///< error, will assert(0)
};

/*!
@struct roots_struct
@brief Structure has coefficients.
*/
struct coefficients {
        double a; ///< coefficient a
        double b; ///< coefficient b
        double c; ///< coefficient c
};

/*!
@struct roots_struct
@brief Structure has roots and number of them.
*/
struct roots_struct {
        double root1; ///< first root
        double root2; ///< second root
        number_roots count_root; ///< number roots cases
};

struct cmd_input_data {
        bool is_coeffs_input;
        double a, b, c;
        bool is_test_on;
        char *name_test_file;
};

/// User choice, user can continue, get answer or exit.
enum user_choice {
        USER_CONTINUE, ///< if input coefficients was incorrect. user continue input them
        USER_CORRECT, ///< if input was correct will run calculate roots
        USER_EXIT ///< user want to exit
};

/*!
@brief Function prints the number of roots and the roots.
@param[in] data struct, include coefs and roots
@details Function has 5 type of print:\n
1 - 0 roots\n
2 - 1 root (equation is quadratic)\n
3 - 2 roots (equation is quadratic)\n
4 - 1 root (equation is linear)\n
5 - infinity number of roots\n
*/
void print_roots(const roots_struct *roots);

/*!
@brief Function reads all data from cmd.
@param[in] argc count of strings from cmd
@param[in] argv strings from cmd
@param[out] cmd_data struct of data from cmd
@details Function can read 4 flags:\n
 -test_on\n
 -a\n
 -b\n
 -c\n
*/
void input_cmd(int argc, char *argv[], cmd_input_data *cmd_data);

void check_flags_coeffs_cmd(char argv1[], char argv2[], const char *flag_coef, double *x, bool *has_x);

/*!
@brief Function reads coefficients.
@param[in] data struct, include coefs and roots
@details Function continue reads input if user inputs mistake and offers exit.
*/
bool input_coefficients_or_exit(coefficients *coefs);

/*!
@brief Function checks for correct input.
@param[in] count_input count of correct coefficients
@details Function continue reads input if user inputs mistake, user exit or user continue input coefficients.
*/
user_choice check_input(int count_input);

/*!
@brief Function checks for empty input.
@details Function return true if input empty.
*/
bool is_input_empty();

#endif // INPUT_OUTPUT_H

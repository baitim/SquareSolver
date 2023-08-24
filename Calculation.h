#ifndef CALCULATION_H
#define CALCULATION_H

#include "Input_output.h"

const double EPSILON = 1e-7;

/*!
@brief Function calculate roots using data from cmd.
@param[in] cmd_data struct of data from cmd
@details Function also print roots and number of them.
*/
void calculate_equation_from_cmd(cmd_input_data *cmd_data);

/*!
@brief Function calculate roots if equation is quadratic.
@param[in] data struct, include coefs and roots
@param[out] data struct, include coefs and roots
@details Function change root1, root2 and number_of_roots.
*/
void calculation_of_roots(const coefficients *coefs, roots_struct *roots);

/*!
@brief Function calculate roots if equation is linear.
@param[in] data struct, include coefs and roots
@param[out] data struct, include coefs and roots
@details Function change root1, root2 and number_of_roots.
*/
void calculation_linear(const coefficients *coefs, roots_struct *roots);

/*!
@brief Function compare doubles.
@param[in] x first double
@param[in] y second double
@details if double is equal function return true else return false.
*/
bool is_double_equal(double x, double y);

/*!
@brief Function compare doubles.
@param[in] x first double
@param[in] y second double
@details if first double greater function return true else return false.
*/
bool is_double_greater(double x, double y);

/*!
@brief Function compare doubles.
@param[in] x first double
@param[in] y second double
@details if first double less function return true else return false.
*/
bool is_double_less(double x, double y);

#endif // CALCULATION_H

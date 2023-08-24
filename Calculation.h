#ifndef CALCULATION_H
#define CALCULATION_H

#include "Input_output.h"

const double EPSILON = 1e-7;

void calculate_equation_from_cmd(cmd_input_data *cmd_data);

void calculation_of_roots(coefs_roots *data);

void calculation_linear(coefs_roots *data);

bool is_double_equal(double x, double y);

bool is_double_greater(double x, double y);

bool is_double_less(double x, double y);

#endif // CALCULATION_H

#ifndef S21_DECIMAL_SUITES
#define S21_DECIMAL_SUITES

#include <check.h>

#include "../matrix.h"

Suite *calc_complements_suite();
Suite *create_matrix_suite();
Suite *determinant_suite();
Suite *eq_matrix_suite();
Suite *inverse_matrix_suite();
Suite *mult_matrix_suite();
Suite *mult_number_suite();
Suite *remove_matrix_suite();
Suite *sub_matrix_suite();
Suite *sum_matrix_suite();
Suite *transpose_suite();

#endif
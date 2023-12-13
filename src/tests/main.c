#include "s21_matrix_suites.h"
#include <stdio.h>

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  // failed = srunner_ntests_failed(sr);
  srunner_free(sr);
}

void run_tests() {
  Suite *test_cases[] = {
    s21_calc_complements_suite(), s21_create_matrix_suite(), s21_determinant_suite(),
    s21_eq_matrix_suite(), s21_inverse_matrix_suite(), s21_mult_matrix_suite(),
    s21_mult_number_suite(), s21_remove_matrix_suite(), s21_sub_matrix_suite(), 
    s21_sum_matrix_suite(), s21_transpose_suite(),
        NULL};
  for (Suite **current_testcase = test_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

int main() {
  run_tests();
}
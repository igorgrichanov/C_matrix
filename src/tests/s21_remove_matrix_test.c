#include "s21_matrix_suites.h"

START_TEST(remove_matrix_test_1) {
  matrix_t *A = NULL;
  s21_remove_matrix(A);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(remove_matrix_test_2) {
  matrix_t A = {NULL, 1, 1};
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(remove_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  int flag = 0;
  if (A.matrix != NULL) flag = 1;
  ck_assert_int_eq(flag, 0);
}
END_TEST

Suite *s21_remove_matrix_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_remove_matrix");
  tc = tcase_create("s21_remove_matrix_case");
  
  tcase_add_test(tc, remove_matrix_test_1);
  tcase_add_test(tc, remove_matrix_test_2);
  tcase_add_test(tc, remove_matrix_test_3);

  suite_add_tcase(s, tc);

  return s;
}
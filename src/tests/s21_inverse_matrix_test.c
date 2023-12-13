#include "s21_matrix_suites.h"

START_TEST(inverse_matrix_test_1) {
  int x = 1;
  ck_assert_int_eq(s21_div(x), div(x));
}
END_TEST

Suite *s21_inverse_matrix_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_inverse_matrix");
  tc = tcase_create("s21_inverse_matrix_case");
  
  tcase_add_test(tc, inverse_matrix_test_1);

  suite_add_tcase(s, tc);

  return s;
}
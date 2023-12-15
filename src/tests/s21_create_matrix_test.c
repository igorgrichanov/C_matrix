#include "s21_matrix_suites.h"

START_TEST(create_matrix_test_1) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(0, 4, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(result.columns, 0);
}
END_TEST

START_TEST(create_matrix_test_2) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(4, 0, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(result.rows, 0);
}
END_TEST

START_TEST(create_matrix_test_3) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(0, 0, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(result.rows, 0);
}
END_TEST

START_TEST(create_matrix_test_4) {
  matrix_t *result = NULL;
  ck_assert_int_eq(s21_create_matrix(5, 5, result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_test_5) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(1, 1, &result), OK);
  ck_assert_int_eq(result.rows, 1);
  ck_assert_int_eq(result.columns, 1);
  ck_assert_double_eq(0.0, result.matrix[0][0]);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_test_6) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(2, 1, &result), OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 1);
  ck_assert_double_eq(0.0, result.matrix[1][0]);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_test_7) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(20, 30, &result), OK);
  ck_assert_int_eq(result.rows, 20);
  ck_assert_int_eq(result.columns, 30);
  ck_assert_double_eq(0.0, result.matrix[18][29]);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_test_8) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(-1, 0, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(result.rows, 0);
}
END_TEST

START_TEST(create_matrix_test_9) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(-1, -1, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(result.rows, 0);
}
END_TEST

START_TEST(create_matrix_test_10) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(5, -1, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(result.rows, 0);
}
END_TEST

START_TEST(create_matrix_test_11) {
  matrix_t result;
  ck_assert_int_eq(s21_create_matrix(5, 5, &result), OK);
  ck_assert_int_eq(result.rows, 5);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_test_12) {
  matrix_t result;
  ck_assert_int_eq(s21_create_matrix(5, 0, &result), INCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_create_matrix");
  tc = tcase_create("s21_create_matrix_case");
  
  tcase_add_test(tc, create_matrix_test_1);
  tcase_add_test(tc, create_matrix_test_2);
  tcase_add_test(tc, create_matrix_test_3);
  tcase_add_test(tc, create_matrix_test_4);
  tcase_add_test(tc, create_matrix_test_5);
  tcase_add_test(tc, create_matrix_test_6);
  tcase_add_test(tc, create_matrix_test_7);
  tcase_add_test(tc, create_matrix_test_8);
  tcase_add_test(tc, create_matrix_test_9);
  tcase_add_test(tc, create_matrix_test_10);
  tcase_add_test(tc, create_matrix_test_11);
  tcase_add_test(tc, create_matrix_test_12);

  suite_add_tcase(s, tc);

  return s;
}
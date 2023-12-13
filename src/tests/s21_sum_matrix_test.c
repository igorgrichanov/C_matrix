#include "s21_matrix_suites.h"

START_TEST(sum_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int err = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(sum_matrix_test_2) {
  matrix_t A = {NULL, 3, 3};
  matrix_t B = {NULL, 3, 3};
  matrix_t result = {NULL, 0, 0};
  int err = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(sum_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  matrix_t result = {NULL, 0, 0};
  int err = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(OK, err);
  ck_assert_int_eq(result.rows, A.rows);
  err = s21_eq_matrix(&A, &result);
  ck_assert_int_eq(SUCCESS, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[0][0] = -1.0;
  B.matrix[0][0] = 2.0;
  matrix_t result = {NULL, 0, 0};
  int err = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(OK, err);
  ck_assert_float_eq(result.matrix[0][0], 1.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST


START_TEST(sum_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -1.0;
  B.matrix[0][0] = 2.0;
  matrix_t result = {NULL, 0, 0};
  int err = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(CALC_ERROR, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  matrix_t result = {NULL, 0, 0};
  matrix_t correct_res = {NULL, 0, 0};
  s21_create_matrix(2, 3, &correct_res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = 2 * i - 3 * j;
      correct_res.matrix[i][j] = 3 * i - 2 * j;
    }
  }
  int err = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&result, &correct_res);
  ck_assert_int_eq(SUCCESS, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(sum_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  matrix_t *result = NULL;
  int err = s21_sum_matrix(&A, &B, result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

Suite *s21_sum_matrix_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sum_matrix");
  tc = tcase_create("s21_sum_matrix_case");
  
  tcase_add_test(tc, sum_matrix_test_1);
  tcase_add_test(tc, sum_matrix_test_2);
  tcase_add_test(tc, sum_matrix_test_3);
  tcase_add_test(tc, sum_matrix_test_4);
  tcase_add_test(tc, sum_matrix_test_5);
  tcase_add_test(tc, sum_matrix_test_6);
  tcase_add_test(tc, sum_matrix_test_7);

  suite_add_tcase(s, tc);

  return s;
}
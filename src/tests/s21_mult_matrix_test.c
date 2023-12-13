#include "s21_matrix_suites.h"

START_TEST(mult_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int err = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(mult_matrix_test_2) {
  matrix_t A = {NULL, 3, 3};
  matrix_t B = {NULL, 3, 3};
  matrix_t result = {NULL, 0, 0};
  int err = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(mult_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  matrix_t result = {NULL, 0, 0};
  int err = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(CALC_ERROR, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 4, &B);
  matrix_t result = {NULL, 0, 0};
  matrix_t correct_res = {NULL, 0, 0};
  s21_create_matrix(2, 4, &correct_res);
  int err = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(OK, err);
  ck_assert_int_eq(result.rows, A.rows);
  ck_assert_int_eq(result.columns, B.columns);
  err = s21_eq_matrix(&correct_res, &result);
  ck_assert_int_eq(SUCCESS, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 2, &B);
  matrix_t *result = NULL;
  int err = s21_mult_matrix(&A, &B, result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &B);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = i + j + 1;
      B.matrix[i][j] = i + j + 1;
    }
  }
  matrix_t result = {NULL, 0, 0};
  matrix_t correct_res = {NULL, 0, 0};
  s21_create_matrix(2, 2, &correct_res);
  correct_res.matrix[0][0] = 5;
  correct_res.matrix[0][1] = 8;
  correct_res.matrix[1][0] = 8;
  correct_res.matrix[1][1] = 13;
  int err = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&correct_res, &result);
  ck_assert_int_eq(SUCCESS, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&correct_res);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_mult_matrix");
  tc = tcase_create("s21_mult_matrix_case");
  
  tcase_add_test(tc, mult_matrix_test_1);
  tcase_add_test(tc, mult_matrix_test_2);
  tcase_add_test(tc, mult_matrix_test_3);
  tcase_add_test(tc, mult_matrix_test_4);
  tcase_add_test(tc, mult_matrix_test_5);
  tcase_add_test(tc, mult_matrix_test_6);

  suite_add_tcase(s, tc);

  return s;
}
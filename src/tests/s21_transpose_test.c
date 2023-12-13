#include "s21_matrix_suites.h"

START_TEST(transpose_test_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t *result = NULL;
  int err = s21_transpose(&A, result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int err = s21_transpose(&A, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(transpose_test_3) {
  matrix_t *A = NULL;
  matrix_t result = {NULL, 0, 0};
  int err = s21_transpose(A, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(transpose_test_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  matrix_t correct = {NULL, 0, 0};
  s21_create_matrix(2, 3, &correct);
  int counter = 0;
  for (int i = 0; i < A.columns; i++) {
    for (int j = 0; j < A.rows; j++) {
      A.matrix[j][i] = ++counter;
    }
  }
  counter = 0;
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = ++counter;
    }
  }
  matrix_t result = {NULL, 0, 0};
  int err = s21_transpose(&A, &result);
  ck_assert_int_eq(OK, err);
  err = s21_eq_matrix(&correct, &result);
  ck_assert_int_eq(SUCCESS, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_transpose");
  tc = tcase_create("s21_transpose_case");
  
  tcase_add_test(tc, transpose_test_1);
  tcase_add_test(tc, transpose_test_2);
  tcase_add_test(tc, transpose_test_3);
  tcase_add_test(tc, transpose_test_4);

  suite_add_tcase(s, tc);

  return s;
}
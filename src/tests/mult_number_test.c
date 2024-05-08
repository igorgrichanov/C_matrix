#include "matrix_suites.h"

START_TEST(mult_number_test_1) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 3, &A);
  matrix_t *result = NULL;
  int err = mult_number(&A, 2, result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
  remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int err = mult_number(&A, 2, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(mult_number_test_3) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 3, &A);
  matrix_t result = {NULL, 0, 0};
  int err = mult_number(&A, 2, &result);
  ck_assert_int_eq(OK, err);
  err = eq_matrix(&A, &result);
  ck_assert_int_eq(SUCCESS, err);
  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test_4) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 3, &A);
  matrix_t result = {NULL, 0, 0};
  matrix_t correct_res = {NULL, 0, 0};
  create_matrix(2, 3, &correct_res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i + 3 * j;
      correct_res.matrix[i][j] = 2 * (i + 3 * j);
    }
  }
  int err = mult_number(&A, 2, &result);
  ck_assert_int_eq(OK, err);
  err = eq_matrix(&correct_res, &result);
  ck_assert_int_eq(SUCCESS, err);
  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&correct_res);
}
END_TEST

START_TEST(mult_number_test_5) {
  matrix_t A = {NULL, 3, 3};
  matrix_t result = {NULL, 0, 0};
  int err = mult_number(&A, 2, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, err);
}
END_TEST

START_TEST(mult_number_test_6) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 3, &A);
  matrix_t result = {NULL, 0, 0};
  matrix_t correct_res = {NULL, 0, 0};
  create_matrix(2, 3, &correct_res);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i + 3 * j;
      correct_res.matrix[i][j] = -2 * (i + 3 * j);
    }
  }
  int err = mult_number(&A, -2, &result);
  ck_assert_int_eq(OK, err);
  err = eq_matrix(&correct_res, &result);
  ck_assert_int_eq(SUCCESS, err);
  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&correct_res);
}
END_TEST

Suite *mult_number_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("mult_number");
  tc = tcase_create("mult_number_case");

  tcase_add_test(tc, mult_number_test_1);
  tcase_add_test(tc, mult_number_test_2);
  tcase_add_test(tc, mult_number_test_3);
  tcase_add_test(tc, mult_number_test_4);
  tcase_add_test(tc, mult_number_test_5);
  tcase_add_test(tc, mult_number_test_6);

  suite_add_tcase(s, tc);

  return s;
}
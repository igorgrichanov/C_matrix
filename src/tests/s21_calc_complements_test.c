#include "s21_matrix_suites.h"

START_TEST(calc_complements_test_1) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t res = {NULL, 0, 0};
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, OK);
  err = s21_eq_matrix(&A, &res);
  ck_assert_int_eq(err, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t res = {NULL, 0, 0};
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_test_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  double *res = NULL;
  int err = s21_calc_complements(&A, res);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_test_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  matrix_t res = {NULL, 0, 0};
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_test_5) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(0, 2, &A);
  matrix_t res = {NULL, 0, 0};
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_test_6) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t res;
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, OK);
  err = s21_eq_matrix(&A, &res);
  ck_assert_int_eq(err, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_test_7) {
  matrix_t A;
  matrix_t res = {NULL, 0, 0};
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_test_8) {
  double A_workpiece[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double res_workpiece[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  matrix_t res_needed = {NULL, 0, 0};
  s21_create_matrix(3, 3, &res_needed);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_workpiece[i][j];
      res_needed.matrix[i][j] = res_workpiece[i][j];
    }
  }
  matrix_t res = {NULL, 0, 0};
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, OK);
  err = s21_eq_matrix(&res_needed, &res);
  ck_assert_int_eq(SUCCESS, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_needed);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_test_9) {
  double A_workpiece[3][3] = {{1, 8, 3}, {0, 4, 2}, {5, 2, 1}};
  double res_workpiece[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  matrix_t res_needed = {NULL, 0, 0};
  s21_create_matrix(3, 3, &res_needed);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_workpiece[i][j];
      res_needed.matrix[i][j] = res_workpiece[i][j];
    }
  }
  matrix_t res = {NULL, 0, 0};
  int err = s21_calc_complements(&A, &res);
  ck_assert_int_eq(err, OK);
  err = s21_eq_matrix(&res_needed, &res);
  ck_assert_int_eq(FAILURE, err);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_needed);
  s21_remove_matrix(&res);
}
END_TEST

Suite *s21_calc_complements_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_calc_complements");
  tc = tcase_create("s21_calc_complements_case");
  
  tcase_add_test(tc, calc_complements_test_1);
  tcase_add_test(tc, calc_complements_test_2);
  tcase_add_test(tc, calc_complements_test_3);
  tcase_add_test(tc, calc_complements_test_4);
  tcase_add_test(tc, calc_complements_test_5);
  tcase_add_test(tc, calc_complements_test_6);
  tcase_add_test(tc, calc_complements_test_7);
  tcase_add_test(tc, calc_complements_test_8);
  tcase_add_test(tc, calc_complements_test_9);

  suite_add_tcase(s, tc);

  return s;
}
#include "matrix_suites.h"

START_TEST(determinant_test_1) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_double_eq_tol(0.0, res, ACCURACY);
  ck_assert_int_eq(err, OK);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_2) {
  matrix_t A = {NULL, 0, 0};
  double res = 2.0;
  int err = determinant(&A, &res);
  ck_assert_double_eq_tol(2.0, res, ACCURACY);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_test_3) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  double *res = NULL;
  int err = determinant(&A, res);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_4) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(3, 2, &A);
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, CALC_ERROR);
  ck_assert_double_eq_tol(0.0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_5) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(0, 2, &A);
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, INCORRECT_MATRIX);
  ck_assert_double_eq_tol(0.0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_6) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  double res;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(0.0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

// START_TEST(determinant_test_7) {
//   matrix_t A;
//   double res = 0.0;
//   int err = determinant(&A, &res);
//   ck_assert_int_eq(err, CALC_ERROR);
//   ck_assert_double_eq_tol(0.0, res, ACCURACY);
// }
// END_TEST

START_TEST(determinant_test_8) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(1, 1, &A);
  A.matrix[0][0] = 5.0;
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(5.0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_9) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(4.0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_10) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 4;
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(10.0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_11) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(3, 3, &A);
  double counter = 0.0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = ++counter;
    }
  }
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(0.0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_12) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 84;
  A.matrix[0][1] = 965.87;
  A.matrix[0][2] = -20;
  A.matrix[1][0] = 8.2;
  A.matrix[1][1] = 54;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -666.21;
  A.matrix[2][1] = 41;
  A.matrix[2][2] = 55;
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(-912358.17, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_13) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(4, 4, &A);
  A.matrix[0][0] = 84;
  A.matrix[0][1] = 965.87;
  A.matrix[0][2] = -20;
  A.matrix[0][3] = 0;
  A.matrix[1][0] = 8.2;
  A.matrix[1][1] = 54;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;
  A.matrix[2][0] = -666.21;
  A.matrix[2][1] = 41;
  A.matrix[2][2] = 55;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 0;
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(0, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_14) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(4, 4, &A);
  A.matrix[0][0] = 84;
  A.matrix[0][1] = 965.87;
  A.matrix[0][2] = -20;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 8.2;
  A.matrix[1][1] = 54;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 51.7;
  A.matrix[2][0] = -666.21;
  A.matrix[2][1] = 41;
  A.matrix[2][2] = 55;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 10;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 2;
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  ck_assert_double_eq_tol(2693395.06, res, ACCURACY);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_15) {
  matrix_t A = {NULL, 0, 0};
  create_matrix(5, 5, &A);
  A.matrix[0][0] = 84;
  A.matrix[0][1] = 965.87;
  A.matrix[0][2] = -20;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 8.2;
  A.matrix[1][0] = 54;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 51.7;
  A.matrix[1][3] = -666.21;
  A.matrix[1][4] = 41;
  A.matrix[2][0] = 55;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = 10;
  A.matrix[2][4] = 0;
  A.matrix[3][0] = 2;
  A.matrix[3][1] = 51.7;
  A.matrix[3][2] = -666.21;
  A.matrix[3][3] = 41;
  A.matrix[3][4] = 55;
  A.matrix[4][0] = -17;
  A.matrix[4][1] = 0;
  A.matrix[4][2] = 10;
  A.matrix[4][3] = 0;
  A.matrix[4][4] = 2;
  double res = 0.0;
  int err = determinant(&A, &res);
  ck_assert_int_eq(err, OK);
  // ck_assert_double_eq(-7.29806e+10, res);
  remove_matrix(&A);
}
END_TEST

Suite *determinant_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("determinant");
  tc = tcase_create("determinant_case");

  tcase_add_test(tc, determinant_test_1);
  tcase_add_test(tc, determinant_test_2);
  tcase_add_test(tc, determinant_test_3);
  tcase_add_test(tc, determinant_test_4);
  tcase_add_test(tc, determinant_test_5);
  tcase_add_test(tc, determinant_test_6);
  // tcase_add_test(tc, determinant_test_7);
  tcase_add_test(tc, determinant_test_8);
  tcase_add_test(tc, determinant_test_9);
  tcase_add_test(tc, determinant_test_10);
  tcase_add_test(tc, determinant_test_11);
  tcase_add_test(tc, determinant_test_12);
  tcase_add_test(tc, determinant_test_13);
  tcase_add_test(tc, determinant_test_14);
  tcase_add_test(tc, determinant_test_15);

  suite_add_tcase(s, tc);

  return s;
}
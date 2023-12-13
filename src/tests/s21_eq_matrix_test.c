#include "s21_matrix_suites.h"

START_TEST(eq_matrix_test_1) {
  matrix_t *A = NULL;
  matrix_t B = {NULL, 0, 0};
  ck_assert_int_eq(s21_eq_matrix(A, &B), FAILURE);
}
END_TEST

START_TEST(eq_matrix_test_2) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  ck_assert_int_eq(s21_eq_matrix(A, B), FAILURE);
}
END_TEST

START_TEST(eq_matrix_test_3) {
  matrix_t A =  {NULL, 0, 0};
  matrix_t *B = NULL;
  ck_assert_int_eq(s21_eq_matrix(&A, B), FAILURE);
}
END_TEST

START_TEST(eq_matrix_test_4) {
  matrix_t A =  {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
}
END_TEST

START_TEST(eq_matrix_test_5) {
  matrix_t A =  {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t B = {NULL, 0, 0};
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_test_6) {
  matrix_t A =  {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_7) {
  matrix_t A =  {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t *B = NULL;
  ck_assert_int_eq(s21_eq_matrix(&A, B), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_test_8) {
  matrix_t *A = NULL;
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_eq_matrix(A, &B), FAILURE);
  s21_remove_matrix(A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_9) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 1, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_10) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 0, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 1, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_11) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(-1, 2, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_12) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, -2, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_13) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &B);
  A.matrix[1][0] = 5.2332896;
  B.matrix[1][0] = 5.2332896;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_14) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = 5.2332892;
  B.matrix[1][0] = 5.2332897;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_15) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = 9549845.23328928;
  B.matrix[1][0] = 9549845.23328923;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_16) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = 9549845.2332891;
  B.matrix[1][0] = 9549845.2332892;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_17) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = -9549845.2332891;
  B.matrix[1][0] = -9549845.2332892;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_18) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = -9549845.23328918;
  B.matrix[1][0] = -9549845.23328911;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_19) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = -954989845.23328918;
  B.matrix[1][0] = -954989845.23328911;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_20) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = -954987845.23328918;
  B.matrix[1][0] = -954989845.23328911;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_test_21) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &B);
  A.matrix[1][0] = -954987845.23328918;
  B.matrix[1][0] = 954989845.23328911;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_matrix_suite() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_eq_matrix");
  tc = tcase_create("s21_eq_matrix_case");
  
  tcase_add_test(tc, eq_matrix_test_1);
  tcase_add_test(tc, eq_matrix_test_2);
  tcase_add_test(tc, eq_matrix_test_3);
  tcase_add_test(tc, eq_matrix_test_4);
  tcase_add_test(tc, eq_matrix_test_5);
  tcase_add_test(tc, eq_matrix_test_6);
  tcase_add_test(tc, eq_matrix_test_7);
  tcase_add_test(tc, eq_matrix_test_8);
  tcase_add_test(tc, eq_matrix_test_9);
  tcase_add_test(tc, eq_matrix_test_10);
  tcase_add_test(tc, eq_matrix_test_11);
  tcase_add_test(tc, eq_matrix_test_12);
  tcase_add_test(tc, eq_matrix_test_13);
  tcase_add_test(tc, eq_matrix_test_14);
  tcase_add_test(tc, eq_matrix_test_15);
  tcase_add_test(tc, eq_matrix_test_16);
  tcase_add_test(tc, eq_matrix_test_17);
  tcase_add_test(tc, eq_matrix_test_18);
  tcase_add_test(tc, eq_matrix_test_19);
  tcase_add_test(tc, eq_matrix_test_20);
  tcase_add_test(tc, eq_matrix_test_21);

  suite_add_tcase(s, tc);

  return s;
}
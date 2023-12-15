#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_correctness(A, A)) return INCORRECT_MATRIX;
  else if (is_matrix_not_square(A)) return CALC_ERROR;
  int err = s21_create_matrix(A->rows, A->columns, result);
  double det = 0.0;
  if (!err) {
    err = s21_determinant(A, &det);
    if ((fabs(det) - 0.0) > ACCURACY) err = CALC_ERROR;
  }
  if (!err) {
    matrix_t complements = {NULL, 0, 0};
    err = s21_calc_complements(A, &complements);
    if (!err) {
      matrix_t transposed = {NULL, 0, 0};
      err = s21_transpose(&complements, &transposed);
      if (!err) {
        err = s21_mult_number(&transposed, 1 / det, result);
      }
      s21_remove_matrix(&transposed);
    }
    s21_remove_matrix(&complements);
  }
  return err;
}
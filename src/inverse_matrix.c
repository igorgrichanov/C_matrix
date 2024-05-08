#include "matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_correctness(A, A) || result == NULL)
    return INCORRECT_MATRIX;
  else if (is_matrix_not_square(A))
    return CALC_ERROR;
  double det = 0.0;
  int err = determinant(A, &det);
  if (fabs(det) < ACCURACY) err = CALC_ERROR;
  if (!err) {
    matrix_t complements = {NULL, 0, 0};
    err = calc_complements(A, &complements);
    if (!err) {
      matrix_t transposed = {NULL, 0, 0};
      err = transpose(&complements, &transposed);
      if (!err) {
        err = mult_number(&transposed, 1 / det, result);
      }
      remove_matrix(&transposed);
    }
    remove_matrix(&complements);
  }
  return err;
}
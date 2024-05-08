#include "matrix.h"

int determinant(matrix_t *A, double *result) {
  if (check_correctness(A, A) || result == NULL)
    return INCORRECT_MATRIX;
  else if (is_matrix_not_square(A))
    return CALC_ERROR;
  int err = 0;
  *result = 0.0;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    for (int j = 0; j < A->columns; j++) {
      double minor = 0.0;
      err = matrix_minor(A, 0, j, &minor);
      if (!err)
        *result += pow(-1, j + 2) * A->matrix[0][j] * minor;  // рекурсия
      else
        break;
    }
  }
  return err;
}
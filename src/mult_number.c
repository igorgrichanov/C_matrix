#include "matrix.h"

int mult_number(matrix_t *A, double number, matrix_t *result) {
  if (check_correctness(A, A)) return INCORRECT_MATRIX;
  int err = create_matrix(A->rows, A->columns, result);
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return err;
}
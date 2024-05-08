#include "matrix.h"

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_correctness(A, B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALC_ERROR;
  int err = create_matrix(A->rows, B->columns, result);
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return err;
}
#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_correctness(A, B)) return INCORRECT_MATRIX;
  else if (not_same_size(A, B)) return CALC_ERROR;
  int err = s21_create_matrix(A->rows, A->columns, result);
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return err;
}
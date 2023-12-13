#include "s21_matrix.h"

// 1 - SUCCESS, 0 - FAILURE
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_correctness(A, B) || not_same_size(A, B)) return FAILURE;
  int err = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(fabs(A->matrix[i][j]) - fabs(B->matrix[i][j])) > 1e-7) err = FAILURE;
    }
  }
  return err;
}
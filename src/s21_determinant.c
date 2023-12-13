#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (check_correctness(A, A)) return INCORRECT_MATRIX;
  else if (is_matrix_not_square(A)) return CALC_ERROR;
  if (A->rows == 1 && A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2 && A->columns == 2) {
    *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    
  }
  
}
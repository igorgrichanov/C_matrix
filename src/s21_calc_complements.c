#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_correctness(A, A)) return INCORRECT_MATRIX;
  else if (is_matrix_not_square(A)) return CALC_ERROR;
  int err = s21_create_matrix(A->rows, A->columns, result);
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor = 0.0;
        err = s21_minor(A, i, j, &minor);
        if (!err) result->matrix[i][j] = minor;
      }
    }
  }
  if (!err) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] *= pow(-1, (i + j + 2));
      }
    }
  }
  return err;
}

int s21_minor(matrix_t *A, int row, int col, double *result) {
  matrix_t temp = {NULL, 0, 0};
  int err = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  if (!err) {
    int row_counter = 0, col_counter = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i == row) continue;
      for (int j = 0; j < A->columns; j++) {
        if (j == col) continue;
        temp.matrix[row_counter][col_counter] = A->matrix[i][j];
        col_counter++;
      }
      row_counter++;
      col_counter = 0;
    }
    err = s21_determinant(&temp, result); // HERE
  }
  return err;
}
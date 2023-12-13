#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < MIN_ROWS || columns < MIN_COLUMNS || result == NULL) return INCORRECT_MATRIX;
  result->matrix = (double **)malloc(sizeof(double *) * rows + sizeof(double) * rows * columns);
  result->rows = rows;
  result->columns = columns;
  double *start = (double *)((char *)result->matrix + sizeof(double *) * rows);

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = start + i * columns;
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0.0;
    }
  }
  return OK;
}
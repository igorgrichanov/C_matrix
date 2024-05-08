#include "matrix.h"

int check_correctness(matrix_t *A, matrix_t *B) {
  int err = OK;
  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL)
    err = INCORRECT_MATRIX;
  else if (A->rows < MIN_ROWS || A->columns < MIN_COLUMNS ||
           B->rows < MIN_ROWS || B->columns < MIN_COLUMNS)
    err = INCORRECT_MATRIX;
  return err;
}

int not_same_size(matrix_t *A, matrix_t *B) {
  int err = OK;
  if ((A->columns != B->columns) || (A->rows != B->rows))
    err = INCORRECT_MATRIX;
  return err;
}

int is_matrix_not_square(matrix_t *A) {
  int err = OK;
  if (A->columns != A->rows) err = INCORRECT_MATRIX;
  return err;
}
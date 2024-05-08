#include "matrix.h"

void remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    free(A->matrix);
    A->matrix = NULL;
  }
  if (A != NULL) {
    A->rows = 0;
    A->columns = 0;
  }
}
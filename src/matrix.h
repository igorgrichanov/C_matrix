#ifndef S21_MATRIX
#define S21_MATRIX

#include <math.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2

#define SUCCESS 1
#define FAILURE 0

#define MIN_ROWS 1
#define MIN_COLUMNS 1

#define ACCURACY 1E-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);
int eq_matrix(matrix_t *A, matrix_t *B);
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int transpose(matrix_t *A, matrix_t *result);
int calc_complements(matrix_t *A, matrix_t *result);
int determinant(matrix_t *A, double *result);
int inverse_matrix(matrix_t *A, matrix_t *result);

int check_correctness(matrix_t *A, matrix_t *B);
int not_same_size(matrix_t *A, matrix_t *B);
int is_matrix_not_square(matrix_t *A);
int matrix_minor(matrix_t *A, int i, int j, double *result);

#endif
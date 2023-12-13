#ifndef S21_MATRIX
#define S21_MATRIX

#include <stdlib.h>
#include <math.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2

#define SUCCESS 1
#define FAILURE 0

#define MIN_ROWS 1
#define MIN_COLUMNS 1

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int check_correctness(matrix_t *A, matrix_t *B);
int not_same_size(matrix_t *A, matrix_t *B);

#endif
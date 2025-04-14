#ifndef MATRIX_H
#define MATRIX_H

#include "../header.h"

/*
    Struct
*/

typedef struct {
    int rows, cols;
    
    float **matrix;
    float **transposed_matrix;
    float **inverted_matrix;
    float **minimum_complementaries;
    float **algebrical_complementaries;

    int rank;
    float determinant;

    bool is_diagonal;
    bool is_upper_triangular;
    bool is_lower_triangular;

    bool determinant_exis;
    bool is_square;
} Matrix;

/*
    General Functions (declaration only)
*/

void matrix_inizialization(Matrix *m, int r, int c);

void matrix_destroy(Matrix *m);

#endif
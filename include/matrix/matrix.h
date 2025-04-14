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
    float **minor_complementaries;
    float **algebrical_complementaries;

    int rank;
    float determinant;

    bool is_diagonal;
    bool is_upper_triangular;
    bool is_lower_triangular;
    bool null_matrix;
    bool determinant_exis;
    bool is_square;
} Matrix;

/*
    General Functions (declaration only)
*/

/**
 * @brief This function is responsible for initializing the data that make up the Matrix structure
 * 
 * @param m matrix struct
 * @param r count of rows
 * @param c count of colums
 */
void matrix_inizialization(Matrix *m, int r, int c);

/**
 * @brief This function is responsible for freeing memory from the data that make up the Matrix struct
 * 
 * @param m matrix struct
 */
void matrix_destroy(Matrix *m);

/**
 * @brief This function checks if the matrix is null rather than not
 * 
 * @param m matrix struct
 */
void matrix_is_null(Matrix *m);

/**
 * @brief This function is responsible for the transposing of the matrix
 * 
 * @param m matrix struct
 */
void transpose_matrix(Matrix *m);

#endif
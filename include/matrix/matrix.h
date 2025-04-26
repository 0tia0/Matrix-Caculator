#ifndef MATRIX_H
#define MATRIX_H

#include "../header.h"
#include "matrix.h"

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
 * @brief This function checks whether the matrix is mull or not.
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

/**
 * @brief This function checks whether the matrix is ​​diagonal or not.
 * 
 * @param m matrix struct
 */
void is_diagonal(Matrix *m);

/**
 * @brief This function checks whether the matrix is upper diagonal or not.
 * 
 * @param m matrix struct
 */
void is_upper_triangular(Matrix *m);

/**
 * @brief This function checks whether the matrix is lower diagonal or not.
 * 
 * @param m matrix struct
 */
void is_lower_triangular(Matrix *m);

void print_matrix(char *name, float **matrix, int rows, int cols);

#endif
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "../header.h"
#include "matrix.h"

/**
 * @brief This function is responsible of calculating, if possible, the sum of two matrix
 * 
 * @param A first matrix
 * @param B second matrix 
 */
Matrix matrix_sum(Matrix *A, Matrix *B);

/**
 * @brief This function is responsible of calculating, if possible, the sub of two matrix
 * 
 * @param A first matrix
 * @param B second matrix 
 */
Matrix matrix_sub(Matrix *A, Matrix *B);

/**
 * @brief This function is responsible of calculating, if possible, the mul of two matrix
 * 
 * @param A first matrix
 * @param B second matrix 
 */
Matrix matrix_mul(Matrix *A, Matrix *B);

/**
 * @brief This function is responsible of calculating, if possible, the div of two matrix
 * 
 * @param A first matrix
 * @param B second matrix 
 */
Matrix matrix_div(Matrix *A, Matrix *B);

#endif
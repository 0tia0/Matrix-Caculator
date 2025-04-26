#ifndef INVERTED_H
#define INVERTED_H

#include "../header.h"
#include "matrix.h"
#include "determinant.h"

/*
    Functions (declaration only)
*/

/**
 * @brief  This function is responsible for calculating the minor complementaries matrix
 * 
 * @param m original matrix
 */
void calculate_minor_complementaries(Matrix *m);

/**
 * @brief  This function is responsible for calculating the algebrical complementaries matrix
 * 
 * @param m original matrix
 */
void calculate_algebrical_complementaries(Matrix *m);

/**
 * @brief  This function is responsible for calculating the inverted matrix
 * 
 * @param m original matrix
 */
void calculate_inverted_matrix(Matrix *m);

#endif
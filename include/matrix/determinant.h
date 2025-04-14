#ifndef DETERMINANT_H
#define DETERMINANT_H

#include "../header.h"
#include "matrix.h"

/*
    Functions (declaration only)
*/

/**
 * @brief This function is responsible of calculating, if possible, the determinant of a matrix.
 * 
 * @param m matrix struct 
 */
void calculate_determinant(Matrix *m);

/**
 * @brief 
 * 
 * @param matrix matrix array
 * @param rows rows count
 * @return float determinant
 */
float big_matrix_determinant(float **matrix, int rows);

#endif
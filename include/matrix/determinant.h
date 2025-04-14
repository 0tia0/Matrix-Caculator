#ifndef DETERMINANT_H
#define DETERMINANT_H

#include "../header.h"
#include "matrix.h"

/*
    Functions (declaration only)
*/

void calculate_determinant(Matrix *m);

float big_matrix_determinant(float **matrix, int rows);

#endif
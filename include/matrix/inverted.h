#ifndef INVERTED_H
#define INVERTED_H

#include "../header.h"
#include "matrix.h"
#include "determinant.h"

/*
    Functions (declaration only)
*/

void calculate_minor_complementaries(Matrix *m);

void calculate_algebrical_complementaries(Matrix *m);

void calculate_inverted_matrix(Matrix *m);

#endif
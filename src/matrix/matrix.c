#include "header.h"
#include "matrix/matrix.h"

/*
     Global Functions
*/

void matrix_inizialization(Matrix *m, int r, int c) {
    m->rows = r;
    m->cols = c;

    m->matrix = malloc(m->rows * sizeof(float *));
    for (int i=0; i < m->rows; i++) {
        m->matrix[i] = malloc(m->cols * sizeof(float));
    }

    m->transposed_matrix = malloc(m->cols * sizeof(float *));
    for (int i=0; i < m->cols; i++) {
        m->transposed_matrix[i] = malloc(m->rows * sizeof(float));
    }

    m->inverted_matrix = malloc(m->rows * sizeof(float *));
    for (int i=0; i < m->rows; i++) {
        m->inverted_matrix[i] = malloc(m->cols * sizeof(float));
    }

    m->minimum_complementaries = malloc(m->rows * sizeof(float *));
    for (int i=0; i < m->rows; i++) {
        m->minimum_complementaries[i] = malloc(m->cols * sizeof(float));
    }

    m->algebrical_complementaries = malloc(m->rows * sizeof(float *));
    for (int i=0; i < m->rows; i++) {
        m->algebrical_complementaries[i] = malloc(m->cols * sizeof(float));
    }

    m->rank = 0;
    m->determinant = 0;

    m->is_diagonal = false;
    m->is_upper_triangular = false;
    m->is_lower_triangular = false;

    if(m->rows == m->cols) {
        m->is_square = true;
        m->determinant_exis = true;
    } else {
        m->is_square = false;
        m->determinant_exis = false;
    }
}

void matrix_destroy(Matrix *m) {
    for (int i=0; i < m->rows; i++) {
        free(m->matrix[i]);
    }
    free(m->matrix);

    for (int i=0; i < m->cols; i++) {
        free(m->transposed_matrix[i]);
    }
    free(m->transposed_matrix);

    for (int i=0; i < m->rows; i++) {
        free(m->inverted_matrix[i]);
    }
    free(m->inverted_matrix);

    for (int i=0; i < m->rows; i++) {
        free(m->minimum_complementaries[i]);
    }
    free(m->minimum_complementaries);

    for (int i=0; i < m->rows; i++) {
        free(m->algebrical_complementaries[i]);
    }
    free(m->algebrical_complementaries);
}

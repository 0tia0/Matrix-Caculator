#include "matrix/determinant.h"

void calculate_determinant(Matrix *m) {
    if(!m->determinant_exis) {
        return;
    }

    if(m->cols == 1 && m->rows == 1) {
        m->determinant = m->matrix[0][0];
        return;
    } else { 
        m->determinant = big_matrix_determinant(m->matrix, m->rows);
        return;
    }
}

float big_matrix_determinant(float **matrix, int rows) {
    if(rows == 1) {
        return matrix[0][0];
    }
    
    float sum = 0;

    for(int i=0; i<rows; i++) {
        float **subMatrix;

        subMatrix = malloc((rows-1) * sizeof(float *));
        for (int i=0; i < rows-1; i++) {
            subMatrix[i] = malloc((rows-1) * sizeof(float));
        }

        for (int l=1; l<rows; l++) {
            int k = 0;
            for (int j=0; j<rows; j++) {
                if (j==i) {
                    continue;
                }
                subMatrix[l - 1][k] = matrix[l][j];
                k++;
            }
        }

        float sign = 0;
        if(i%2==0) {
            sign = 1;
        } else {
            sign = -1;
        }

        sum += sign * matrix[0][i] * big_matrix_determinant(subMatrix, rows - 1);
    
        for (int j = 0; j < rows - 1; j++) {
            free(subMatrix[j]);
        }
        free(subMatrix);
    }

    return sum;
}
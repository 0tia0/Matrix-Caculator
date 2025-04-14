#include "matrix/determinant.h"

/**
 * @brief This function is responsible of calculating, if possible, the determinant of a matrix.
 * 
 * @param m matrix struct 
 */
void calculate_determinant(Matrix *m) {
    //The matrix isn't square
    if(!m->determinant_exis) {
        return;
    }

    //1x1 matrix
    if(m->cols == 1 && m->rows == 1) {
        m->determinant = m->matrix[0][0];
        return;
    } else { 
        //2x2 or more matrix
        m->determinant = big_matrix_determinant(m->matrix, m->rows);
        return;
    }
}

/**
 * @brief 
 * 
 * @param matrix matrix array
 * @param rows rows count
 * @return float determinant
 */
float big_matrix_determinant(float **matrix, int rows) {
    //exit condition
    if(rows == 1) {
        return matrix[0][0];
    }
    
    float sum = 0;
    
    //Laplace
    for(int i=0; i<rows; i++) {
        float **subMatrix;

        //subMatrix without row 1 and col i
        subMatrix = malloc((rows-1) * sizeof(float *));
        for (int i=0; i < rows-1; i++) {
            subMatrix[i] = malloc((rows-1) * sizeof(float));
        }

        //subMatrix fill
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

        //sign calculation
        float sign = 0;
        if(i%2==0) {
            sign = 1;
        } else {
            sign = -1;
        }

        //recursion
        sum += sign * matrix[0][i] * big_matrix_determinant(subMatrix, rows - 1);
    
        //memory cleanup
        for (int j = 0; j < rows - 1; j++) {
            free(subMatrix[j]);
        }
        free(subMatrix);
    }

    return sum;
}
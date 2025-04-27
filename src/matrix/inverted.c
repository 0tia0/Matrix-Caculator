#include "matrix/inverted.h"

/**
 * @brief  This function is responsible for calculating the minor complementaries matrix
 * 
 * @param m original matrix
 */
void calculate_minor_complementaries(Matrix *m) {
    if(!m->is_square) {
        return;
    }

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            //subMatrix without row 1 and col i
            float **subMatrix = malloc((m->rows - 1) * sizeof(float *));
            for (int si = 0; si < m->rows - 1; si++) {
                subMatrix[si] = malloc((m->cols - 1) * sizeof(float));
            }

            //subMatrix fill
            int k = 0;
            for (int r = 0; r < m->rows; r++) {
                if (r == i) {
                    continue;
                }

                int l = 0;
                for (int c = 0; c < m->cols; c++) {
                    if (c == j) {
                        continue;
                    }
                    subMatrix[k][l++] = m->matrix[r][c];
                }

                k++;
            }

            //minor calculations
            m->minor_complementaries[i][j] = big_matrix_determinant(subMatrix, m->rows - 1);

            //memory cleanup
            for (int r = 0; r < m->rows - 1; r++) {
                free(subMatrix[r]);
            }
            free(subMatrix);
        }
    }
}

/**
 * @brief  This function is responsible for calculating the algebrical complementaries matrix
 * 
 * @param m original matrix
 */
void calculate_algebrical_complementaries(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {

            //sign calculation
            int sign = -1;
            if(( (i+1) + (j+1) )%2==0) {
                sign=1;
            }

            m->algebrical_complementaries[i][j] = sign * m->minor_complementaries[i][j];
        }
    }
}

/**
 * @brief  This function is responsible for calculating the inverted matrix
 * 
 * @param m original matrix
 */
void calculate_inverted_matrix(Matrix *m) {
    //if det=0 inverted matrix does not exist
    if(m->determinant == 0) {
        return;
    }

    calculate_minor_complementaries(m);
    calculate_algebrical_complementaries(m);

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            // Index are inverted to transpose the algebrical complentaries matrix
            m->inverted_matrix[i][j] = m->algebrical_complementaries[j][i] * (1/m->determinant);
        }
    }
}
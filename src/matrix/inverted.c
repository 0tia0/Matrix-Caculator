#include "matrix/inverted.h"

void calculate_minor_complementaries(Matrix *m) {
    if(!m->is_square) {
        return;
    }

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            float **subMatrix = malloc((m->rows - 1) * sizeof(float *));
            for (int si = 0; si < m->rows - 1; si++) {
                subMatrix[si] = malloc((m->cols - 1) * sizeof(float));
            }

            int k = 0;
            for (int r = 0; r < m->rows; r++) {
                if (r == i) continue;

                int l = 0;
                for (int c = 0; c < m->cols; c++) {
                    if (c == j) continue;

                    subMatrix[k][l++] = m->matrix[r][c];
                }

                k++;
            }

            m->minor_complementaries[i][j] = big_matrix_determinant(subMatrix, m->rows - 1);

            for (int r = 0; r < m->rows - 1; r++) {
                free(subMatrix[r]);
            }
            free(subMatrix);
        }
    }
}

void calculate_algebrical_complementaries(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {

            int sign = -1;
            if(( (i+1) + (j+1) )%2==0) {
                sign=1;
            }

            m->algebrical_complementaries[i][j] = sign * m->minor_complementaries[i][j];
        }
    }
}

void calculate_inverted_matrix(Matrix *m) {
    if(m->determinant == 0) {
        return;
    }

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            // Index are inverted to transpose the algebrical complentaries matrix
            m->inverted_matrix[i][j] = m->algebrical_complementaries[j][i] * (1/m->determinant);
        }
    }
}
#include "header.h"
#include "matrix/operations.h"
#include "matrix/inverted.h"

Matrix null_matrix;

Matrix matrix_sum(Matrix *A, Matrix *B) {
    //impossible
    if(A->rows != B->rows || A->cols != B->cols) {
        return null_matrix;
    }

    Matrix result;
    matrix_inizialization(&result, A->rows, A->cols);

    for(int i=0; i<A->rows; i++) {
        for(int j=0; j<A->cols; j++) {
            result.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }  
    }

    return result;
}

Matrix matrix_sub(Matrix *A, Matrix *B) {
    //impossible
    if(A->rows != B->rows || A->cols != B->cols) {
        return null_matrix;
    }

    Matrix result;
    matrix_inizialization(&result, A->rows, A->cols);

    for(int i=0; i<A->rows; i++) {
        for(int j=0; j<A->cols; j++) {
            result.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }  
    }

    return result;
}

Matrix matrix_mul(Matrix *A, Matrix *B) {
    //impossible
    if (A->cols != B->rows) {
        return null_matrix;
    }

    Matrix result;
    matrix_inizialization(&result, A->rows, B->cols);

    for (int i=0; i<A->rows; i++) {
        for (int j=0; j<B->cols; j++) {
            result.matrix[i][j] = 0;
            for (int k=0; k<A->cols; k++) {
                result.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
        }
    }

    return result;
}

Matrix matrix_div(Matrix *A, Matrix *B) {
    //impossible
    if (A->cols != B->rows) {
        return null_matrix;
    }

    if(!B->is_square) {
        return null_matrix;
    }

    calculate_inverted_matrix(B);

    return matrix_mul(A, B->inverted_matrix);
}
/*
    Matrix Calculator V1.0           
                                
    Code wrote by Mattia Marelli
    on 2025 as an homework for school
*/

#include "include/header.h"
#include "include/menu/libreria/boxes.h"
#include "include/menu/libreria/menu.h"
#include "include/text/text.h"
#include "include/matrix/matrix.h"
#include "include/matrix/determinant.h"

void print_matrix(float **matrix, int rows, int cols) {
    const int cell_width = 8; // spazio per ogni cella (inclusi bordi)
    const int precision = 2;  // numero di decimali

    // Stampa bordo superiore
    printf("\n\n┌");
    for (int j = 0; j < cols; j++) {
        for (int k = 0; k < cell_width; k++) printf("─");
        if (j < cols - 1) printf("┬");
    }
    printf("┐\n");

    // Stampa righe
    for (int i = 0; i < rows; i++) {
        printf("│");
        for (int j = 0; j < cols; j++) {
            printf(" %*.2f ", cell_width - 2, matrix[i][j]);  // stampa float allineato
            printf("│");
        }
        printf("\n");

        // Stampa bordo intermedio (se non è l'ultima riga)
        if (i < rows - 1) {
            printf("├");
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < cell_width; k++) printf("─");
                if (j < cols - 1) printf("┼");
            }
            printf("┤\n");
        }
    }

    // Stampa bordo inferiore
    printf("└");
    for (int j = 0; j < cols; j++) {
        for (int k = 0; k < cell_width; k++) printf("─");
        if (j < cols - 1) printf("┴");
    }
    printf("┘\n");
}

int main()
{
    // Imposta il charset in UTF-8
    SetConsoleOutputCP(CP_UTF8);

    Matrix m;
    matrix_inizialization(&m, 2, 2);

    m.matrix[0][0] = 3;
    m.matrix[0][1] = 1.5;
    m.matrix[1][0] = 2;
    m.matrix[1][1] = 1;

    calculate_determinant(&m);

    printf("%f", m.determinant);

    print_matrix(m.matrix, m.rows, m.cols);
    transpose_matrix(&m);
    print_matrix(m.transposed_matrix, m.cols, m.rows);

    matrix_destroy(&m);

    return 0;
}
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

int main()
{
    // Imposta il charset in UTF-8
    SetConsoleOutputCP(CP_UTF8);

    Matrix m;
    matrix_inizialization(&m, 2, 2);

    m.matrix[0][0] = 3;
    m.matrix[0][1] = 5;
    m.matrix[1][0] = 2;
    m.matrix[1][1] = 1;

    calculate_determinant(&m);

    printf("%f", m.determinant);

    matrix_destroy(&m);

    return 0;
}
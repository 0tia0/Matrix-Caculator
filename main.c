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
#include "include/matrix/rank.h"
#include "include/matrix/inverted.h"
#include "include/matrix/operations.h"

void welcome_screen() {
    const char *ticket[] = {
        " __  __       _        _         _____      _            _       _             ",
        "|  \\/  |     | |      (_)       / ____|    | |          | |     | |            ",
        "| \\  / | __ _| |_ _ __ ___  __ | |     __ _| | ___ _   _| | __ _| |_ ___  _ __ ",
        "| |\\/| |/ _` | __| '__| \\ \\/ / | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|",
        "| |  | | (_| | |_| |  | |>  <  | |___| (_| | | (__| |_| | | (_| | || (_) | |   ",
        "|_|  |_|\\__,_|\\__|_|  |_/_/\\_\\  \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|   ",
        "",
        "",
        "Funzioni disponibili:",
        "- Operazioni fra matrici",
        "- Calcolo del Determinante",
        "- Matrici trasposte e inverse",
        "- Matrici triangoli e diagonali",
        "- Minori complementari e algebrici",
        "",
        "Limiti:",
        "- Le operazioni devo rispettare tutte",
        "  le regole matematiche delle matrici"
    };

    int lineCount0 = sizeof(ticket) / sizeof(ticket[0]);
    printBox(ticket, lineCount0);

    wait();

    clearScreen();
}

int get_list_size() {
    int matrix_count = 30;
    do {
    printBoxLinesUP();
    printText("Con quante matrici si desidera operare (max 26)", false, CENTER);
    printBoxLinesDOWN();

    printf("\n?:");
    scanf("%d", &matrix_count);
    } while (matrix_count > 26);

    if(matrix_count == 0) {
        printBoxLinesUP();
        printText("Exiting the program...", false, CENTER);
        printBoxLinesDOWN();
        exit(0);
    }

    return matrix_count;
}

void inizialize_matrix_list(Matrix *list, int size) {
    for(int i=0; i<size; i++) {
        char matrix_name = 'A' + i;

        int cols_count, rows_count;

        char cols[50];
        char rows[50];

        sprintf(cols, "Inserire il numero di righe della matrice %c", matrix_name);
        sprintf(rows, "Inserire il numero di colonne della matrice %c", matrix_name);

        printBoxLinesUP();
        printText(cols, false, CENTER);
        printBoxLinesDOWN();
    
        printf("\n?:");
        scanf("%d", &rows_count);

        leaveBlankLine();

        printBoxLinesUP();
        printText(rows, false, CENTER);
        printBoxLinesDOWN();
    
        printf("\n?:"); 
        scanf("%d", &cols_count);

        matrix_inizialization(&list[i], rows_count, cols_count);

        clearScreen();
    }
}

void compile_matrix_list(Matrix *list, int size) {
    for (int i=0; i<size; i++) {
        char matrix_name = 'A' + i;

        char prompt[100];
        sprintf(prompt, "Inserimento dei valori della matrice %c", matrix_name);

        printBoxLinesUP();
        printText(prompt, false, CENTER);
        printBoxLinesDOWN();

        leaveBlankLine();

        for (int j=0; j<list[i].rows; j++) {
            for (int k=0; k<list[i].cols; k++) {
                printf("Valore [%d][%d] della matrice %c:\n?: ", j+1, k+1, matrix_name);
                scanf("%f", &list[i].matrix[j][k]);
            }
            leaveBlankLine();
        }

        clearScreen();
    }
}

int select_matrix(int size, char *prompt) {
    int index = 0;

    char **matrix_names = malloc(size*sizeof(char*));
    
    for (int i=0; i<size; i++) {
        matrix_names[i] = malloc(3);
        sprintf(matrix_names[i], "%c", 'A' + i);  
    }

    int choice = newMenu(prompt, matrix_names, size, &index);

    for (int i=0; i<size; i++) {
        free(matrix_names[i]);
    }
    free(matrix_names);

    return choice;
}

void sum(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la prima matrice:") - 1;
    int b = select_matrix(matrix_list_size, "Seleziona la seconda matrice:") - 1;

    clearScreen();

    if (matrix_list[a].rows != matrix_list[b].rows || matrix_list[a].cols != matrix_list[b].cols)
    {
        printBoxLinesUP();
        printText("Errore: Matrici di dimensioni diverse!", false, CENTER);
        printBoxLinesDOWN();
        wait();
        return;
    }

    *temp_result = matrix_sum(&matrix_list[a], &matrix_list[b]);

    print_matrix("Risultante", temp_result->matrix, temp_result->rows, temp_result->cols);

    matrix_destroy(temp_result);
    wait();

    return;
}


void sub(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la prima matrice:") - 1;
    int b = select_matrix(matrix_list_size, "Seleziona la seconda matrice:") - 1;

    clearScreen();

    if (matrix_list[a].rows != matrix_list[b].rows || matrix_list[a].cols != matrix_list[b].cols)
    {
        printBoxLinesUP();
        printText("Errore: Matrici di dimensioni diverse!", false, CENTER);
        printBoxLinesDOWN();
        wait();
        return;
    }

    *temp_result = matrix_sub(&matrix_list[a], &matrix_list[b]);

    print_matrix("Risultante", temp_result->matrix, temp_result->rows, temp_result->cols);

    matrix_destroy(temp_result);
    wait();

    return;
}

void mul(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la prima matrice:") - 1;
    int b = select_matrix(matrix_list_size, "Seleziona la seconda matrice:") - 1;

    clearScreen();

    if (matrix_list[a].cols != matrix_list[b].rows)
    {
        printBoxLinesUP();
        printText("Errore: Matrici di dimensioni non compatibili!", false, CENTER);
        printBoxLinesDOWN();
        wait();
        return;
    }

    *temp_result = matrix_mul(&matrix_list[a], &matrix_list[b]);

    print_matrix("Risultante", temp_result->matrix, temp_result->rows, temp_result->cols);

    matrix_destroy(temp_result);
    wait();

    return;
}

void divide(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la prima matrice:") - 1;
    int b = select_matrix(matrix_list_size, "Seleziona la seconda matrice:") - 1;
    
    clearScreen();

    if (matrix_list[a].rows != matrix_list[b].cols || !matrix_list[b].is_square)
    {
        printBoxLinesUP();
        printText("Errore: Matrici di dimensioni non compatibili oppure la seconda non è quadrata", false, CENTER);
        printBoxLinesDOWN();
        wait();

        return;
    }

    calculate_determinant(&matrix_list[b]);

    if(matrix_list[b].determinant == 0) {
        printBoxLinesUP();
        printText("Errore: La seconda matrice ha determinante 0 e non supporta la divisione", false, CENTER);
        printBoxLinesDOWN();
        wait();

        return;
    }

    *temp_result = matrix_div(&matrix_list[a], &matrix_list[b]);

    print_matrix("Risultante", temp_result->matrix, temp_result->rows, temp_result->cols);

    matrix_destroy(temp_result);
    wait();

    return;
}

void transpose(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la matrice:") - 1;

    transpose_matrix(&matrix_list[a]);

    clearScreen();
    print_matrix("Trasposta", matrix_list[a].transposed_matrix, matrix_list[a].cols, matrix_list[a].rows);

    wait();
}

void determinant(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la matrice:") - 1;

    clearScreen();

    if (matrix_list[a].rows != matrix_list[a].cols)
    {
        printBoxLinesUP();
        printText("Errore: Il determinante esiste solo per matrici quadrate!", false, CENTER);
        printBoxLinesDOWN();
        wait();

        return;
    }

    calculate_determinant(&matrix_list[a]);

    printf("\nDeterminante: %.2f\n", matrix_list[a].determinant);

    wait();
}

void inverted(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la matrice:") - 1;
    char matrix_name = 'A' + a;

    char name[20];
    sprintf(name, "Inversa di %c", matrix_name);

    clearScreen();

    if(matrix_list[a].is_square) {
        calculate_determinant(&matrix_list[a]);
        calculate_inverted_matrix(&matrix_list[a]);
    } else {
        printBoxLinesUP();
        printText("Errore: Matrice non quadrata", false, CENTER);
        printBoxLinesDOWN();
        wait();

        return;
    }

    print_matrix(name, matrix_list[a].inverted_matrix, matrix_list[a].rows, matrix_list[a].cols);

    wait();
}

void info(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    int a = select_matrix(matrix_list_size, "Seleziona la matrice:") - 1;
    char matrix_name = 'A' + a;

    char name[2];
    sprintf(name, "%c", matrix_name);

    clearScreen();

    matrix_is_null(&matrix_list[a]);
    is_upper_triangular(&matrix_list[a]);
    is_lower_triangular(&matrix_list[a]);
    is_diagonal(&matrix_list[a]);
    transpose_matrix(&matrix_list[a]);
    
    printf("\nInformazioni sulla matrice %c:\n", 'A' + a);
    printf("- Righe: %d\n", matrix_list[a].rows);
    printf("- Colonne: %d\n", matrix_list[a].cols);
    if(matrix_list[a].is_square) {
        calculate_determinant(&matrix_list[a]);
        calculate_inverted_matrix(&matrix_list[a]);

        printf("- Determinante: %.2f\n", matrix_list[a].determinant);
        printf("- È quadrata\n");
    }

    if (matrix_list[a].is_upper_triangular)
    {
        printf("- È triangolare superiore\n");
    }

    if (matrix_list[a].is_lower_triangular)
    {
        printf("- È triangolare inferiore\n");
    }

    if (matrix_list[a].is_diagonal)
    {
        printf("- È diagonale\n");
    }

    if (matrix_list[a].null_matrix)
    {
        printf("- È nulla\n");
    }

    print_matrix(name, matrix_list[a].matrix, matrix_list[a].rows, matrix_list[a].cols);
    print_matrix("Trasposta", matrix_list[a].transposed_matrix, matrix_list[a].cols, matrix_list[a].rows);
    if(matrix_list[a].is_square) {
        print_matrix("Minori complementari", matrix_list[a].minor_complementaries, matrix_list[a].rows, matrix_list[a].cols);
        print_matrix("Complementi algebrici", matrix_list[a].algebrical_complementaries, matrix_list[a].rows, matrix_list[a].cols);
        print_matrix("Inversa", matrix_list[a].inverted_matrix, matrix_list[a].rows, matrix_list[a].cols);
    }

    wait();
}

void list(Matrix *temp_result, Matrix *matrix_list, int matrix_list_size) {
    clearScreen();

    for (int i = 0; i < matrix_list_size; i++)
    {
        char matrix_name = 'A' + i;

        char name[2];
        sprintf(name, "%c", matrix_name);

        print_matrix(name, matrix_list[i].matrix, matrix_list[i].rows, matrix_list[i].cols);
    }

    wait();
}

void show_matrix_operations(Matrix *matrix_list, int matrix_list_size)
{
    const char *options[] = {
        "Somma di due matrici",
        "Sottrazione di due matrici",
        "Moltiplicazione di due matrici",
        "Divisione di due matrici",
        "Trasposta di una matrice",
        "Determinante di una matrice",
        "Inversa di una matrice",
        "Informazioni sulla matrice",
        "Visualizza le matrici inserite"
    };

    int options_count = sizeof(options) / sizeof(options[0]);
    int selected = 0;

    while (1)
    {
        clearScreen();

        int choice = newMenu("Seleziona un'operazione:", options, options_count, &selected) - 1;

        Matrix temp_result;

        switch (choice)
        {
            case 0:
            {
                sum(&temp_result, matrix_list, matrix_list_size);
                break;
            }

            case 1:
            {
                sub(&temp_result, matrix_list, matrix_list_size);
                break;
            }

            case 2:
            {
                mul(&temp_result, matrix_list, matrix_list_size);
                break;
            }

            case 3:
            {
                divide(&temp_result, matrix_list, matrix_list_size);
                break;
            }

            case 4:
            {
                transpose(&temp_result, matrix_list, matrix_list_size);
                break;
            }

            case 5:
            {
                determinant(&temp_result, matrix_list, matrix_list_size);
                break;
            }

            case 6:
            {
                inverted(&temp_result, matrix_list, matrix_list_size); 
                break;
            }

            case 7:
            {       
                info(&temp_result, matrix_list, matrix_list_size);       
                break;
            }

            case 8: 
            {
                list(&temp_result, matrix_list, matrix_list_size);
                break;
            }
        }
    }
}

void load_matrices(Matrix matrix_list[], int matrix_list_size)
{
    inizialize_matrix_list(matrix_list, matrix_list_size);
    compile_matrix_list(matrix_list, matrix_list_size);

    for (int i=0; i<matrix_list_size; i++)
    {
        char matrix_name = 'A' + i;

        char name[2];
        sprintf(name, "%c", matrix_name);

        print_matrix(name, matrix_list[i].matrix, matrix_list[i].rows, matrix_list[i].cols);
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    welcome_screen();

    int matrix_list_size = get_list_size();
    Matrix matrix_list[matrix_list_size];

    load_matrices(matrix_list, matrix_list_size);

    wait();
    clearScreen();

    show_matrix_operations(matrix_list, matrix_list_size);

    return 0;
}
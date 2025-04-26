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
        "- Matrici trangoli e diagonali",
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

void inizialize_matrix(Matrix *list, int size) {
    for(int i=0; i<size; i++) {
        char matrix_name;

        char cols[50];
        char rows[50];

        sprintf(cols, "Inserire il numero di righe della matrice %c", matrix_name);
        sprintf(rows, "Inserire il numero di colonne della matrice %c", matrix_name);

        printBoxLinesUP();
        printText(cols, false, CENTER);
        printBoxLinesDOWN();
    
        printf("\n?:");
        scanf("%d", list[i].rows);

        leaveBlankLine();

        printBoxLinesUP();
        printText(rows, false, CENTER);
        printBoxLinesDOWN();
    
        printf("\n?:"); 
        scanf("%d", list[i].cols);

        clearScreen();
    }
}

int main()
{
    // Imposta il charset in UTF-8
    SetConsoleOutputCP(CP_UTF8);

    welcome_screen();

    int matrix_list_size = get_list_size();
    Matrix matrix_list[matrix_list_size];

    

    return 0;
}

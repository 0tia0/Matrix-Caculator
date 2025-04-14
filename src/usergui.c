#include "usergui.h"
#include "text.h"
#include "header.h"
#include "boxes.h"
#include <limits.h>

int isValidChar(char c) {    
    return ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
             (c >= '0' && c <= '9') || (strchr(specialChars, c) != NULL) );
}

int readKey() {
    clearScreen();

    char carattere;
    int numero = 0;
    int i = 0;

    printBoxLines();
    printText("Inserire la chiave di cifratura", false, CENTER);
    printBoxLines();

    char buffer[MAX_KEY_LENGHT + 1];

    for(int j=0; j<MAX_KEY_LENGHT; j++) {
        buffer[j] = '_';
    }

    buffer[MAX_KEY_LENGHT] = '\0';

    printText(buffer, false, CENTER);
    printBoxLines();

    moveCursor((BOX_WIDTH/2-MAX_KEY_LENGHT/2)+1, 4);

    while (1) {
        carattere = getch(); 

        if (carattere == '\r' && i > 0) {
            buffer[i] = '\0';
            break;
        } else if (carattere == '\b' && i > 0) {
            i--;
            buffer[i] = '\0';
            moveCursor(i + (BOX_WIDTH / 2 - MAX_KEY_LENGHT / 2) + 1, 4);
            printf("_");
            moveCursor(i + (BOX_WIDTH / 2 - MAX_KEY_LENGHT / 2) + 1, 4);
        } else if (i < MAX_KEY_LENGHT && carattere >= '0' && carattere <= '9') {
            buffer[i] = carattere;
            moveCursor(i + (BOX_WIDTH / 2 - MAX_KEY_LENGHT / 2) + 1, 4);
            printf("*");
            i++;
        }
    }

    for (int j = 0; j < i; j++) {
        numero = numero * 10 + (buffer[j] - '0');
    }

    return numero;
}

void readPassword(char *buffer) {
    char c;
    int i = 0;

    clearScreen();

    printBoxLines();
    printText("Inserire la password", false, CENTER);
    printBoxLines();

    char bufferPlaceHolder[MAX_PASSWORD_LENGTH + 1];
    for(int j=0; j<MAX_PASSWORD_LENGTH; j++) {
        bufferPlaceHolder[j] = '_';
    }
    bufferPlaceHolder[MAX_PASSWORD_LENGTH] = '\0';

    printText(bufferPlaceHolder, false, CENTER);
    
    printBoxLines();

    moveCursor((BOX_WIDTH/2-MAX_PASSWORD_LENGTH/2)+1, 4);

    while (1) {
        c = getch();

        if (c == '\r' && i > 0) {
            buffer[i] = '\0';
            break;
        } else if (c == '\b' && i > 0) {
            i--;
            buffer[i] = '\0';
            moveCursor(i + (BOX_WIDTH / 2 - MAX_PASSWORD_LENGTH / 2) + 1, 4);
            printf("_");
            moveCursor(i + (BOX_WIDTH / 2 - MAX_PASSWORD_LENGTH / 2) + 1, 4);
        } else if (i < MAX_PASSWORD_LENGTH && isValidChar(c)) {
            buffer[i] = c;
            moveCursor(i + (BOX_WIDTH / 2 - MAX_PASSWORD_LENGTH / 2) + 1, 4);
            printf("*");
            i++;
        }
    }

    buffer[i] = '\0';

    clearScreen();
}
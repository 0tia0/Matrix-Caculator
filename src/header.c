#include "header.h"

/*
     Global Functions
*/

void moveCursor(int x, int y) {
    printf("\033[%d;%dH",y,x);
}

void wait() {
    printf("\n\n");
    system("pause");
}
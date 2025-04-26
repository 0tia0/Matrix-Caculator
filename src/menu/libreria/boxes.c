#include "menu/libreria/boxes.h"

/**
 * @brief stampa il lati del box
 */
void printBoxSide()
{
    printf("%s", BOX_SIDE);
    for (int i = 0; i < BOX_WIDTH - 2; i++)
    {
        printf(" ");
    }
    printf("%s", BOX_SIDE);
}

/**
 * @brief stampa la parte superio del box
 */
void printBoxLinesUP()
{
    printf("\n%s", BOX_SIDE_LEFT_UP);
    for (int i = 0; i < BOX_WIDTH - 2; i++)
    {
        printf("%s", BOX_CHAR);
    }
    printf("%s", BOX_SIDE_RIGHT_UP);
    printf("\n");
}

/**
 * @brief stampa la parte sotto del box
 */
void printBoxLinesDOWN()
{
    printf("%s", BOX_SIDE_LEFT_DOWN);
    for (int i = 0; i < BOX_WIDTH - 2; i++)
    {
        printf("%s", BOX_CHAR);
    }
    printf("%s", BOX_SIDE_RIGHT_DOWN);
    printf("\n");
}

/**
 * @brief stampa diverse linee di testo centrate in un box
 *
 * @param text le linee da stampare
 * @param lineCount la quantita delle linee
 */
void printBox(const char *text[], int lineCount)
{
    printBoxLinesUP();

    // stampa le linee centrate
    for (int i = 0; i < lineCount; i++)
    {
        printText(text[i], false, CENTER);
    }

    printBoxLinesDOWN();
}
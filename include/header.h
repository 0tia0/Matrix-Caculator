#ifndef HEADER_H
#define HEADER_H

/*
    Libraries inclusion
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

/*
    Enums
*/

enum TEXT_FORMAT
{
    LEFT,
    CENTER,
    RIGHT
};

/*
    Global definitions
*/

#define BOX_CHAR '-'
#define BOX_SIDE '#'
#define BOX_WIDTH 70

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER_KEY 13
#define ESC_KEY 27

// I seguenti valori devono essere pari
#define MAX_KEY_LENGHT 6
#define MAX_PASSWORD_LENGTH 30

/*
     Global Variables (declaration only)
*/

extern const char specialChars[];
extern const char capsChars[];
extern const char lowerChars[];
extern const char digits[];

void moveCursor(int x, int y);

#endif
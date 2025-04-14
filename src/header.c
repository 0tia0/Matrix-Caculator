#include "header.h"

const char specialChars[] = "!?/@#$%&*()-_=+[{]}|;:,<.>";
const char capsChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lowerChars[] = "abcdefghijklmnopqrstuvwxyz";
const char digits[] = "0123456789";

void moveCursor(int x, int y) {
    printf("\033[%d;%dH",y,x);
}
#ifndef CESARE_H
#define CESARE_H

#include "header.h"

char encryptChar(char c, int key);

char decryptChar(char c, int key);

void cifrarioCesare(char *input, char *output, int operation, int key);

#endif
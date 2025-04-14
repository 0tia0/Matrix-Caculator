#include "cesare.h"
#include <time.h>

char encryptChar(char c, int key) {
    int specialCharsCount = strlen(specialChars);
    int capsCharsCount = strlen(capsChars);
    int lowerCharsCount = strlen(lowerChars);
    
    if (c >= 'A' && c <= 'Z') {
        key = key % capsCharsCount; // Limita la chiave
        for (int i = 0; i < capsCharsCount; i++) {
            if (c == capsChars[i]) {
                c = capsChars[(i + key) % capsCharsCount];
                break;
            }
        }
    } else if (c >= 'a' && c <= 'z') {
        key = key % lowerCharsCount; // Limita la chiave
        for (int i = 0; i < lowerCharsCount; i++) {
            if (c == lowerChars[i]) {
                c = lowerChars[(i + key) % lowerCharsCount];
                break;
            }
        }
    } else if (c >= '0' && c <= '9') {
        key = key % 10; // Limita la chiave per le cifre
        c = c + key;
        if (c > '9') c = c - 10;
    } else {
        key = key % specialCharsCount; // Limita la chiave
        for (int i = 0; i < specialCharsCount; i++) {
            if (c == specialChars[i]) {
                c = specialChars[(i + key) % specialCharsCount];
                break;
            }
        }
    }

    return c;
}

char decryptChar(char c, int key) {
    int specialCharsCount = strlen(specialChars);
    int capsCharsCount = strlen(capsChars);
    int lowerCharsCount = strlen(lowerChars);

    if (c >= 'A' && c <= 'Z') {
        key = key % capsCharsCount; // Limita la chiave
        for (int i = 0; i < capsCharsCount; i++) {
            if (c == capsChars[i]) {
                c = capsChars[(i - key + capsCharsCount) % capsCharsCount];
                break;
            }
        }
    } else if (c >= 'a' && c <= 'z') {
        key = key % lowerCharsCount; // Limita la chiave
        for (int i = 0; i < lowerCharsCount; i++) {
            if (c == lowerChars[i]) {
                c = lowerChars[(i - key + lowerCharsCount) % lowerCharsCount];
                break;
            }
        }
    } else if (c >= '0' && c <= '9') {
        key = key % 10; // Limita la chiave per le cifre
        c = c - key;
        if (c < '0') c = c + 10;
    } else {
        key = key % specialCharsCount; // Limita la chiave
        for (int i = 0; i < specialCharsCount; i++) {
            if (c == specialChars[i]) {
                c = specialChars[(i - key + specialCharsCount) % specialCharsCount];
                break;
            }
        }
    }

    return c;
}

void cifrarioCesare(char *input, char *output, int operation, int key) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (operation) {
            output[i] = decryptChar(input[i], key);
        } else {
            output[i] = encryptChar(input[i], key);
        }
    }
    output[strlen(input)] = '\0';
}
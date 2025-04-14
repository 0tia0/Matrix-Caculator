/*
    Caesar Vault V1.0           
                                
    Code wrote by Mattia Marelli
    on 2025 as an homework for school
*/

#include "include/header.h"
#include "boxes.h"
#include "menu.h"
#include "text.h"
#include "usergui.h"
#include "cesare.h"

int main()
{
    // Imposta il charset in UTF-8
    SetConsoleOutputCP(CP_UTF8);

    int key = readKey();

    int password[MAX_PASSWORD_LENGTH + 1];
    int buffer[MAX_PASSWORD_LENGTH + 1];

    while(1) {
        const char *options[] = {
            "Cifra una password",
            "Decifra una password",
        };
        int lineCount1 = sizeof(options) / sizeof(options[0]);
        int count = 0;

        int selection = newMenu("Cosa desideri fare:", options, lineCount1, &count);

        if(selection == 1 || selection == 2) {
            readPassword(password);
        }

        switch (selection)
        {
        case 0:
            clearScreen();
            exit(0);
            break;
        case 1:
            //cifra
            cifrarioCesare(password, buffer, 0, key);

            printBoxLines();
            printText("PASSWORD CIFRATA:", false, CENTER);
            printBoxLines();
            printText(buffer, false, CENTER);
            printBoxLines();

            leaveBlankLine();

            system("pause");
            break;
        case 2:
            //decifra
            cifrarioCesare(password, buffer, 1, key);

            printBoxLines();
            printText("PASSWORD DECIFRATA:", false, CENTER);
            printBoxLines();
            printText(buffer, false, CENTER);
            printBoxLines();

            leaveBlankLine();

            system("pause");
            break;
        }
    }

    clearScreen();

    return 0;
}
//
//  lab 3.c
//  C labs
//
//  Created by Илья Овсянников on 10.04.2025.
//
//Ввести с консоли строку символов произвольной длины (до 80 символов). Поменять в ней все маленькие символы ‘a’ и ‘b’ на заглавные и вывести на консоль получен-ную строку.

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80

int main(void) {
    char input[MAX_LENGTH + 1];

    printf("Введите строку (до 80 символов): ");
    fgets(input, MAX_LENGTH + 1, stdin);

    input[strcspn(input, "\n")] = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') {
            input[i] = 'A';
        } else if (input[i] == 'b') {
            input[i] = 'B';
        }
    }

    printf("Полученная строка: %s\n", input);

    return 0;
}

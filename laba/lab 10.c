//
//  lab 10.c
//  C labs
//
//  Created by Илья Овсянников on 10.05.2025.
//Написать программу вычисления максимального числа из введенных пользователем в виде одной строки.  Использовать для этого макрос (без функции), на вход которому по-дается массив чисел и их количество.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define MAX_IN_ARRAY(arr, n, max) \
    do { \
        max = arr[0]; \
        for (int i = 1; i < n; i++) { \
            if (arr[i] > max) max = arr[i]; \
        } \
    } while(0)

int main(void) {
    char line[1024];
    int numbers[MAX_NUMBERS];
    int count = 0;

    printf("Введите числа через пробел в одной строке:\n");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        printf("Ошибка ввода\n");
        return 1;
    }


    // Разбиваем строку на числа
    char *token = strtok(line, " ");
    while (token != NULL && count < MAX_NUMBERS) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int max_value;
    MAX_IN_ARRAY(numbers, count, max_value);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }

    //среднее арифметическое
    double average = (double)sum / count;
    
    printf("Максимальное число: %d\n", max_value);
    printf("Среднее арифметическое: %.2f\n", average);

    return 0;
}

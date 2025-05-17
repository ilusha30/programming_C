//
//  lab 11.c
//  C labs
//
//  Created by Илья Овсянников on 17.05.2025.
//Создать в отдельном модуле функции с переменным количеством аргументов, которая вычисляет их сумму, максимум, минимум, среднее арифметическое.


#include <stdio.h>

int summation(int num, ...);
int maximum(int num, ...);
int minimum(int num, ...);
double average(int num, ...);

int main(void) {
    int count = 5;
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    printf("Сумма: %d\n", summation(count, a, b, c, d, e));
    printf("Максимум: %d\n", maximum(count, a, b, c, d, e));
    printf("Минимум: %d\n", minimum(count, a, b, c, d, e));
    printf("Среднее арифметическое: %.2f\n", average(count, a, b, c, d, e));

    return 0;
}

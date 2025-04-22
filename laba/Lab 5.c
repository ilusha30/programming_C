//
//  Lab 5.c
//  C labs
//
//  Created by Илья Овсянников on 19.04.2025.
//Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли). А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и возвращающую указатель на массив-результат. Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения полученного вектора.

#include <stdio.h>
#include <stdlib.h>
#include "matrix-ops.h"

int main(void) {
    int n;
    printf("Введите размерность матриц n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Неверный ввод размерности.\n");
        return 1;
    }

    // Выделяем память под две матрицы
    double* a = (double*)malloc(n * n * sizeof(double));
    double* b = (double*)malloc(n * n * sizeof(double));

    if (!a || !b) {
        printf("Ошибка выделения памяти.\n");
        free(a);
        free(b);
        return 1;
    }

    printf("Введите элементы первой матрицы (%d элементов):\n", n * n);
    for (int i = 0; i < n * n; i++) {
        if (scanf("%lf", &a[i]) != 1) {
            printf("Ошибка ввода элемента.\n");
            free(a);
            free(b);
            return 1;
        }
    }

    printf("Введите элементы второй матрицы (%d элементов):\n", n * n);
    for (int i = 0; i < n * n; i++) {
        if (scanf("%lf", &b[i]) != 1) {
            printf("Ошибка ввода элемента.\n");
            free(a);
            free(b);
            return 1;
        }
    }

    char op;
    printf("Введите операцию ('+', '-' или '*'): ");
    scanf(" %c", &op);

    double* result = matrix_operation(a, b, n, op);
    if (!result) {
        printf("Ошибка: неверный оператор или ошибка выделения памяти.\n");
        free(a);
        free(b);
        return 1;
    }

    printf("Результат операции:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", result[i * n + j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(result);

    return 0;
}

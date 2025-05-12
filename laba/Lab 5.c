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
    double** a = create_matrix(n);
    double** b = create_matrix(n);

    if (!a || !b) {
        printf("Ошибка выделения памяти.\n");
        free_matrix(a, n);
        free_matrix(b, n);
        return 1;
    }

    printf("Введите элементы первой матрицы (%d элементов):\n", n * n);
    input_matrix(a, n);

    printf("Введите элементы второй матрицы (%d элементов):\n", n * n);
    input_matrix(b, n);


    double** result_plus = matrix_plus(a, b, n );
    double** result_min = matrix_min(a, b, n );
    double** result_um = matrix_um(a, b, n );
    
    char op;
    printf("Введите операцию ('+', '-' или '*'): ");
    scanf(" %c", &op);

    double** result = matrix_operation(a, b, n, op);
    if (!result) {
        printf("Ошибка: неверный оператор или ошибка выделения памяти.\n");
        free_matrix(a, n);
        free_matrix(b, n);
        return 1;
    }

    
    printf("Результат операции:\n");
    print_matrix(result_plus, n);
    print_matrix(result_min, n);
    print_matrix(result_um, n);
    print_matrix(result, n);

    free_matrix(a, n);
    free_matrix(b, n);
    

    return 0;
}

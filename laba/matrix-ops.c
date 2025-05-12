//
//  matrix-ops.c
//  C labs
//
//  Created by Илья Овсянников on 22.04.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrix-ops.h"

// Выделение памяти под матрицу n x n
double** create_matrix(int n){
    double** matrix = malloc(n * sizeof(double*));
    if (!matrix) return NULL;
    
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(double));
    }return matrix;
}


// Освобождение памяти матрицы n x n
void free_matrix(double** matrix, int n) {
    if (!matrix) return;
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Ввод элементов матрицы n x n
void input_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                printf("Ошибка ввода элемента [%d][%d]\n", i, j);
            }
        }
    }
}

// Вывод матрицы n x n
void print_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.4lf ", matrix[i][j]);
        }
        printf("\n");
    }
}


double** matrix_plus(double**a ,double** b, int n){
    double** result_pl = create_matrix(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            result_pl[i][j] = a[i][j] + b[i][j];
    }
    return result_pl;
}

double**  matrix_min(double**a ,double** b, int n){
    double** result_m = create_matrix(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            result_m[i][j] = a[i][j] - b[i][j];
    }return result_m;
}
double**  matrix_um(double**a ,double** b, int n){
    double** result_um = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result_um[i][j] = sum;
        }
    }return result_um;
}

// Операции над матрицами n x n
double** matrix_operation(double** a, double** b, int n, char op) {
    double** result = create_matrix(n);
    if (!result) return NULL;

    switch (op) {
        case '-':
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    result[i][j] = a[i][j] - b[i][j];
            break;

        case '*':
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    double sum = 0.0;
                    for (int k = 0; k < n; k++) {
                        sum += a[i][k] * b[k][j];
                    }
                    result[i][j] = sum;
                }
            }
            break;
    }

    return result;
}

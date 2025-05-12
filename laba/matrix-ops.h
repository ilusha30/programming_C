//
//  matrix-ops.h
//  C labs
//
//  Created by Илья Овсянников on 22.04.2025.
//

#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

// Выделение памяти под матрицу n x n
double** create_matrix(int n);

// Освобождение памяти матрицы n x n
void free_matrix(double** matrix, int n);

// Ввод элементов матрицы n x n с консоли
void input_matrix(double** matrix, int n);

// Вывод матрицы n x n на консоль
void print_matrix(double** matrix, int n);


double** matrix_plus(double**a ,double** b, int n);
double**  matrix_min(double**a ,double** b, int n);
double**  matrix_um(double**a ,double** b, int n);
double** matrix_operation(double** a, double** b, int n, char op);

#endif // MATRIX_OPS_H


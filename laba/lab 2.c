//
//  lab 2.c
//  C labs
//
//  Created by Илья Овсянников on 31.03.2025.
//
//Объявить массив данных типа double размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, расположенных на  побочной диагонали.Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значения, вывести на консоль квадрат данной матрицы.


#include <stdio.h>

int main(void) {
    double matrix[3][3];
    double diagonalSum = 0.0;
    double secondaryDiagonalSum = 0.0;
    int matrix2[2][2];
    int cvadrat[2][2];
    // Ввод значений
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Введите значение для [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    
    // Вывод введенных значений
    printf("Введенные значения:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Сумма элементов на главной диагонали
    for (int i = 0; i < 3; i++) {
        diagonalSum += matrix[i][i];
    }
    
    // Сумма элементов на побочной диагонали
    for (int i = 0; i < 3; i++) {
        secondaryDiagonalSum += matrix[i][2 - i];
    }
    
    printf("Сумма элементов на главной диагонали: %f\n", diagonalSum);
    printf("Сумма элементов на побочной диагонали: %f\n", secondaryDiagonalSum);
    
    //Ввод значений второй матрицы
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) {
            printf("Введите значения для второй матрицы [%d][%d]: ", i , j);
            scanf("%d", &matrix2[i][j]);
        }
        
    }
    
    //Вывод значений
    printf("Введенные значения:\n");
    for (int i = 0; i < 2; i++ ){
        for (int j =0; j < 2; j++){
            printf("%d", matrix2[i][j]);
        }
        printf("\n");
    }
    
    // Обнуление массива cvadrat
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cvadrat[i][j] = 0;

    // Вычисление квадрата матрицы
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cvadrat[i][j] += matrix2[i][k] * matrix2[k][j];
            }
        }
    }

    // Вывод результата
    printf("Квадрат матрицы:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", cvadrat[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}


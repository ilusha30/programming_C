//
//  lab 4 main.c
//  C labs
//
//  Created by Илья Овсянников on 10.04.2025.
// Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон. Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади.
#include <stdio.h>
#include <math.h>
#include "triangle_module.h"

// Проверка на корректность неравенства треугольника
int check_triangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main(void) {
    double a, b, c;

    printf("Введите длины сторон треугольника (a, b, c):\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (check_triangle(a, b, c)) {
        double perimeter = calculate_perimeter(a, b, c);
        double area = calculate_area(a, b, c);
        double Ha = calculate_Ha(a, b , c);
        double Hb = calculate_Hb(a, b,  c);
        double Hc = calculate_Hc(a, b,  c);

        printf("Периметр треугольника: %.2f\n", perimeter);
        printf("Площадь треугольника: %.2f\n", area);
        printf("Длинна высоты к стороне A: %.2f\n", Ha);
        printf("Длинна высоты к стороне B: %.2f\n", Hb);
        printf("Длинна высоты к стороне C: %.2f\n", Hc);
    } else {
        printf("Неравенство треугольника не выполнено. Введите другие значения.\n");
    }

    return 0;
}



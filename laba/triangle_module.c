//
//  triangle_module.c
//  C labs
//
//  Created by Илья Овсянников on 10.04.2025.
//
#include <math.h>

// Функция для вычисления периметра треугольника
double calculate_perimeter(double a, double b, double c) {
    return a + b + c;
}

// Функция для вычисления площади треугольника по формуле Герона
double calculate_area(double a, double b, double c) {
    double s = (a + b + c) / 2; // Полупериметр
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

//Функция для вычисления высот к сторонам
double calculate_Ha(double a, double b, double c){
    double s = (a + b + c) / 2;
    return (2 * sqrt(s * (s - a) * (s - b) * (s - c)))/a;
}

double calculate_Hb(double a, double b, double c){
    double s = (a + b + c) / 2;
    return (2 * sqrt(s * (s - a) * (s - b) * (s - c)))/b;
}

double calculate_Hc(double a, double b, double c){
    double s = (a + b + c) / 2;
    return (2 * sqrt(s * (s - a) * (s - b) * (s - c)))/c;
}


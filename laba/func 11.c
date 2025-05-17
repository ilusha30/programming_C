//
//  func 11.c
//  C labs
//
//  Created by Илья Овсянников on 17.05.2025.
//
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int summation(int num, ...) {
    va_list args;
    va_start(args, num);

    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum;
}

int maximum(int num, ...) {
    va_list args;
    va_start(args, num);

    int max = INT_MIN;
    for (int i = 0; i < num; i++) {
        int val = va_arg(args, int);
        if (val > max) max = val;
    }

    va_end(args);
    return max;
}

int minimum(int num, ...) {
    va_list args;
    va_start(args, num);

    int min = INT_MAX;
    for (int i = 0; i < num; i++) {
        int val = va_arg(args, int);
        if (val < min) min = val;
    }

    va_end(args);
    return min;
}

double average(int num, ...) {
    va_list args;
    va_start(args, num);

    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, int);
    }

    va_end(args);
    if (num == 0) return 0.0;  
    return (double)sum / num;
}


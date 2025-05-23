//
//  lab 16.c
//  C labs
//
//  Created by Илья Овсянников on 17.05.2025.
//Написать программу подсчитывающая количество битов, выставленных в единицу у числа типа long и double. Сами значения чисел вводятся с клавиатуры.

/*#include <stdio.h>

int count_bits_long(long num) {
    int count = 0;
    unsigned long mask = 1;
    for (int i = 0; i < sizeof(long) * 8; i++) {
        if (num & mask) {
            count++;
        }
        mask <<= 1;
    }
    return count;
}

int count_bits_double(double num) {
    int count = 0;
    unsigned char *ptr = (unsigned char*)&num;
    for (size_t i = 0; i < sizeof(double); i++) {
        unsigned char byte = ptr[i];
        for (int j = 0; j < 8; j++) {
            if (byte & (1 << j)) {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    long lnum;
    double dnum;

    printf("Введите число типа long: ");
    if (scanf("%ld", &lnum) != 1) {
        printf("Ошибка ввода для long.\n");
        return 1;
    }

    printf("Введите число типа double: ");
    if (scanf("%lf", &dnum) != 1) {
        printf("Ошибка ввода для double.\n");
        return 1;
    }

    int bits_long = count_bits_long(lnum);
    int bits_double = count_bits_double(dnum);

    printf("Количество битов, установленных в 1 в числе long: %d\n", bits_long);
    printf("Количество битов, установленных в 1 в числе double: %d\n", bits_double);

    return 0;
}*/



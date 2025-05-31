//
//  lab 16.c
//  C labs
//
//  Created by Илья Овсянников on 17.05.2025.
//Написать программу подсчитывающая количество битов, выставленных в единицу у числа типа long и double. Сами значения чисел вводятся с клавиатуры.

#include <stdio.h>

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

void print_binary_long(long num) {
    unsigned long mask = 1UL << (sizeof(long) * 8 - 1);
    printf("Двоичное представление long: ");
    for (int i = 0; i < sizeof(long) * 8; i++) {
        printf("%d", (num & mask) ? 1 : 0);
        mask >>= 1;
        if ((i + 1) % 8 == 0) printf(" ");     }
    printf("\n");
}

void print_binary_double(double num) {
    unsigned char *ptr = (unsigned char*)&num;
    printf("Двоичное представление double: ");
    for (int i = (int)sizeof(double) - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (ptr[i] & (1 << j)) ? 1 : 0);
        }
        printf(" ");
    }
    printf("\n");
}

int main(void) {
    long lnum;
    double dnum;

    printf("Введите число типа long: ");
    scanf("%ld", &lnum);

    printf("Введите число типа double: ");
    scanf("%lf", &dnum);

    print_binary_long(lnum);
    print_binary_double(dnum);

    int bits_long = count_bits_long(lnum);
    int bits_double = count_bits_double(dnum);

    printf("Количество битов, установленных в 1 в числе long: %d\n", bits_long);
    printf("Количество битов, установленных в 1 в числе double: %d\n", bits_double);

    return 0;
}



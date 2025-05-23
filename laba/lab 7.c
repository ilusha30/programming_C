//
//  lab 7.c
//  C labs
//
//  Created by Илья Овсянников on 22.05.2025.
//Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов типа humen. Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по го-дам рождения. Вывести результат.

#include <stdio.h>
#include <string.h>

#define SIZE 4

typedef struct {
    char name[50];
    char surname[50];
    int birth_year;
} humen;

void input_humen(humen arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Введите имя человека %d: ", i + 1);
        scanf("%49s", arr[i].name);
        printf("Введите фамилию человека %d: ", i + 1);
        scanf("%49s", arr[i].surname);
        printf("Введите год рождения человека %d: ", i + 1);
        scanf("%d", &arr[i].birth_year);
    }
}


void sort_by_birth_year(humen src[], humen dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    for (int i = 1; i < n; i++) {
        humen key = dest[i];
        int j = i - 1;
        while (j >= 0 && dest[j].birth_year > key.birth_year) {
            dest[j + 1] = dest[j];
            j--;
        }
        dest[j + 1] = key;
    }
}

void print_humen(humen arr[], int n) {
    printf("\nОтсортированный список по году рождения:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s, год рождения: %d\n", arr[i].name, arr[i].surname, arr[i].birth_year);
    }
}

int main(void) {
    humen array1[SIZE];
    humen array2[SIZE];

    input_humen(array1, SIZE);

    sort_by_birth_year(array1, array2, SIZE);

    print_humen(array2, SIZE);

    return 0;
}

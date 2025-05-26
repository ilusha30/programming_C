//
//  lab 7.c
//  C labs
//
//  Created by Илья Овсянников on 22.05.2025.
//Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов типа humen. Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения. Вывести результат.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 9

typedef struct {
    char name[50];
    char surname[50];
    int birth_year;
} humen;

void read_from_file(humen arr[], int n, const char* filename) {
    FILE* file = fopen("/Users/ilaovsannikov/прог-е/C labs/C labs/input.txt", "r");
    
    for (int i = 0; i < n; i++) {
            fscanf(file, "%49s %49s %d", arr[i].name, arr[i].surname, &arr[i].birth_year);
        }
        fclose(file);
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
    
    read_from_file(array1, SIZE, "/Users/ilaovsannikov/прог-е/C labs/C labs/input.txt");
    sort_by_birth_year(array1, array2, SIZE);
    print_humen(array2, SIZE);
    
    return 0;
}

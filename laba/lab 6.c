//
//  lab 6.c
//  C labs
//
//  Created by Илья Овсянников on 17.05.2025.
/*Создать текстовый файл с записями следующего вида:
Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1987
Воробьянинов Ипполит Матвеевич 1978

Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *inputFile, *outputFile;
    char lastName[50], firstName[50], middleName[50];
    int year;

    inputFile = fopen("/Users/ilaovsannikov/прог-е/C labs/C labs/input.txt", "r");
    outputFile = fopen("/Users/ilaovsannikov/прог-е/C labs/C labs/output.txt", "w");

    while (fscanf(inputFile, "%49s %49s %49s %d", lastName, firstName, middleName, &year) == 4) {
        if ((unsigned char)firstName[0] == 0xD0 && (unsigned char)firstName[1] == 0x90){
            fprintf(outputFile, "%s %s %s %d\n", lastName, firstName, middleName, year);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Фильтрация завершена. Результаты записаны\n");
    return 0;
}


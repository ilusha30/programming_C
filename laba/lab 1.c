//
//  lab 1.c
//  C labs
//
//  Created by Илья Овсянников on 19.04.2025.
//
/*Объявить вещественные переменные a, b и с и задать их значения. Предполагая, что a, b, c есть коэффициенты квадратного уравнения вывести на консоль значения их кор-ней х1, х2. Следует подобрать такие значения коэффициентов, при которых корни бу-дут существовать.
Примечание. Для выполнения задания потребуется функции вычисления квад-ратного корня (возведение в степень), а так же вывод данных на консоль.
Возведение в степень - подключаем заголовочный файл     math.h и исполь-зуем функцию pow, первым параметром которого должен быть возводимое значение, а вторым - степень, тип данных double. Вывод данных - заголовочный файл stdio.h, функция printf, первым параметром является форматная строка, а последующие - переменные, значения которых необхо-димо вывести.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    double a,b,c;
    double x1, x2, d;
    
    while (1) {
        printf("VVEDITE a:\n");
        scanf("%lf",&a);
        printf("VVEDITE b:\n");
        scanf("%lf",&b);
        printf("VVEDITE c:\n");
        scanf("%lf",&c);
        
        d =  pow(b,2) - 4*a*c;
        printf("d=%1f\n", d);
        
        if (d<0) printf("Kornei net");
        if (d>0) {
            
            x1 = (-b + sqrt(d))/(2*a);
            x2 = (-b - sqrt(d))/(2*a);
            printf("x1 = %lf\n", x1);
            printf("x2 = %lf\n", x2);
        }
        if (d==0){
            x1 = (-b + sqrt(d))/(2*a);
            printf("odin koren x1 = %lf\n", x1);
        }
    }return 0;
    }


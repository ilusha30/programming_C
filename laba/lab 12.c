//
//  lab 12.c
//  C labs
//
//  Created by Илья Овсянников on 19.05.2025.
/*Написать программу-календарь. Пользователь может указать даты в формате:
- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате;
- гггг.мм – программа выводит календарь за данный месяц;
- гггг – календарь за год;
- now – текущую дату.*/


#include <stdio.h>
#include <string.h>
#include <time.h>

const char *weekdays[] = {"Вс", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб"};
const int days_in_months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int is_leap(int y) {
    return (y%400==0) || (y%4==0 && y%100!=0);
}

int days_in_month(int y, int m) {
    if (m == 2) return days_in_months[1] + is_leap(y);
    return days_in_months[m-1];
}

int day_of_week(int y, int m, int d) {
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (d + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return (h + 6) % 7;
}

void print_month(int y, int m) {
    printf("\n  %d.%02d\n", y, m);
    printf("Вс Пн Вт Ср Чт Пт Сб\n");
    int start = day_of_week(y, m, 1);
    for (int i=0; i<start; i++) printf("   ");
    int dim = days_in_month(y,m);
    for (int d=1; d<=dim; d++) {
        printf("%2d ", d);
        if ((start + d) % 7 == 0) printf("\n");
    }
    printf("\n");
}

void print_year(int y) {
    for (int m=1; m<=12; m++) {
        print_month(y, m);
    }
}

int main(void) {
    char s[20];
    printf("Введите дату (гггг.мм.дд, гггг.мм, гггг или now): ");
    if (!fgets(s, sizeof(s), stdin)) return 1;
    s[strcspn(s, "\n")] = 0;

    if (strcmp(s, "now") == 0) {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        printf("Сегодня: %04d.%02d.%02d %s\n",
               tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, weekdays[tm->tm_wday]);
        return 0;
    }

    int y=0, m=0, d=0;
    int dots = 0;
    for (int i=0; s[i]; i++) if (s[i]=='.') dots++;

    if (dots == 2) {
        if (sscanf(s, "%d.%d.%d", &y, &m, &d) == 3) {
            if (m<1 || m>12 || d<1 || d>days_in_month(y,m)) {
                printf("Неверная дата\n");
                return 1;
            }
            int w = day_of_week(y,m,d);
            printf("%04d.%02d.%02d - %s\n", y,m,d, weekdays[w]);
        } else {
            printf("Неверный формат\n");
            return 1;
        }
    } else if (dots == 1) {
        if (sscanf(s, "%d.%d", &y, &m) == 2) {
            if (m<1 || m>12) {
                printf("Неверный месяц\n");
                return 1;
            }
            print_month(y,m);
        } else {
            printf("Неверный формат\n");
            return 1;
        }
    } else if (dots == 0) {
        if (sscanf(s, "%d", &y) == 1) {
            print_year(y);
        } else {
            printf("Неверный формат\n");
            return 1;
        }
    } else {
        printf("Неверный формат\n");
        return 1;
    }

    return 0;
}

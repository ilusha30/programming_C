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

int days_in_month(int y, int m) {
    struct tm tm = {0};
    tm.tm_year = y - 1900;
    tm.tm_mon = m;
    tm.tm_mday = 0;
    mktime(&tm);
    return tm.tm_mday;
}

void print_month(int y, int m) {
    printf("\n  %d.%02d\n", y, m);
    printf("Su Mo Tu We Th Fr Sa\n");
    struct tm tm = {0};
    tm.tm_year = y - 1900;
    tm.tm_mon = m - 1;
    tm.tm_mday = 1;
    mktime(&tm);
    int start = tm.tm_wday;
    for (int i = 0; i < start; i++) printf("   ");
    int dim = days_in_month(y, m);
    for (int d = 1; d <= dim; d++) {
        printf("%2d ", d);
        if ((start + d) % 7 == 0) printf("\n");
    }
    printf("\n");
}

void print_year(int y) {
    for (int m = 1; m <= 12; m++)
        print_month(y, m);
}

int main(void) {
    char s[20];
    printf("Введите дату (гггг.мм.дд, гггг.мм, гггг или now): ");
    if (!fgets(s, sizeof(s), stdin)) return 1;
    s[strcspn(s, "\n")] = 0;

    if (strcmp(s, "now") == 0) {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        char buf[32];
        strftime(buf, sizeof(buf), "%A", tm);
        printf("Сегодня: %04d.%02d.%02d %s\n",
               tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, buf);
        return 0;
    }

    int y = 0, m = 0, d = 0;
    int dots = 0;
    for (int i = 0; s[i]; i++) if (s[i] == '.') dots++;

    if (dots == 2) {
        if (sscanf(s, "%d.%d.%d", &y, &m, &d) == 3) {
            if (m < 1 || m > 12 || d < 1) {
                printf("Неверная дата\n");
                return 1;
            }
            struct tm tm = {0};
            tm.tm_year = y - 1900;
            tm.tm_mon = m - 1;
            tm.tm_mday = d;
            if (mktime(&tm) == (time_t)-1) {
                printf("Неверная дата\n");
                return 1;
            }
            tm.tm_year = y - 1900;
            tm.tm_mon = m;
            tm.tm_mday = 0;
            mktime(&tm);
            if (d > tm.tm_mday) {
                printf("Неверная дата\n");
                return 1;
            }
            tm.tm_year = y - 1900;
            tm.tm_mon = m - 1;
            tm.tm_mday = d;
            mktime(&tm);
            char buf[32];
            strftime(buf, sizeof(buf), "%A", &tm);
            printf("%04d.%02d.%02d - %s\n", y, m, d, buf);
        } else {
            printf("Неверный формат\n");
            return 1;
        }
    } else if (dots == 1) {
        if (sscanf(s, "%d.%d", &y, &m) == 2) {
            if (m < 1 || m > 12) {
                printf("Неверный месяц\n");
                return 1;
            }
            print_month(y, m);
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

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int year = 2025;
    int month = 12;
    int day = 2;

    int yearday = day_of_year(year, month, day);
    printf("Day of year: %d\n", yearday);

    int month2 = 0;
    int day2 = 0;
    month_day(year, yearday, &month2, &day2);
    printf("Day of month: %dm, %dd\n", month2, day2);

    day_of_year(30985, 6, 7); // good
    day_of_year(1999, 18, 7); // error
    day_of_year(1999, 7, 65); // error

    month_day(30985, 300, &month2, &day2); // good
    month_day(1005, 0, &month2, &day2); // error
    month_day(800, 800, &month2, &day2); // error

    return 0;
}

int day_of_year(int year, int month, int day) {
    char *daytabp = daytab;

    if (year%4 == 0 && year%100 != 0 || year%400 == 0) {
        daytabp+=13;
    }

    if (month < 1 || month > 12) {
        printf("Error: month out of bounds\n");
        return 0;
    }

    if (day > *(daytabp+=month) || day < 1) {
        printf("Error: day out of bounds\n");
        return 0;
    }
    else {
        daytabp-=month;
    }

    while (--month > 0) {
        day += *++daytabp;
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    char *daytabp = daytab;
    char *daytabpinit = daytab;

    if (year%4 == 0 && year%100 != 0 || year%400 == 0) {
        daytabp+=13;
    }

    if (yearday < 1 || yearday > 365) {
        printf("Error: day out of bounds\n");
        return;
    }

    while (yearday > *daytabp) {
        yearday -= *daytabp++;
    }

    *pmonth = daytabp - daytabpinit;
    *pday = yearday;
}
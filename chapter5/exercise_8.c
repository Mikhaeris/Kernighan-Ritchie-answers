static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int dat_of_year(int year, int month, int day) {
    if (year <= 0  || !(1 <= month && month <= 12) || !(1 <= day && day <= 31)) {
        return -1;
    }

    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (int i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (year <= 0 || !(1 <= yearday && (leap ? yearday <= 366 : yearday <= 365))) {
        return;
    }

    int i;
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}

//
// Created by zww on 8/13/17.
//
/*
 * 如果一个渔夫从2011年1月1日开始每三天打一次渔，两天晒一次网，
 * 编程实现当输入2011年1月1日以后的任意一天，
 * 输出该渔夫是在打渔还是在晒网。
 */

#include <stdio.h>

int is_right_year(int iyear, int imonth, int iday);

int return_days(int iyear, int imonth, int iday);

int main() {
    printf("请输入需要计算的年.月.日,如2011-3-5\n");
    int year, month, day;
    for (;;) {
        scanf("%d.%d.%d", &year, &month, &day);
        if (is_right_year(year, month, day) == 0) {
            break;
        }
    }

    int total_days = return_days(year, month, day);
    int what_doing = total_days % 5;
    if (what_doing >= 1 && what_doing <= 3) {
        printf("今天渔夫在打渔\n");
    } else printf("今天渔夫在晒网\n");
    return 0;
}

int is_right_year(int iyear, int imonth, int iday) {
    int normal_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((iyear % 4 == 0 && iyear % 100 != 0) || iyear % 400 == 0) {
        normal_days[1] = 29;
    }
    if (iyear < 2011) {
        printf("年份错误，请重新输入\n");
        return 1;
    }
    if (imonth >= 13 || imonth <= 0) {
        printf("月份错误，请重新输入\n");
        return 2;
    }
    if (iday > normal_days[imonth - 1]) {
        printf("天数错误，请重新输入\n");
        return 3;
    }
    return 0;
}

int return_days(int iyear, int imonth, int iday) {
    int total_day = 0, circle;
    int normal_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int x = iyear - 1; x >= 2011; x--) {
        total_day += 365;
        if (x % 4 == 0) {
            total_day += 1;
        }
    }
    circle = imonth - 2;
    while (circle >= 0) {
        total_day += normal_days[circle];
        circle--;
    }
    total_day += iday;
    if (((iyear % 4 == 0 && iyear % 100 != 0) || iyear % 400 == 0) && imonth > 2) {
        total_day += 1;
    }
    printf("%d天\n", total_day);
    return total_day;
}
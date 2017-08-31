//
// Created by zww on 8/11/17.
//
/*
 * 编写一个计算天数的程序，用户从键盘中输入年、月、日，在屏幕中输出此日期是该年的第几天。
 */

#include <stdio.h>

int main() {
    printf("请输入需要计算的年-月-日,如2017-3-5\n");
    int year, month, day, is_leap_year = 0, total_day = 0, circle;
    int normal_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (;;) {
        scanf("%d-%d-%d", &year, &month, &day);
        if (month >= 13 || month <= 0) {
            printf("月份错误，请重新输入\n");
            continue;
        }
        if (day > normal_days[month - 1]) {
            printf("天数错误，请重新输入\n");
            continue;
        }
        break;
    }
    circle = month - 2;
    while (circle >= 0) {
        total_day += normal_days[circle];
        circle--;
    }
    total_day += day;
    is_leap_year = (year % 4 == 0) ? 1 : 0;
    if (is_leap_year == 1 && month > 2) { total_day += 1; }
    printf("这一天为%d年的第%d天\n", year, total_day);
    return 0;
}
//
// Created by zww on 8/9/17.
//
/*
 * 阳阳买苹果，每个苹果0.8元，阳阳第一天买两个苹果，第二天开始买前一天的两倍，
 * 直到购买的苹果个数为不超过100的最大值，编程求阳阳每天平均花多少钱？
 * 注意：这里不超过100的最大值有两种理解，一是总数不超过100，二是当天购买的数不超过100。
 * 本程序解释的为第一种。
 */
#include <stdio.h>
double powerd(double x,double y);

int main() {
    double total_day = 1.0, total_apple = 2.0;
    double total_money = 0;
    while ((total_apple+ powerd(2.0, total_day + 1)) < 100) {
        total_day = total_day + 1;
        total_apple = total_apple + powerd(2.0, total_day);
        total_money = total_apple * 0.8;
    }
    printf("一共购买了苹果　%.0f　个\n",total_apple);
    printf("一共药费了　%.1f　元\n",total_money);
    printf("一共购买了　%.0f　天\n",total_day);
    double average_cost = total_money / total_day;
    printf("阳阳平均每天花费的钱数为: %f", average_cost);
    return 0;
}

double powerd(double x, double y) {
    double result = 1;
    while (y > 0) {
        y--;
        result = result * x;
    }
    return result;
}
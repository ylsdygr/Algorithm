//
// Created by zww on 8/8/17.
//
/*
 * 求给定底数的给定次幂
 */
#include <stdio.h>

int main() {
    int base, power, result = 1;
    printf("请输入底数与幂,使用^分隔,如3^5(3的5次幂)\n");
    scanf("%d^%d", &base, &power);
    int count = power;
    while (count > 0) {
        result = result * base;
        count--;
    }
    printf("%d的%d次幂结果为: %d\n", base, power, result);
    int last3 = result % 1000;
    printf("结果的最位是: %d\n", last3);
    return 0;
}
//
// Created by zww on 29/08/2017.
//
/*
 * 歌德巴赫猜想：任一大于2的偶数，都可表示成两个素数之和。
 * 验证100以内的正偶数都能拆分成两个素数之和。
 */
#include <stdio.h>

void calc_goldbach(int in_number);

int get_prime_number(int in_minimal, int in_maximal);

int judge_prime_number(int in_number);

int main() {
    int calc_number = 4;
    for (int i = 1; i < 100; i++) {
        if (i % 2 == 0 && i > 2)
            calc_goldbach(i);
    }
    printf("请输入一个大于2的偶数: ");
    scanf("%d", &calc_number);
    calc_goldbach(calc_number);
    return 0;
}

void calc_goldbach(int in_number) {
    int top = (int) (in_number / 2 + 1);
    for (int i = 1; i < top; i++) {
        i = get_prime_number(i, in_number);
        for (int j = 3; j < in_number; j++) {
            j = get_prime_number(j, in_number);
            if (i + j == in_number) {
                printf("%-2d = %-2d + %-2d  ", in_number, i, j);
            }
        }
    }
    printf("\n");
}

int get_prime_number(int in_minimal, int in_maximal) {
    int i = 0;
    for (i = in_minimal; i < in_maximal; i++) {
        int result = judge_prime_number(i);
        if (result == 1)
            return i;
    }
    return in_maximal;
}

int judge_prime_number(int in_number) {
    if (in_number == 1)
        return -1;
    if (in_number == 3)
        return 1;
    int i = 0, top = (int) (in_number / 2 + 1);
    for (i = 2; i <= top; i++) {
        if (in_number % i == 0)
            return -1;
    }
    return 1;
}
//
// Created by zww on 8/7/17.
//
/*
 * 猴子吃桃子问题，猴子第一天摘下若干桃子，当即吃了一半，还不过瘾，又多吃了一个。
 * 第二天早上又将第一天剩下的桃子吃掉了一半，又多吃了一个。
 * 以后每天早上都吃了前一天剩下的一半零一个。
 * 到第10天早上想再吃时，发现只剩下一个桃子了。编写程序求猴子第一天共摘了多少个桃子。
 */
#include <stdio.h>

int main() {
    int total = 1, total_day = 10;
    while (total_day > 1) {
        total = (total + 1) * 2;
        total_day--;
    }
    printf("桃子的总数为: %d\n", total);
    return 0;
}
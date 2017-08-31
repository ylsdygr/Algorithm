//
// Created by zww on 27/07/17.
//
/*
 * 求给定正整数的阶乘
 */
#include <stdio.h>

int main(){
    int num = 5;
    double result = 1;
    while(num != 0){
        result = result * num;
        num -= 1;
    }
    printf("%d 的阶乘是: %.0f",num,result);
    return 0;
}
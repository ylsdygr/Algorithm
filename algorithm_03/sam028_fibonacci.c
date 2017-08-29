//
// Created by zww on 29/08/2017.
//
/*
 * 斐波那契数列
 */
#include <stdio.h>

void print_fibonacci(int in_number);

int main() {
    int input_number = 0;
    printf("请输入你想计算数列的最后一个值\n");
    scanf("%d", &input_number);
    print_fibonacci(input_number);
    return 0;
}

void print_fibonacci(int in_number) {
    if (in_number < 1) {
        printf("输入的数字不正确!\n");
        return;
    }
    if (in_number == 1) {
        printf("%-6d ",1);
    }
    if (in_number == 2) {
        printf("%-6d ",1);
    }
    printf("%-6d %-6d ",1,1);
    int fibonacci_1 = 1;
    int fibonacci_2 = 1;
    int fibonacci_3 = 0;
    for (int i = 3; i <= in_number; i++) {
        fibonacci_3 = fibonacci_1 + fibonacci_2;
        fibonacci_1 = fibonacci_2;
        fibonacci_2 = fibonacci_3;
        printf("%-6d ", fibonacci_3);
        if(i % 5 == 0){
            printf("\n");
        }
    }
}

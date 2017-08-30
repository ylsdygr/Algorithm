//
// Created by zww on 29/08/2017.
//
/*
 * 尼科马库斯定理/尼科梅彻斯定理
 * 任何一个整数的立方都可以写成一串相邻奇数之和(如果不是一串相邻的奇数，这个奇数组合可能会有多个)。
 */

#include <stdio.h>
#include <math.h>

int main() {
    int calc_number = 1;
    int current_sum = 0;
    printf("请输入任意一个整数: 　");
    scanf("%d", &calc_number);
    if (calc_number == 1) {
        printf("1 已经是最小的奇数，无法计算\n");
        return 0;
    }
    int cubic_number = pow(calc_number, 3);
    int start_point = -1;
    for (int i = 1; i < cubic_number; i += 2) {
        current_sum += i;
        if (current_sum == cubic_number) {
            printf("%-3d* %-3d* %-3d= %-3d = ", calc_number, calc_number, calc_number, cubic_number);
            for (int k = 1; k <= i; k += 2) {
                printf("%-3d", k);
                if (k + 2 <= i) {
                    printf(" + ");
                }
            }
            break;
        }
        if (current_sum > cubic_number) {
            for (int j = start_point + 2; j < i; j += 2) {
                current_sum = current_sum - j;
                if (current_sum == cubic_number) {
                    printf("%-3d* %-3d* %-3d= %-3d = ", calc_number, calc_number, calc_number, cubic_number);
                    for (int k = j + 2; k <= i; k += 2) {
                        printf("%-3d", k);
                        if (k + 2 <= i) {
                            printf(" + ");
                        }
                    }
                    return 0;
                }
                if (current_sum < cubic_number) {
                    start_point = j;
                    break;
                }
            }
        }
    }
    return 0;
}
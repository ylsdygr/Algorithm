//
// Created by zww on 24/08/2017.
//
/*
 * 冒泡排序
 */

#include <stdio.h>

int main() {
//9 8 1 66 18 34 7 3 10 5
    printf("请输入 10 个数字，以空格为间隔,回车为结束\n");
    int num_arr[10];
    for (int n = 0; n < 10; n++) {
        scanf("%d", &num_arr[n]);
    }
    printf("待排序数组为: ");
    for (int n = 0; n < 10; n++) {
        printf("%-3d", num_arr[n]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        int sorted = 0, moved = 0, moved_pos = 0;
        for (int j = i; j > 0; j--) {
            if (num_arr[j] < num_arr[j - 1]) {
                int temp = num_arr[j];
                moved = temp;
                num_arr[j] = num_arr[j - 1];
                num_arr[j - 1] = temp;
                moved_pos = j - 1;
                sorted = 1;
            }
        }
        if (sorted == 1) {
            printf("当前序列为：");
            for (int n = 0; n < 10; n++) {
                printf("%-3d", num_arr[n]);
            }
            printf(" --此次排序将　%-3d 冒泡至位置 %-3d\n", moved, moved_pos);
        }
    }
    printf("排序完成，数组为: ");
    for (int n = 0; n < 10; n++) {
        printf("%-3d", num_arr[n]);
    }
    return 0;
}
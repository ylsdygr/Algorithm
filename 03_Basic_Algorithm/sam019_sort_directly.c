//
// Created by zww on 8/13/17.
//
/*
 * 直接插入法
 * 插入排序法是把一个记录插入到已排序的有序序列中，使整个序列在插入该记录后仍然有序。
 * 第一次从R[0]~R[n-1]中选取最小值，与R[0]交换，第二次从R[1]~R[n-1]中选取最小值，
 * 与R[1]交换，....，第i次从R[i-1]~R[n-1]中选取最小值，与R[i-1]交换，.....，
 * 第n-1次从R[n-2]~R[n-1]中选取最小值，与R[n-2]交换，
 * 总共通过n-1次，得到一个按排序码从小到大排列的有序序列
 */

#include <stdio.h>

int main() {
    int mount = 0;
    int sort[10];
    printf("请输入 10 个整形数\n");
    while (mount < 10) {
        scanf("%d", &sort[mount]);
        mount++;
    }
    printf("待排序数组为:\n");
    int i, j, k, temp = 0;
    for (i = 0; i < sizeof(sort) / sizeof(int); i++) {
        printf("%-3d ", sort[i]);
    }
    printf("\n");
    for (i = 1, j = 0; i < sizeof(sort) / sizeof(int); i++, j++) {
        if (sort[i] < sort[j]) {
            temp = sort[i];
            k = i;
            while (sort[k - 1] > temp) {
                sort[k] = sort[k - 1];
                k--;
            }
            sort[k] = temp;
            printf("当前数组为:");
            for (int n = 0; n < sizeof(sort) / sizeof(int); n++) {
                printf("%-3d ", sort[n]);
            }
            printf("\n");
        }
    }
    printf("排序后数组为:\n");
    for (int i = 0; i < sizeof(sort) / sizeof(int); i++) {
        printf("%-3d ", sort[i]);
    }

    return 0;
}


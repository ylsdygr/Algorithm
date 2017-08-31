//
// Created by zww on 26/08/2017.
//
/*
 * 选择排序
 * 每一次从待排序的数据元素中选出最小（或最大）的一个元素，
 * 存放在序列的起始位置，直到全部待排序的数据元素排完。
 */
//9 8 18 53 2 60 48 4 6 76
#include <stdio.h>

void select_sort(int arr[], int count);

int main() {
    int count = 10, num_arr[count];
    printf("请输入 %d 个数，以空格分隔\n", count);
    for (int n = 0; n < count; n++) {
        scanf("%d", &num_arr[n]);
    }
    printf("待排序数组为: ");
    for (int n = 0; n < count; n++) {
        printf("%-3d", num_arr[n]);
    }
    printf("\n");
    select_sort(num_arr, 10);

    printf("选择排序完成，数组为: ");
    for (int n = 0; n < count; n++) {
        printf("%-3d", num_arr[n]);
    }
    printf("\n");
    return 0;
}

void select_sort(int arr[], int count) {
    int i, j, temp = arr[0], temp_sub = 0;
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (arr[j] < temp) {
                temp = arr[j];
                temp_sub = j;
            }
        }
        if (temp_sub != i) {
            temp = arr[i];
            arr[i] = arr[temp_sub];
            arr[temp_sub] = temp;
        }
        temp = arr[i + 1];
        temp_sub = i + 1;
        printf("当次排序完成，将%3d 放至第%3d 位,", arr[i], i+1);
        printf("数组为: ");
        for (int n = 0; n < count; n++) {
            printf("%-3d", arr[n]);
        }
        printf("\n");
    }
}
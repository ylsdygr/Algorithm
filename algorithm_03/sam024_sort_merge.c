//
// Created by zww on 26/08/2017.
//
/*
 * 归并排序
 */
//2  4  6  8  9  18 48 53 60 76
//1  3  5  7  9  58 62 91 96 99

#include <stdio.h>

void merge_sort(int arr_result[], int count_result, int arr1[], int count1, int arr2[], int count2);

int main() {
    int count = 10,num_arr1[10],num_arr2[10],num_arr_result[count * 2];
    printf("请输入第一个数组 %d 个数，以空格分隔\n", count);
    for (int n = 0; n < count; n++) {
        scanf("%d", &num_arr1[n]);
    }
    printf("请输入第二个数组 %d 个数，以空格分隔\n", count);
    for (int n = 0; n < count; n++) {
        scanf("%d", &num_arr2[n]);
    }
    printf("待排序数组1为: ");
    for (int n = 0; n < count; n++) {
        printf("%-3d", num_arr1[n]);
    }
    printf("\n");
    printf("待排序数组2为: ");
    for (int n = 0; n < count; n++) {
        printf("%-3d", num_arr2[n]);
    }
    printf("\n");

    merge_sort(num_arr_result, 20, num_arr1, 10, num_arr2, 10);
    printf("排序结束，结果数组为: ");
    for (int n = 0; n < count * 2; n++) {
        printf("%-3d", num_arr_result[n]);
    }
    printf("\n");
    return 0;
}

void merge_sort(int arr_result[], int count_result, int arr1[], int count1, int arr2[], int count2) {
    int i = 0, j = 0, k = 0, temp = 0;
    //判断下count1,count2的合法性
    //else if (count2 > 0) { temp = arr2[0]; }
    //else return;
    if (count_result < count1 + count2) { return; }

    while (j < count1 || k < count2) {
        if (j == count1) {
            temp = arr2[k];
            k++;
            printf("单次合并结束，将数组 2 的第 %3d 位排至新数组中\n", k);
        } else if (k == count2) {
            temp = arr1[j];
            j++;
            printf("单次合并结束，将数组 1 的第 %3d 位排至新数组中\n", j);
        } else if (arr2[k] <= arr1[j]) {
            temp = arr2[k];
            k++;
            printf("单次合并结束，将数组 2 的第 %3d 位排至新数组中\n", k);
        } else {
            temp = arr1[j];
            j++;
            printf("单次合并结束，将数组 1 的第 %3d 位排至新数组中\n", j);
        }
        arr_result[i] = temp;
        i++;
    }
}
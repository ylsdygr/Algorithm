//
// Created by zww on 25/08/2017.
//
/*
 * 快速排序
 */
#include <stdio.h>

void fast_sort(int arr[], int start, int end);

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
    fast_sort(num_arr, 0, 9);

    printf("快速排序完成，结果数组为: ");
    for (int n = 0; n < 10; n++) {
        printf("%-3d", num_arr[n]);
    }
    printf("\n");
    return 0;
}

//9 8 18 53 2 60 48 4 6 76

void fast_sort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int i = start, j = end, key = start, temp = 0;
    while (i < j) {
        while (i < j && arr[j] >= arr[key]) {
            j--;
        }
        temp = arr[j];
        arr[j] = arr[key];
        arr[key] = temp;
        key = j;
        while (i < j && arr[i] <= arr[key]) {
            i++;
        }
        temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
        key = i;
    }
    printf("本次快速排序完成，结果数组为: ");
    for (int n = 0; n < 10; n++) {
        printf("%-3d", arr[n]);
    }
    printf(" 本次排序选定的key值为%-3d\n", arr[key]);
    if (start < i)
        fast_sort(arr, start, key - 1);
    if (i < end)
        fast_sort(arr, key + 1, end);
}
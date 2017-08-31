//
// Created by zww on 26/08/2017.
//
/*
 * 二分查找
 * 二分查找的基本思想是将n个元素分成大致相等的两部分，取a[n/2]与x做比较，
 * 如果x=a[n/2],则找到x,算法中止；如果x<a[n/2],则只要在数组a的左半部分继续搜索x,
 * 如果x>a[n/2],则只要在数组a的右半部搜索x.
 */
#include <stdio.h>

void binary_search(int arr[], int count, int number, int in_result[]);

int main() {
    int num_arr[] = {3, 5, 6, 8, 9, 11, 15, 18, 48, 53, 58, 60, 62, 76, 91, 96, 99}, find_number;
    printf("请输入你想要查找的数: \n");
    scanf("%d", &find_number);
    int result[2] = {0, 0};
    binary_search(num_arr, 17, find_number, result);
    if (result[0] == -1)
        printf("未查找到结果,查找了 %2d 次\n", result[1]);
    else {
        printf("已查找到结果，为数组第 %2d 个元素,查找了%2d 次 \n", result[0] + 1, result[1]);
    }
    return 0;
}

void binary_search(int arr[], int count, int number, int in_result[]) {
    int find_count = 0;
    int low = 0, high = count - 1;
    while (low < high) {
        find_count++;
        int mid = (int) (low + high) / 2;
        if (number == arr[mid]) {
            in_result[0] = mid;
            in_result[1] = find_count;
            return;
        }
        if (number < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    in_result[0] = -1;
    in_result[1] = find_count;
    return;
}
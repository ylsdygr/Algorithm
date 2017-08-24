//
// Created by zww on 8/13/17.
//
/*
 * 希尔排序
 */
#include <stdio.h>

void hash_sort(int arr[10], int count);

int main() {
    int mount = 0;
    int sort[10];
    printf("请输入 10 个整形数\n");
    while (mount < 10) {
        scanf("%d", &sort[mount]);
        mount++;
    }
    printf("待排序数组为:\n");
    int n;
    for (n = 0; n < 10; n++) {
        printf("%-3d ", sort[n]);
    }
    printf("\n");
    hash_sort(sort, 10);
    printf("排序后数组为:\n");
    for (n = 0; n < 10; n++) {
        printf("%-3d ", sort[n]);
    }
    return 0;
}

//4(0)   5(1)   2(2)   19(3)  8(4)   7(5)   10(6)  4(7)   3(8)   9(9)
//4 5 2 19 8 7 10 4 3 9
void hash_sort(int arr[10], int count) {
    int i, j, k, temp = 0, skip = (int) (count / 2);
    while (skip >= 1) {
        printf("当前跳数为: %-3d \n",skip);
        for (i = 0, j = skip; i < count && j < count; i++, j++) {
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                k = i;
                while (k - skip > 0 && arr[k - skip] > temp) {
                    arr[k] = arr[k - skip];
                        k -= skip;
                }
                arr[k] = temp;
                printf("当前数组为:");
                for (int n = 0; n < count; n++) {
                    printf("%-3d ", arr[n]);
                }
                printf("本次调整了　%-3d",arr[k]);
                printf("\n");
            }
        }
        skip = (int) (skip / 2);
        printf("跳数已更改，当前跳数为: %-3d \n",skip);
    }
}
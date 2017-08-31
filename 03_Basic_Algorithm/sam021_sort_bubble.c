//
// Created by zww on 24/08/2017.
//
/*
 * 冒泡排序
 * 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
 * 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
 * 针对所有的元素重复以上的步骤，除了最后一个。
 * 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
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
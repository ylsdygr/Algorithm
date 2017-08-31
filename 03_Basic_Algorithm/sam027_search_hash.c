//
// Created by zww on 26/08/2017.
//
/*
 * 哈希查找
 * 通过计算数据元素的存储地址进行查找的一种方法。
 * 用给定的哈希函数构造哈希表；
 * 根据选择的冲突处理方法解决地址冲突；
 * 在哈希表的基础上执行哈希查找
 */
#include <stdio.h>
#include <memory.h>

void calc_hash_table(int in_hash_array[][11], int in_hash_number, int ori_array[], int arr_count);

int hash_search(int in_hash_array[][11], int in_find_number, int in_hash_number, int in_num_arr[]);

int main() {
    int num_arr[20] = {3, 5, 6, 8, 9, 11, 13, 15, 18, 36, 48, 53, 58, 60, 62, 76, 83, 91, 96, 99}, find_number;
    int hash_number = 11;
    int hash_array[11][11] = {};
    memset(hash_array, -1, sizeof(hash_array));
    calc_hash_table(hash_array, hash_number, num_arr, 20);
/*  //输出当前的哈希表内容
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (j % 5 == 0) { printf("\n"); }
            printf("%d  ", hash_array[i][j]);
        }
    }
*/
    printf("初始化完成请输入你想要查找的数: \n");
    scanf("%d", &find_number);
    int result = hash_search(hash_array, find_number, hash_number, num_arr);
    if (result == -1) {
        printf("未查找到结果\n");
    } else {
        printf("查找到结果，位置为原数组的第 %3d 个位置,值为 %3d \n", result, num_arr[result]);
    }
    return 0;
}

void calc_hash_table(int in_hash_array[][11], int in_hash_number, int ori_array[], int in_arr_count) {
    for (int i = 0; i < in_arr_count; i++) {
        int remainder = ori_array[i] % in_hash_number;
        for (int j = 0; j < in_hash_number; j++) {
            if (in_hash_array[remainder][j] == -1) {
                in_hash_array[remainder][j] = i;
                break;
            }
        }
    }

}

int hash_search(int in_hash_array[][11], int in_find_number, int in_hash_number, int in_num_arr[]) {
    int remainder = in_find_number % in_hash_number;
    for (int i = 0; i < 11; i++) {
        if (in_num_arr[in_hash_array[remainder][i]] == in_find_number) {
            return in_hash_array[remainder][i];
        }
    }
    return -1;
}
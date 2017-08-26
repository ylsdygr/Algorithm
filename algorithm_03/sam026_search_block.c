//
// Created by zww on 26/08/2017.
//
/*
 * 分块查找
 */
//3 6 2 4 5  9 7 10 9 12  16 18 17 13 15  23 87 78 32 66
#include <stdio.h>

typedef struct index {
    int value;
    int start;
    int end;
} index;

void struct_assign(index in_table[], int in_count, int in_array[], int arr_count);
void block_search(index in_table[], int in_count, int in_array[], int arr_count, int in_find_number);

int main() {
    index index_table[4];
    int array[20], count = 20, find_number;
    printf("请输入20个数字，以空格分隔，每5个为一组，前一组中最大的数应比后一组最小的数小\n");
    for (int i = 0; i < count; i++) {
        scanf("%d", &array[i]);
    }
    struct_assign(index_table, 4, array, 20);
    printf("分析已完成，请输入想要查找的数： ");
    scanf("%d", &find_number);
    block_search(index_table,4,array,20,find_number);
    return 0;
}

void struct_assign(index in_table[], int in_count, int in_array[], int arr_count) {
    int count_in_every = arr_count / in_count;
    int sub_calc = 0;
    for (int i = 0; i < in_count; i++) {
        in_table[i].start = sub_calc;
        in_table[i].end = sub_calc + count_in_every - 1;
        int max_value = in_array[sub_calc];
        for (int j = sub_calc; j < sub_calc + count_in_every; j++) {
            if (in_array[j] > max_value)
                max_value = in_array[j];
        }
        in_table[i].value = max_value;
        sub_calc += 5;
    }
}

void block_search(index in_table[], int in_count, int in_array[], int arr_count, int in_find_number) {
    int in_block = 0;
    for (int i = 0; i < in_count; i++) {
        if (in_find_number <= in_table[i].value) {
            in_block = i;
            break;
        } else {
            continue;
        }
    }
    for (int i = in_table[in_block].start; i < in_table[in_block].end; i++) {
        if (in_find_number == in_array[i]) {
            printf("元素已查到，位于第%3d块内，原数组第%3d个元素\n", in_block + 1, i + 1);
            return ;
        }
    }
    printf("原数组中无此元素\n");
}
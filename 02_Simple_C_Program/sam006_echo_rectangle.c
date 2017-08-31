//
// Created by zww on 27/07/17.
//
/*
 * 输出正方形
 */
#include <stdio.h>

int main() {
    printf("*************\n");
    printf("*           *\n");
    printf("*           *\n");
    printf("*************\n");
    printf("\n");

    int columns = 20, rows = 5, isheadortail = 1;
    for (int i = 1; i <= rows; i++) {
        if (isheadortail == 1) {
            for (int j = 1; j <= columns; j++) {
                printf("*");
            }
        } else {
            printf("*");
            for (int j = 1; j < columns - 1; j++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
        if (i == rows - 1)
            isheadortail = 1;
        else
            isheadortail = 0;
    }
    return 0;
}

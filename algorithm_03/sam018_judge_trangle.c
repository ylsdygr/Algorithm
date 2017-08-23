//
// Created by zww on 8/13/17.
//
/*
 * 根据输入的三角形的三条边判断三角形的类型，并输出它的面积和类型。
 * 提示：首先判断所给的三条边是否能组成三角形，若可以构成三角形，
 * 则判断该三角形是什么类型，并求三角形的面积。
 */

#include <stdio.h>
#include <math.h>

int is_triangle(float a, float b, float c);

double calc_area(float a, float b, float c);

int what_triangle(float a, float b, float c);

int main() {
    printf("请输入三角形的三条边长,以','分隔.如3,4,5\n");
    float line1, line2, line3;
    for (;;) {
        scanf("%f,%f,%f", &line1, &line2, &line3);
        if (is_triangle(line1, line2, line3) != 0)
            continue;
        else { break; }
    }
    if (line1 > line2) {
        float temp = line1;
        line1 = line2;
        line2 = temp;
    }
    if (line2 > line3) {
        float temp = line2;
        line2 = line3;
        line3 = temp;
    }
    what_triangle(line1, line2, line3);
    printf("三角形三边长分别为: %.0f,%.0f,%.0f\n", line1, line2, line3);
    printf("三角形的面积为: %f\n", calc_area(line1, line2, line3));
    return 0;
}

int is_triangle(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("错误1,您输入的三边无法构成三角形!请重新输入.\n");
        return 1;
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("错误2,您输入的三边无法构成三角形!请重新输入.\n");
        return 2;
    }
    return 0;
}

int what_triangle(float a, float b, float c) {
    if (a * a + b * b == c * c) {
        printf("当前判断三角形为直角三角形\n");
        return 1;//直角三角形
    } else if (a * a + b * b >= c * c) {
        printf("当前判断三角形为锐角三角形\n");
        return 2;//锐角三角形
    } else {
        printf("当前判断三角形为钝角三角形\n");
        return 3;//钝角三角形
    }
}

double calc_area(float a, float b, float c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
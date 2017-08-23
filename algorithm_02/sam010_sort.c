//
// Created by zww on 8/7/17.
//
/*
 * 三个数由小到大排序
 */
#include <stdio.h>

int main(){
    float a,b,c ;
    printf("Please input a,b,c\n");
    scanf("%f%f%f",&a,&b,&c);
    if(a > b ){
        int t = a;
        a = b;
        b = t;
    }
    if(a > c){
        int t = a;
        a = c;
        c = t;
    }
    if(b > c){
        int t = b;
        b = c;
        c = t;
    }
    printf("三个数从小到大排序结果为： %.0f,%.0f,%.0f",a,b,c);
    return 0;
}
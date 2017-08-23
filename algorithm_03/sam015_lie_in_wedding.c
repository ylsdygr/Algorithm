//
// Created by zww on 8/12/17.
//
/*
 * 3对情况参加婚礼，3个新郎为A，B，C，3个新娘为X，Y，Z，有人想知道究竟谁与谁结婚，
 * 于是就问新人中的三位，下结果:
 * A说他将和X，X说他的未婚夫是C；C说他将和Z结婚。这人事后知道他们在开玩笑，说的全是假话。
 * 那么，究竟谁与谁结婚呢？
 */

#include <stdio.h>

char give_wife(int num);

int main() {
    int a, b, c;
    int x = 1, y = 2, z = 3;
    for (a = 1; a <= 3; a++) {
        for (b = 1; b <= 3; b++) {
            for (c = 1; c <= 3; c++) {
                if (a != 1 && c != 1 && c != 3 && a != c && a != b && b != c) {
                    printf("a的妻子为：%c\n", 'a' + 23 + a - 1);
                    //'a'+23是将字母a转为x，+a是根据上一步算出a中的1,2,3.
                    // 再减1是为了可能保证.x可以等于a的
                    printf("b的妻子为：%c\n", 'a' + 23 + b - 1);
                    printf("c的妻子为：%c\n", give_wife(c));
                }
            }
        }

    }
    if (a == 3)
        printf("没有合适的结果\n");
    //printf("%d",'x' - 'a');
    return 0;
}

char give_wife(int num) {
    switch (num) {
        case 1:
            return 'x';
        case 2:
            return 'y';
        case 3:
            return 'z';
        default:
            return '0';
    }
}
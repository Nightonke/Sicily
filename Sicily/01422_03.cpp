// Problem#: 1422
// Submission#: 2770309
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n, m, lcm, hit_horizontal_size, hit_vertical_size;
    while (~scanf("%d%d", &m, &n)) {
        lcm = n * m / gcd(n, m);
        hit_horizontal_size = lcm / m - 1;
        hit_vertical_size = lcm / n - 1;
        //1 & 1 = 1, 0 & 1 = 0
        if (hit_horizontal_size & 1) {//如果撞击水平边的次数是奇数次，那么可能的点是AD
            if (hit_vertical_size & 1) {//如果撞击竖直边的次数是奇数次，那么可能的点是AB
                printf("A ");
            } else {
                printf("D ");
            }
        } else {
            if (hit_vertical_size & 1) {
                printf("B ");
            } else {
                printf("C ");
            }
        }
        printf("%d\n", hit_horizontal_size + hit_vertical_size);
    }
    return 0;
}                                 
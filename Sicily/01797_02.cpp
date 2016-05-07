// Problem#: 1797
// Submission#: 2807552
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int x, y;
bool dir_x, dir_y;

int gcd(int a, int b) {
    int temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void gogogo(int a, int b) {
    if (dir_x == 0 && dir_y == 0) {
        y++;
    } else if (dir_x == 0 && dir_y == 1) {
        x++;
    } else if (dir_x == 1 && dir_y == 0) {
        y--;
    } else {
        x--;
    }
    if (a - b > 0 && b > 0) {
        gogogo(a - b, b);
    }
    if (dir_y) {
        dir_x ^= 1;
        dir_y ^= 1;
    } else {
        dir_y ^= 1;
    }
    if (b - a > 0 && a > 0) {
        gogogo(b - a, a);
    }
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 || b == 0) {
            printf("0 0\n");
            continue;
        }
        int temp = gcd(a, b);
        a /= temp;
        b /= temp;
        x = y = dir_x = dir_y = 0;
        gogogo(a, b);
        printf("%d %d\n", x, y);
    }
    return 0;
}                                 
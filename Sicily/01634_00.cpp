// Problem#: 1634
// Submission#: 2498445
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a, b, down, mul1, mul2, i;
    while (scanf("%d %d", &a, &b), a != -1) {
        if (a == 0 && b == 0) {
            printf("%d+%d!=%d\n", a, b, a + b);
            continue;
        }
        if (a == 0 && b != 0) {
            if (b == 1)
                printf("%d+%d=%d\n", a, b, a + b);
            else
                printf("%d+%d!=%d\n", a, b, a + b);
            continue;
        }
        if (a != 0 && b == 0) {
            if (a == 1)
                printf("%d+%d=%d\n", a, b, a + b);
            else
                printf("%d+%d!=%d\n", a, b, a + b);
            continue;
        }
        down = a + b;
        mul1 = mul2 = 1;
        for (i = 0; i < b; i++) {
            mul1 = down * mul1;
            down--;
        }
        for (i = b; i >= 1; i--) {
            mul2 = mul2 * i;
        }
        if (mul1 / mul2 != a + b)
            printf("%d+%d!=%d\n", a, b, a + b);
        else
            printf("%d+%d=%d\n", a, b, a + b);
    }
    return 0;
}                                 
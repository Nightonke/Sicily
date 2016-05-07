// Problem#: 1723
// Submission#: 2510014
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int result (int a, int b) {
    int zj;
    if (a < b) {
        zj = a;
        a = b;
        b = zj;
    }
    if (a % b == 0)
        return b;
    else
        return result(b, a % b);
}
int main() {
    int a, b;
    while (scanf("%d %d", &a, &b), a != 0 && b != 0) {
        if (a * b == 0)
            printf("0\n");
        else
            printf("%d\n", result(a, b));
    }
    return 0;
}                                 
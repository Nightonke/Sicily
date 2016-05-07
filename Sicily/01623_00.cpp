// Problem#: 1623
// Submission#: 2442519
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, a, b, a1, b1, zj, counter = 1;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        a1 = a;
        b1 = b;
        if (a < b) {
            zj = b;
            b = a;
            a = zj;
        }
        while (a % b != 0) {
            zj = b;
            b = a % b;
            a = zj;
        }
        printf("%d %d %d\n", counter, a1 * b1 / b, b);
        counter++;
    }
    return 0;
}                                 
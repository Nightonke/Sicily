// Problem#: 7769
// Submission#: 2522197
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, a[10001], kongzhi, j, n2, i;
    while (scanf("%d", &n), n) {
        memset(a, 0, sizeof(a));
        a[0] = n;
        kongzhi = 1;
        for (j = 1; kongzhi; j++) {
            n2 = n * n;
            n2 = n2 / 100;
            n = n2 % 10000;
            a[j] = n;
            for (i = 0; i < j; i++) {
                if (a[i] == a[j])
                    kongzhi = 0;
            }
        }
        printf("%d\n", j - 1);
    }
    return 0;
}                                 
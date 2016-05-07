// Problem#: 6084
// Submission#: 2652522
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int c[10001] = {0}, i, j, k, la, lb = 5, a[10001], b[6] = {1, 0, 0, 0, 1};
    char aa[10001];
    scanf("%s", aa);
    la = strlen(aa);
    for (i = 0; i < la; i++) {
        a[i] = aa[la - 1 - i] - '0';
    }
    for (i = 0; i < la; i++) {
        for (j = 0; j < lb; j++) {
            c[i + j] = a[i] * b[j] + c[i + j];
            c[i + j + 1] = c[i + j] / 2 + c[i + j + 1];
            c[i + j] %= 2;
        }
    }
    for (k = 10000; c[k] == 0 && k > 0; k--);
    for (i = k; i >= 0; i--) {
        printf("%d", c[i]);
    }
    printf("\n");
    return 0;
}                                 
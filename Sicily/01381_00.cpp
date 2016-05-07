// Problem#: 1381
// Submission#: 2435640
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char a[200] = {0}, c[300] = {0}, a1[200] = {0}, b1[200] = {0};
    int long1, i, j = 0, m, n;
    scanf("%d", &n);
    while (n--) {
    scanf("%s %d", a, &m);
    long1 = strlen(a);
    if (m != 0) {
        for (i = long1 - 1; i >= 0; i--) {
        a1[j] = a[i];
        j++;
    }
    for (i = 0; i < long1; i++)
        a1[i] = a1[i] - '0';
    while (m--) {
        for (i = 0; i < long1; i++) {
        c[i] = c[i] + a1[i] + b1[i];
        c[i + 1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    if (c[i] != 0)
        long1++;
    for (j = 0; j < long1; j++) {
        b1[j] = c[j];
        c[j] = 0;
    }
    }
    for (j = long1 - 1; j >= 0; j--) {
        printf("%c", b1[j] + '0');
        b1[j] = 0;
    }
    printf("\n");
    }
    if (m == 0)
        printf("0\n");
    j = 0;
    }
    return 0;
}                                 
// Problem#: 1485
// Submission#: 2592120
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int b[100], a[210][210];
void make() {
    int lb, i, j, k;
    b[0] = 2;
    memset(a, 0, sizeof(a));
    a[1][0] = 4;
    lb = 1;
    for (i = 2; i <= 200; i++) {
        for (j = 0; j < 100; j++) {
            for (k = 0; k < lb; k++) {
                a[i][j + k] = a[i - 1][j] * b[k] + a[i][j + k];
                a[i][j + k + 1] = a[i][j + k] / 10 + a[i][j + k + 1];
                a[i][j + k] = a[i][j + k] % 10;
            }
        }
    }
}

void print(int n) {
    int t1[100] = {0}, t2[100] = {0}, i, k;
    memset(t1, 0, sizeof(t1));
    memset(t2, 0, sizeof(t2));
    t2[0] = 2;
    for (i = 0; i < 100; i++) {
        if (a[n][i] < t2[i]) {
            a[n][i + 1]--;
            a[n][i] += 10;
        }
        t1[i] = a[n][i] - b[i];
    }
    for (k = 99; t1[k] == 0 && k > 0; k--);
    for (; k >= 0; k--) {
        printf("%d", t1[k]);
    }
    printf("\n");
}

int main() {
    int n, kongzhi = 0;
    make();
    while (scanf("%d", &n) == 1) {
        if (kongzhi)
            printf("\n");
        kongzhi = 1;
        print(n);
    }
    return 0;
}                                 
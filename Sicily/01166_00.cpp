// Problem#: 1166
// Submission#: 2583696
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int af[1002][1000] = {0}, a2[1002][1000] = {0};

void make_a2() {
    int i, k;
    for (k = 2; k < 1002; k++) {
        for (i = 0; i < 999; i++) {
            a2[k][i] = a2[k - 1][i] * 2 + a2[k][i];
            a2[k][i + 1] = a2[k][i] / 10 + a2[k][i + 1];
            a2[k][i] %= 10;
        }
    }
}

void make_af() {
    int k, i;
    for (k = 4; k < 1002; k++) {
        for (i = 0; i < 999; i++) {
            af[k][i] += a2[k - 3][i] + af[k - 2][i];
            af[k][i + 1] += af[k][i] / 10;
            af[k][i] %= 10;
        }
    }
}
    
void ready() {
    a2[1][0] = 2;
    make_a2();
    af[1][0] = 0;
    af[2][0] = 1;
    af[3][0] = 1;
    make_af();
}

int main() {
    int i, n, j;
    ready();
    while (scanf("%d", &n) == 1) {
        i = 999;
        while (af[n][i] == 0 && i > 0)
            i--;
        for (j = i; j >= 0; j--)
            printf("%d", af[n][j]);
        printf("\n");
    }
    return 0;
}                                 
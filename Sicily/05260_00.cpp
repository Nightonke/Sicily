// Problem#: 5260
// Submission#: 2651980
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int i, j, k, u, la, lb, kongzhi = 1;
    char a[31], b[31], p[31][31];
    scanf("%s %s", a, b);
    for (i = 0; i < 30 && kongzhi; i++) {
        for (j = 0; j < 30 && kongzhi; j++) {
            if (a[i] == b[j]) {
                kongzhi = 0;
                break;
            }
        }
    }
    i--;
    la = strlen(a);
    lb = strlen(b);
    for (k = 0; k < lb; k++) {
        for (u = 0; u < la; u++) {
            p[k][u] = '.';
        }
    }
    for (k = 0; k < lb; k++) {
        p[k][i] = b[k];
    }
    for (k = 0; k < la; k++) {
        p[j][k] = a[k];
    }
    for (k = 0; k < lb; k++) {
        for (u = 0; u < la; u++) {
            printf("%c", p[k][u]);
        }
        printf("\n");
    }
    return 0;
}                                 
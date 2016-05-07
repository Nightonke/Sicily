// Problem#: 3712
// Submission#: 2371287
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[11][11], b[11][11], c[11][11], n, i, j, k;
    for (i = 0; i < 11; i++)
        for (j = 0; j < 11; j++)
            c[i][j] = 0;
    while (scanf("%d", &n)!=EOF) {
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            printf("%d ", c[i][j]);}
        printf("%d\n", c[i][n - 1]);}
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c[i][j] = 0;
    }
    return 0;
}                                 
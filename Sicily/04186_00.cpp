// Problem#: 4186
// Submission#: 2371187
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[11][11], b[11][11], c[11][11], n, i, j;
    while (1) {
        scanf("%d", &n);
    if (n == 0)
        break;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            printf("%d ", c[i][j]);}
        printf("%d\n", c[i][n - 1]);}}
    return 0;
}                                 
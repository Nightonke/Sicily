// Problem#: 1146
// Submission#: 2457417
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int max(int a, int b) {
    return (a > b ? a : b);
}
int main() {
    int V[110][1100] = {0}, c, n, i, j, w[1100], v[1100];
    scanf("%d %d", &c , &n);
    for (i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &v[i]);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= c; j++)
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
    printf("%d\n", V[n][c]);
    return 0;
}                                 
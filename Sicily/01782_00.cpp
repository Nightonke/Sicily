// Problem#: 1782
// Submission#: 2519956
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int V[1001][10001];
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int t, n, m, v[1001], i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        memset(V, 0, sizeof(V));
        memset(v, 0, sizeof(v));
        for (i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (v[i] > j)
                    V[i][j] = V[i - 1][j];
                else
                    V[i][j] = max(V[i - 1][j], V[i - 1][j - v[i]] + v[i]);
            }
        }
        printf("%d\n", V[n][m]);
    }
    return 0;
}                                 
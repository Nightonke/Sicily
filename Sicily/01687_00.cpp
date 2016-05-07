// Problem#: 1687
// Submission#: 2601021
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, k, i, j, f[110][110];
    while (scanf("%d %d", &n, &k) == 2) {
        if (n == 1 && k == 0) {
            printf("1\n");
            continue;
        }
        if (n == 0) {
            printf("0\n");
            continue;
        }
        memset(f, 0, sizeof(f));
        for (i = 0; i <= n; f[i++][0] = 1);
        for (i = 1; i <= n; i++) {
            for (j = 0; j <= k; j++) {
                if (j - 1 >= 0 && j <= i) {
                    f[i][j] = f[i - 1][j] * (j + 1) + f[i - 1][j - 1] * (i - j);
                }
                if (f[i][j] > 2007)
                    f[i][j] %= 2007;
            }
        }
        printf("%d\n", f[n][k] % 2007);
    }
    return 0;
}                                 
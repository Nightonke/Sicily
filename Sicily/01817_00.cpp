// Problem#: 1817
// Submission#: 2614907
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, m, i, j, min, max, sum, a[101][101];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        for (i = 0; i < m; i++) {
            min = max = a[0][i];
            sum = 0;
            for (j = 0; j < n; j++) {
                sum += a[j][i];
                if (a[j][i] > max)
                    max = a[j][i];
                if (a[j][i] < min)
                    min = a[j][i];
            }
            printf("%.2f\n", (1.0 * sum - max - min) / (n - 2));
        }
    }
    return 0;
}                                 
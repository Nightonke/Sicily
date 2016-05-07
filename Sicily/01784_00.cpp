// Problem#: 1784
// Submission#: 2699837
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, t1, t2, i, j, k;
    float a[110][110], temp;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &t1, &t2);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%f", &temp);
                a[i][j] = 1 - temp;
            }
        }
        for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (a[i][k] * a[k][j] > a[i][j])
                        a[i][j] = a[i][k] * a[k][j];
                }
            }
        }
        printf("%.2f\n", a[t1][t2]);
    }
    return 0;
}                                 
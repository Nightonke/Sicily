// Problem#: 1280
// Submission#: 2796226
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, a[101], b[101], ans[101][101];
    while (scanf("%d", &n) && n) {
        memset(ans, 0, sizeof(ans));
        memset(b, 0, sizeof(b));
        ans[0][0] = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1])
                b[i + 1] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (b[i] == 1) {
                for (int j = 0; j <= i; j++) {
                    for (int k = j + 1; k <= i; k++) {
                        ans[i][k] += ans[i - 1][j];
                    }
                }
            } else {
                for (int j = 0; j <= i; j++) {
                    for (int k = 0; k <= j; k++) {
                        ans[i][k] += ans[i - 1][j];
                    }
                }
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ans[n - 1][i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}                                 
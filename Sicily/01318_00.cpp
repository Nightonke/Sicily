// Problem#: 1318
// Submission#: 2590542
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, xs, ys, x, y, i, j, sum, a[16][16], kongzhi = 0;
    while (scanf("%d", &n) == 1) {
        if (kongzhi)
            printf("\n");
        kongzhi = 1;
        xs = -2;
        ys = n / 2 + 1;
        for (i = 0; i < n; i++) {
            xs += 2;
            if (xs >= n)
                xs -= n;
            ys -= 1;
            if (ys < 0)
                ys += n;
            x = xs;
            y = ys;
            for (j = i * n + 1; j <= (i + 1) * n; j++) {
                a[x][y] = j;
                x--;
                if (x < 0)
                    x += n;
                y++;
                if (y >= n)
                    y -= n;
            }
        }
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[n - i - 1][i];
        }
        printf("n=%d, sum=%d\n", n, sum);
        if (n == 3) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    printf("%2d", a[i][j]);
                }
                printf("\n");
            }
        }
        if (n >= 5 && n <= 9) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    printf("%3d", a[i][j]);
                }
                printf("\n");
            }
        }
        if (n >= 11) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    printf("%4d", a[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}                                 
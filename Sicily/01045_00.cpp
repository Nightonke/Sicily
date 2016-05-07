// Problem#: 1045
// Submission#: 2567302
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int a[2001][1001];
int main() {
    int t, n, i, j, k, counter, x, y, w, h;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x, &y, &w, &h);
            for (j = x; j < x + w; j++) {
                for (k = y; k < y + h; k++) {
                    if (a[j][k] != 1) {
                        a[j][k] = 1;
                    }
                }
            }
        }
        counter = 0;
        for (i = 0; i < 2000; i++) {
            for (j = 0; j < 1000; j++) {
                if (a[i][j] == 1)
                    counter++;  
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 
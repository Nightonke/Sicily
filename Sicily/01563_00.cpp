// Problem#: 1563
// Submission#: 2457152
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int max(int b0, int b1, int b2) {
    int max2;
    max2 = b0;
    if (max2 < b1)
        max2 = b1;
    if (max2 < b2)
        max2 = b2;
    return max2;
}
int main() {
    int h, w, i, j, a[510][510] = {0}, f[510][510] = {0}, max1;
    scanf("%d %d", &h, &w);
    for (i = 0; i < h; i++)
        for (j = 1; j <= w; j++)
            scanf("%d", &a[i][j]);
    for (j = 1; j <= w; j++)
        f[0][j] = a[0][j];
    for (i = 0; i < h; i++)
        for (j = 1; j <= w; j++) {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]) + a[i][j];
        }
    max1 = f[h - 1][1];
    for (j = 1; j <= w; j++)
        if (max1 < f[h - 1][j])
            max1 = f[h - 1][j];
    printf("%d\n", max1);
    return 0;
}                                 
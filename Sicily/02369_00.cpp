// Problem#: 2369
// Submission#: 2620506
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, count, b, x, y, xx[100], yy[100], out[100], length, i, j, sum, p;
    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < 100; i++)
        xx[i] = yy[i] = 0;
        scanf("%d %d %d %d", &count, &b, &x, &y);
        i = 0;
        while (x > 0) {
            xx[i++] = x % b;
            x = x / b;
        }
        j = 0;
        while (y > 0) {
            yy[j++] = y % b;
            y = y / b;
        }
        length = i > j ? i : j;
        for (i = 0; i < length; i++) {
            out[i] = (xx[i] + yy[i]) % b;
        }
        sum = 0;
        p = 1;
        for (i = 0; i < length; i++) {
            sum += out[i] * p;
            p = p * b;
        }
        printf("%d %d\n", count, sum);
    }
    return 0;
}                                 
// Problem#: 1327
// Submission#: 2589726
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int a[10000], r[10000], o[10000], i, j, t, n;
    long long int s[10000];
    a[1] = 1;
    a[2] = 1;
    s[1] = 1;
    s[2] = 2;
    i = 2;
    while (s[i] < 90000000) {
        a[i] = a[i - 1] + a[i - 2];
        s[i] = a[i] + s[i - 1];
        i++;
    }
    scanf("%d", &t);
    while (t--) {
        memset(o, 0, sizeof(o));
        scanf("%d", &n);
        j = 0;
        while (n > 0) {
            for (i = 1; s[i] < n; i++);
            r[j++] = i;
            n = n - s[i - 1] - 1;
        }
        for (i = 0; i < j; i++) {
            o[r[0] - r[i] + 1] = 1;
        }
        for (i = 1; i <= r[0]; i++)
            printf("%d", o[i]);
        printf("\n");
    }
    return 0;
}                                 
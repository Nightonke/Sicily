// Problem#: 1052
// Submission#: 2658218
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int judge(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1])
            return 0;
    }
    return 1;
}

int main() {
    int a[10000], b[10000], n, i, counter;
    while (scanf("%d", &n), n) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        counter = 0;
        while (!judge(a, n)) {
            for (i = 0; i < n; i++) {
                a[i] = b[i] = a[i] / 2;
            }
            for (i = 1; i < n; i++) {
                a[i] += b[i - 1];
            }
            a[0] += b[n - 1];
            for (i = 0; i < n; i++)
                a[i] = a[i] % 2 == 0 ? a[i] : a[i] + 1;
            counter++;
        }
        printf("%d %d\n", counter, a[0]);
    }
    return 0;
}                                 
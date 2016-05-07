// Problem#: 1931
// Submission#: 2461583
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, i, a[100], b[50], tuigeshu, j, k;
    scanf("%d", &t);
    while (t--) {
        k = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            a[i] = i + 1;
        tuigeshu = n - 2;
        j = n;
        for (i = 0; i < tuigeshu; i++) {
            b[i] = a[k];
            a[j] = a[k + 1];
            k = k + 2;
            j++;
        }
        b[i] = a[k];
        b[i + 1] = a[k + 1];
        printf("%d", b[0]);
        for (i = 1; i < n; i++)
            printf(" %d", b[i]);
        printf(" \n");
    }
    return 0;
}                                 
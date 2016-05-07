// Problem#: 1295
// Submission#: 2585224
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, m, x, i, j;
    char a[30], s[] = {"0123456789ABCDEF"};
    while (scanf("%d", &n) == 1) {
        scanf("%d", &m);
        i = 0;
        memset(a, 0, sizeof(a));
        if (n == 0) {
            printf("0\n");
            continue;
        }
        while (n) {
            x = n % m;
            if (n > 0 || x == 0)
                n = n / m;
            else {
                n = n / m + 1;
                x = x - m;
            }
            a[i++] = s[x];
        }
        while ((a[i] == '0' || a[i] == '\0') && i > 0)
            i--;
        for (j = i; j >= 0; j--)
            printf("%c", a[j]);
        printf("\n");
    }
    return 0;
}                                 
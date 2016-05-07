// Problem#: 1147
// Submission#: 2392704
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, j, k = 0, i = 0, max, counter, sum = 0, b[1000], c[1000], f[1000], h[1000], g[1000];
    char a[1000][30], d[1000], e[1000], m;
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        m = getchar();
        while (m != ' ') {
            a[k][i] = m;
            i++;
            m = getchar();
        }
        h[k] = i - 1;
        g[k] = 0;
        scanf("%d%d", &b[k], &c[k]);
        while (1) {
            m = getchar();
            if (m == 'Y' || m == 'N') {
                d[k] = m;
                break;
            }
        }
        while (1) {
            m = getchar();
            if (m == 'Y' || m == 'N') {
                e[k] = m;
                break;
            }
        }
        scanf("%d", &f[k]);
        if (b[k] > 80 && f[k] > 0)
            g[k] = g[k] + 8000;
        if (b[k] > 85 && c[k] > 80)
            g[k] = g[k] + 4000;
        if (b[k] > 90)
            g[k] = g[k] + 2000;
        if (b[k] > 85 && e[k] == 'Y')
            g[k] = g[k] + 1000;
        if (c[k] > 80 && d[k] == 'Y')
            g[k] = g[k] + 850;
        k++;
        i = 0;
    }
    max = g[0];
    counter = 0;
    for (j = 0; j < n; j++) {
        if (g[j] > max) {
            max = g[j];
            counter = j;
        }
    }
    for (j = 0; j < n; j++) {
        sum = sum + g[j];
    }
    for (i = 1; i <= h[counter]; i++) {
        printf("%c", a[counter][i]);
    }
    printf("\n");
    printf("%d\n", max);
    printf("%d\n", sum);
    return 0;
}                                 
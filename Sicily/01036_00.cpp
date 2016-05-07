// Problem#: 1036
// Submission#: 2392476
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i, j, kongzhi, hangshu, min, k, counter, r, q, z, x, m;
    char a[100], c, b[110], d[15][15];
    while (1) {
        i = 0;
        m = 0;
        kongzhi = 0;
        r = 0;
        c = getchar();
        while (1) {
            if (c != '\n' ) {
                a[i] = c;
                i++;
            }
            if (c == '\n') {
                break;
            }
            c = getchar();
        }
        for (j = 0; j < i; j++) {
            a[j] = a[j] - 64;
        }
        if (a[0] == 20 && a[1] == 8 && a[2] == 5)
            if (a[3] == 5 && a[4] == 14 && a[5] == 4)
                break;
        while (1) {
            if (c != '\n') {
                b[m] = c;
                m++;
            }
            if (c == '\n' && kongzhi == 1)
                break;
            if (c == '\n')
                kongzhi = 1;
            c = getchar();
        }
        hangshu = m / i;
        for (j = 0; j < i; j++) {
            min = 29;
            for (k = 0; k < i; k++) {
                if (a[k] < min) {
                    min = a[k];
                    counter = k;
                }
            }
            a[counter] = 30;
            for (q = 0; q < hangshu; q++) {
                d[q][counter] = b[r];
                r++;
            }
        }
        for (z = 0; z < hangshu; z++) {
            for (x = 0; x < i; x++) {
                printf("%c", d[z][x]);
            }
        }
        printf("\n");
    }
    return 0;
}                                 
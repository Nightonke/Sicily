// Problem#: 1513
// Submission#: 2595594
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, num = 0, r, c, k, i, j, b[30][30], addx, addy, d[500];
    char find[] = {" ABCDEFGHIJKLMNOPQRSTUVWXYZ"}, a[500], out[100];
    scanf("%d", &t);
    while (t--) {
        memset(a, '\0', sizeof(a));
        memset(b, 0, sizeof(b));
        memset(out, '\0', sizeof(out));
        num++;
        scanf("%d %d %s", &r, &c, a);
        k = 0;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                b[i][j] = a[k++] - '0';
            }
        }
        addx = 1;
        addy = 1;
        i = 0;
        j = -1;
        k = 0;
        while (k < r * c) {
            while (b[i][j + addx] != -1 && j + addx < c && j + addx >= 0) {
                d[k++] = b[i][j + addx];
                if (k >= r * c)
                    break;
                b[i][j + addx] = -1;
                j = j + addx;
            }
            addx = addx * -1;
            while (b[i + addy][j] != -1 && i + addy < r && i + addy>= 0) {
                d[k++] = b[i + addy][j];
                if (k >= r * c)
                    break;
                b[i + addy][j] = -1;
                i = i + addy;
            }
            addy = addy * -1;
        }
        printf("%d ", num);
        k = 0;
        for (i = 0; i < r * c - 5 + 1; i += 5) {
            out[k++] = find[d[i] * 16 + d[i + 1] * 8 + d[i + 2] * 4 + d[i + 3] * 2 + d[i + 4] * 1];
        }
        for (i = 99; i >= 0 && (out[i] == ' ' || out[i] == '\0'); i--);
        for (k = 0; k <= i; k++)
            printf("%c", out[k]);
        printf("\n");
    }
    return 0;
}                                 
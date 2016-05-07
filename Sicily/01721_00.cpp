// Problem#: 1721
// Submission#: 2699311
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

int a[65536][16];

void ready() {
    int kongzhi = 2, i, j, k, counter;
    for (i = 15; i >= 0; i--) {
        for (j = 0; j < (int)pow(2, 16 - i - 1); j++) {
            a[j][i] = 0;
            a[65536 - j - 1][i] = 0;
        }
        counter = 65536 - 2 * (int)pow(2, 16 - i - 1);
        k = (int)pow(2, 16 - i - 1);
        while (counter) {
            for (j = 0; j < kongzhi; j++) {
                a[k++][i] = 1;
                counter--;
            }
            if (counter == 0)
                break;
            for (j = 0; j < kongzhi; j++) {
                a[k++][i] = 0;
                counter--;
            }
            if (counter == 0)
                break;
        }
        kongzhi *= 2;
    }
    for (j = (int)pow(2, 15); j < 65536; j++)
        a[j][0] = 1;
}

int main() {
    int i, j, t;
    ready();
    while (scanf("%d", &t), t) {
        for (i = 0; i < (int)pow(2, t); i++) {
            j = 16 - t;
            for (; j <= 15; j++) {
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}                                 
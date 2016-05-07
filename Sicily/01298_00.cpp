// Problem#: 1298
// Submission#: 2493771
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, i, j, here, up;
    char out[500];
    while (scanf("%d", &n) == 1) {
        i = 0;
        if (!n)
            printf("0\n");
        else {
            while (n) {
                here = n % 3;
                up = n / 3;
                if (here == 2) {
                    up++;
                    out[i++] = '-';
                }
                if (here == 1) {
                    out[i++] = '1';
                }
                if (here == 0) {
                    out[i++] = '0';
                }
                if (here == -1) {
                    out[i++] = '-';
                }
                if (here == -2) {
                    out[i++] = '1';
                    up--;
                }
                n = up;
            }
            if (out[i - 1] != '0')
                printf("%c", out[i - 1]);
            for (j = i - 2; j >= 0; j--) {
                printf("%c", out[j]);
            }
            printf("\n");
        }
    }
    return 0;
}                                 
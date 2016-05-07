// Problem#: 2499
// Submission#: 2666449
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int a[60001];

void make() {
    int i, j, k;
    for (i = 0; i < 60001; i++)
        a[i] = 4;
    for (i = 1; i * i <= 60000; i++) {
        a[i * i] = 1;
    }
    for (i = 1; i * i <= 60000; i++) {
        for (j = 1; j * j + i * i <= 60000; j++) {
            if (a[i * i + j * j] == 4)
                a[i * i + j * j] = 2;
        }
    }
    for (i = 1; i * i <= 60000; i++) {
        for (j = 1; j * j + i * i <= 60000; j++) {
            for (k = 1; k * k + j * j + i * i <= 60000; k++) {
                if (a[k * k + j * j + i * i] == 4)
                    a[k * k + j * j + i * i] = 3;
            }
        }
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    make();
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", n == 0 ? 0 : a[n]);
    }
    return 0;
}                                 
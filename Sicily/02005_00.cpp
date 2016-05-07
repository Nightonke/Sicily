// Problem#: 2005
// Submission#: 2379414
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, i, a[11000], counter = 0, zj, j;
    while(scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (j = 0; j < n - 1; j++)
            for (i = 0; i < n - j - 1; i++)
                if (a[i] > a[i+1]) {
                    zj = a[i];
                    a[i] = a[i+1];
                    a[i+1] = zj;
                }
        for (i = 0; i < n; i++) {
            if (a[i] == a[i+1]) {
                counter++;
            }
            if (a[i] != a[i+1]) {
                if (counter % 2 == 0) {
                    printf("%d\n", a[i]);
                    break;
                }
                counter = 0;
            }
            if (a[i+1] != a[i] && a[i+1] != a[i+2]) {
                printf("%d\n", a[i+1]);
                break;
            }
        }
    }
    return 0;
}                                 
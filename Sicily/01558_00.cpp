// Problem#: 1558
// Submission#: 2599940
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int an, bn, i, a[20], b[20], amin, bmin, jilu, bsemin;
    while (scanf("%d %d", &an, &bn), an && bn) {
        for (i = 0; i < an; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < bn; i++) {
            scanf("%d", &b[i]);
        }
        amin = a[0];
        bmin = b[0];
        jilu = 0;
        for (i = 0; i < an; i++) {
            if (amin > a[i]) {
                amin = a[i];
            }
        }
        for (i = 0; i < bn; i++) {
            if (bmin > b[i]) {
                bmin = b[i];
                jilu = i;
            }
        }
        b[jilu] = 100000;
        bsemin = b[0];
        for (i = 0; i < bn; i++) {
            if (bsemin > b[i]) {
                bsemin = b[i];
            }
        }
        if (amin < bsemin) {
            printf("Y\n");
            continue;
        }
        if (amin >= bsemin) {
            printf("N\n");
            continue;
        }
    }
    return 0;
}                                 
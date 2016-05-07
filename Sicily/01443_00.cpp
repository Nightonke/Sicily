// Problem#: 1443
// Submission#: 2592996
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
struct print {
    int po;
    int wanna;
}a[101];

int judge(int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (a[i].po > a[0].po) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t, n, t1, i, counter;
    print t2;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &t1);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i].po);
            a[i].wanna = 0;
        }
        a[t1].wanna = 1;
        counter = 0;
        while (1) {
            if (judge(n) == 1) {
                n--;
                counter++;
                if (a[0].wanna == 1)
                    break;
                for (i = 0; i < n; i++) {
                    a[i] = a[i + 1];
                }
            }
            if (judge(n) == 0) {
                t2 = a[0];
                for (i = 0; i < n - 1; i++) {
                    a[i] = a[i + 1];
                }
                    a[n - 1] = t2;
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 
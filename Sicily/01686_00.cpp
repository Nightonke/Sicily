// Problem#: 1686
// Submission#: 2609830
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, m, a[100010], s, e, num, i, max, rem;
    char op;
    while (scanf("%d %d", &n, &m), n || m) {
        memset(a, 0, sizeof(a));
        while (m--) {
            scanf("\n%c", &op);
            if (op == 'I') {
                scanf("%d %d %d\n", &s, &e, &num);
                for (i = s; i <= e; i++) {
                    a[i] += num;
                }
            }
            if (op == 'C') {
                scanf("%d %d", &s, &e);
                max = a[s];
                rem = s;
                for (i = s; i <= e; i++) {
                    if (a[i] > max) {
                        max = a[i];
                        rem = i;
                    }
                }
                printf("%d\n", max);
                a[rem] = 0;
            }
        }
    }
    return 0;
}                                 
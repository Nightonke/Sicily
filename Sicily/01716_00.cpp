// Problem#: 1716
// Submission#: 2699335
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, m, num[30], i, t1, t2, max;
    while (scanf("%d %d", &n, &m), n || m) {
        if (m == 0) {
            printf("%d\n", m);
            continue;
        }
        memset(num, 0, sizeof(num));
        for (i = 0; i < m; i++) {
            scanf("%d %d", &t1, &t2);
            num[t1]++;
            num[t2]++;
        }
        max = 0;
        for (i = 0; i < 30; i++) {
            if (max < num[i])
                max = num[i];
        }
        printf("%d\n", max);
    }
    return 0;
}                                 
// Problem#: 2249
// Submission#: 2654933
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, a[1001], counter, n, i, t1, t2;
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        while (n--) {
            scanf("%d %d", &t1, &t2);
            a[t2] += t1;
        }
        scanf("%d", &n);
        while (n--) {
            scanf("%d %d", &t1, &t2);
            a[t2] += t1;
        }
        counter = 0;
        for (i = 0; i < 1001; i++) {
            if (a[i])
                counter++;
        }
        printf("%d\n", counter);
        while (counter--) {
            for (i = 1000; i >= 0; i--) {
                if (a[i]) {
                    printf("%d %d\n", a[i], i);
                    a[i] = 0;
                }
            }
        }
    }
    return 0;
}                                 
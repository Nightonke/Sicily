// Problem#: 1190
// Submission#: 2519333
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, n, i, a[301], b[301], j, kongzhi, mod;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        mod = 1;
        while (1) {
            kongzhi = 1;
            for (i = 0; i < n && kongzhi; i++) {
                b[i] = a[i] % mod;
                for (j = 0; j < i; j++) {
                    if (b[i] == b[j]) {
                        mod++;
                        kongzhi = 0;
                        memset(b, 0, sizeof(b));
                        break;
                    }
                }
            }
            if (kongzhi)
                break;
        }
        printf("%d\n", mod);
    }
    return 0;
}                                 
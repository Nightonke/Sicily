// Problem#: 7674
// Submission#: 2705010
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, p, i, kongzhi, p_origi, a[55];
    while (scanf("%d%d", &n, &p), n && p) {
        memset(a, 0, sizeof(a));
        p_origi = p;
        kongzhi = 1;
        while (kongzhi) {
            for (i = 0; i < n; i++) {
                if (p) {
                    a[i]++;
                    p--;
                } else {
                    p += a[i];
                    a[i] = 0;
                }
                if (a[i] == p_origi) {
                    printf("%d\n", i);
                    kongzhi = 0;
                    break;
                }
            }
        }
    }
    return 0;
}                                 
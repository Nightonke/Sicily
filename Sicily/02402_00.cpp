// Problem#: 2402
// Submission#: 2707925
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, kongzhi, value, i, m, before;
    while (scanf("%d", &n), n) {
        kongzhi = before = 0;
        value = 1;
        while (n--) {
            scanf("%d", &m);
            if (m > before) {
                for (i = 0; i < m - before; i++) {
                    if (kongzhi)
                        printf(" ");
                    kongzhi = 1;
                    printf("%d", value);
                }
            }
            before = m;
            value++;
        }
        printf("\n");
    }
    return 0;
}                                 
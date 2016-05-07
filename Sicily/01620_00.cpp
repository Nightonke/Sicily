// Problem#: 1620
// Submission#: 2446640
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, m, c, p, s;
    scanf("%d", &t);
    while (t--) {
        scanf ("%d %d %d %d %d", &n, &m, &c, &p, &s);
        if (s * c > p && m >= p) {
            n = n + m / p;
            m = m % p;
        }
        for (; s > 0; s--) {
            m = m + c * n;
            if (m >= p && c * (s - 1) > p) {
                n = n + m / p;
                m = m % p;
            }
        }
        printf("%d\n", m);
    }
    return 0;
}                                 
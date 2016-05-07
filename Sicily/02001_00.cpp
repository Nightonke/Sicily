// Problem#: 2001
// Submission#: 2439835
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int p, q, p1, q1, a[100000], b[100000], i = 0, j = 0, m, n;
    scanf("%d %d", &p, &q);
    for (p1 = 1; p1 <= p; p1++) {
        if (p % p1 == 0) {
            a[i] = p1;
            i++;
        }
    }
    for (q1 = 1; q1 <= q; q1++) {
        if (q % q1 == 0) {
            b[j] = q1;
            j++;
        }
    }
    for (m = 0; m < i; m++)
        for (n = 0; n < j; n++)
            printf("%d %d\n", a[m], b[n]);
    return 0;
}                                 
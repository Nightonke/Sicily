// Problem#: 1099
// Submission#: 2694592
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#define INF 0.00001

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int pn, counter = 0, na, nb, pa, pb, ca, cb;
    while (scanf("%d", &pn), pn) {
        counter++;
        scanf("%d%d%d%d", &ca, &pa, &cb, &pb);
        if (pn % gcd(pa, pb)) {
            printf("Data set %d: cannot be flown\n", counter);
            continue;
        }
        if (ca * pb > cb * pa) {
            for (na = 0; ; na++) {
                if (fabs((double)(pn - na * pa) / pb - ((pn - na * pa) / pb)) < INF) {
                    printf("Data set %d: %d aircraft A, %d aircraft B\n", counter, na, (pn - na * pa) / pb);
                    break;
                }
            }
        }
        else {
            for (nb = 0; ; nb++) {
                if (fabs((double)(pn - nb * pb) / pa - (int)((pn - nb * pb) / pa)) < INF) {
                    printf("Data set %d: %d aircraft A, %d aircraft B\n", counter, (pn - nb * pb) / pa, nb);
                    break;
                }
            }
        }
    }
    return 0;
}                                 
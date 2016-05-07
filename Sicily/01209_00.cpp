// Problem#: 1209
// Submission#: 2451758
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    long long int t, t1, n, i, counter;
    scanf("%lld", &t);
    while (t--) {
        counter = 0;
        scanf("%lld %lld", &t1, &n);
        for (i = 2; i * (i + 1) <= 2 * n; i++) {
            if ((n - (i - 1) * i / 2) % i == 0)
                counter++;
        }
        printf("%lld %lld\n", t1, counter);
        counter = 0;
    }
    return 0;
}                                 
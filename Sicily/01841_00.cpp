// Problem#: 1841
// Submission#: 3590278
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int cs, min, max, a1, a2, a3, a4;

int gcd(int x, int y) {
    int temp;
    while (y) {
        temp = x;
        x = y;
        y = temp % y;
    }
    return x;
}

int main() {
    int i, g;
    scanf("%d", &cs);
    while (cs--) {
        scanf("%d%d%d%d%d%d", &min, &max, &a1, &a2, &a3, &a4);
        a1 -= a4;
        a2 -= a4;
        a3 -= a4;
        g = gcd(a1, gcd(a2, a3));
        if (!g) printf("%d\n", max - min + 1);
        else {
            if (g < 0) g = -g;
            long long n = max - min;
            long long ans = (n / g) * ((n / g - 1) * g + (n % g + 1) * 2) + n + 1;
            printf("%lld\n", ans);
        }
    }
    return 0;
}                                 
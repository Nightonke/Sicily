// Problem#: 1609
// Submission#: 2607204
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    long long int t, length, n, a[2010], d, i;
    char a1[2010];
    scanf("%lld", &t);
    while (t--) {
        memset(a1, '\0', sizeof(a1));
        memset(a, 0, sizeof(a));
        scanf("%lld\n%s", &n, a1);
        length = strlen(a1);
        for (i = 0; i < length; i++) {
            a[i] = a1[length - 1 - i] - '0';
        }
        d = 0;
        for (i = length - 1; i >= 0; i--) {
            d = d * 10 + a[i];
            d %= n;
        }
        printf("%lld\n", d);
    }
    return 0;
}                                 
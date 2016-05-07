// Problem#: 1685
// Submission#: 2447187
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    long long int i, counter, n, a[1010];
    while (1) {
        scanf("%lld", &n);
        if (n == 0)
            break;
        counter = 1;
        for (i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for (i = 0; i < n - 1;) {
            for (; i < n - 1; i++) {
                if (a[i] > a[i + 1]) {
                    counter++;
                    break;
                }
            }
            i++;
            for (; i < n - 1; i++) {
                if (a[i] < a[i + 1]) {
                    counter++;
                    break;
                }
            }
            i++;
        }
        printf("%lld\n", counter);
    }
    return 0;
}                                 
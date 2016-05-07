// Problem#: 1694
// Submission#: 2520907
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
void findposi(long long int k, long long int n) {
    long long int i = 0;
    if (k % 2 == 0)
        k++;
    while (n <= (k - 2) * (k - 2) && k > 1) {
        k -= 2;
        i++;
    }
    if (n <= k * k && n > k * k - k) {
        printf("%lld %lld\n", 1 + i, k - (k * k - n) + i);
        return;
    }
    if (n <= k * k - k && n > k * k - 2 * k + 1) {
        printf("%lld %lld\n", k * k - k + 2 - n + i, 1 + i);
        return;
    }
    if (n <= k * k - 2 * k + 1 && n > k * k - 3 * k + 2) {
        printf("%lld %lld\n", k + i, k * k - 2 * k + 3 - n + i);
        return;
    }
    if (n > (k - 2) * (k - 2) && n <= k * k - 3 * k + 2) {
        printf("%lld %lld\n", n - (k - 2) * (k - 2) + 1 + i, k + i);
        return;
    }
}
int main() {
    long long int n, t, k;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &k, &n);
        findposi(k, n);
    }
    return 0;
}                                 
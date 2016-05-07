// Problem#: 4423
// Submission#: 2702058
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    long long int t, n, i, j, sum, count_1[20] = {0}, temp;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld", &temp);
            j = 19;
            while (temp > 0) {
                if (temp % 2)
                    count_1[j]++;
                j--;
                temp /= 2;
            }
        }
        for (sum = 0, i = 0; i < 20; i++) {
            sum += count_1[i] * (n - count_1[i]) * (long long int)pow(2, 20 - i - 1);
            count_1[i] = 0;
        }
        printf("%lld\n", sum);
    }
    return 0;
}                                 
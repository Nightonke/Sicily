// Problem#: 1218
// Submission#: 2590546
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    long long int n, m, i, temp;
    scanf("%lld %lld", &n, &m);
    for (i = sqrt(2.0 * n) + 1; i >= 1; i--) {
        temp = m - i * (i - 1) / 2;  // deng cha gong shi, temp shi a1*xiangshu;
        if (temp % i == 0 && temp / i > 0 && temp / i + i - 1 <= n)
            printf("[%lld,%lld]\n", temp / i, temp / i + i - 1);
    }
    return 0;
}                                 
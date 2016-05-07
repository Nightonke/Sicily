// Problem#: 2013
// Submission#: 2700054
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int a[100010];

long long int ans(int n) {
    long long int pos1 = 0, pos2, sum = 0, step = 0, before_sum = 0, need_pay = 0;
    for (pos2 = 1; pos2 <= n; pos2++, step++) {
        if (a[pos2] >= 0) {
            sum += a[pos2];
        } else {
            if (a[pos2] * a[pos2] <= sum * sum) {
                sum += a[pos2];
            } else {
                if (!need_pay)
                    pos1 = pos2;
                need_pay = 1;
                before_sum += a[pos2];
            }
        }
        if (sum * sum >= before_sum * before_sum && need_pay) {
            step += (pos2 - pos1) * 2;
            sum += before_sum;
            before_sum = 0;
            need_pay = 0;
        }
    }
    return step;
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%lld\n", ans(n));
    return 0;
}                                 
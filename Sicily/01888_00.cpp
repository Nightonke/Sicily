// Problem#: 1888
// Submission#: 2760944
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#define INF -99999999
int a[100005];

long long ans(int n) {
    long long sum_all = 0, sum_min = 0, sum_max = 0, max = INF, min = -INF;
    for (int i = 0; i < n; i++) {
        
        if (sum_max < 0) {
            sum_max = a[i];
        } else {
            sum_max += a[i];
        }
        if (sum_max > max)
            max = sum_max;
        
        if (sum_min > 0) {
            sum_min = a[i];
        } else {
            sum_min += a[i];
        }
        if (sum_min < min) {
            min = sum_min;
        }
        
        sum_all += a[i];
    }
    if (max < 0) {
        return max;
    } else {
        return max > sum_all - min ? max : sum_all - min;
    }
}

int main() {
    int n, case_num, i;
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        printf("%lld\n", ans(n));
    }
    return 0;
}                                 
// Problem#: 1888
// Submission#: 2760186
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#define INF -99999999
int a[100005];

long long max(int n) {
    long long sum = 0;
    long long max = INF;
    for (int i = 0; i < n; i++) {
        if (sum < 0) {
            sum = a[i];
        } else {
            sum += a[i];
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

long long min(int n) {
    long long sum = 0;
    long long min = -INF;
    for (int i = 0; i < n; i++) {
        if (sum > 0) {
            sum = a[i];
        } else {
            sum += a[i];
        }
        if (sum < min) {
            min = sum;
        }
    }
    return min;
}

long long sum_all(int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int n, case_num, i;
    long long temp1, temp2;
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        temp1 = max(n);
        temp2 = sum_all(n) - min(n);
        if (temp1 < 0)
            printf("%lld\n", temp1);
        else
            printf("%lld\n", temp1 > temp2 ? temp1 : temp2);
    }
    return 0;
}                                 
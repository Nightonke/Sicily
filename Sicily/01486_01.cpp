// Problem#: 1486
// Submission#: 2665380
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
long long int a[200010];
long long int interchange(long long int low, long long int high) {
    long long int key = a[low];
    while (low < high) {
        for (; low < high && a[high] >= key; high--);
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        for (; low < high && a[low] <= key; low++);
        if (low < high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = key;
    return low;
}

void quicksort(long long int low, long long int high) {
    if (low < high) {
        long long int mid = interchange(low, high);
        quicksort(low, mid - 1);
        quicksort(mid + 1, high);
    }
}

int main() {
    long long int n, i, counter = 0, kongzhi = 0;
    while (scanf("%lld", &n) == 1) {
        if (kongzhi)
            printf("\n");
        kongzhi = 1;
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        quicksort(0, n - 1);
        for (i = 0; i < n; i++) {
            if (a[i] == a[i + 1]) {
                counter++;
            }
            if (a[i] != a[i + 1]) {
                printf("%lld %lld\n", a[i], counter + 1);
                counter = 0;
            }
        }
    }
    return 0;
}                                 
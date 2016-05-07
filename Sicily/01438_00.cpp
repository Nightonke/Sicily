// Problem#: 1438
// Submission#: 2490777
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
long long int interchange(long long int a[], long long int low, long long int high) {
    long long int key = a[low];
    while (low < high) {
        while (low < high && a[high] <= key)
            high--;
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        while (low < high && a[low] >= key)
            low++;
        if (low < high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = key;
    return low;
}
void quicksort (long long int a[], long long int low, long long int high) {
    long long int newmid;
    if (low < high) {
        newmid = interchange(a, low, high);
        quicksort(a, low, newmid - 1);
        quicksort(a, newmid + 1, high);
    }
}
int main() {
    long long int n, i, a[30000], sum, t;
    scanf("%lld", &t);
    while (t--) {
        sum = 0;
        scanf("%lld", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        quicksort(a, 0, n - 1);
        for (i = 2; i < n; i = i + 3)
            sum = sum + a[i];
        printf("%lld\n", sum);
    }
    return 0;
}                                 
// Problem#: 4189
// Submission#: 2666521
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
    long long int n, i, counter = 0;
    while (scanf("%lld", &n), n) {
        counter = 0;
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        quicksort(0, n - 1);
        for (i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1])
                counter++;
        }
        printf("%d\n", counter + 1);
    }
    return 0;
}                                 
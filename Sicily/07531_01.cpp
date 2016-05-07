// Problem#: 7531
// Submission#: 2704716
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

long long int a[500010];

long long int interchange(long long int low, long long int high) {
    long long int key = a[low];
    while (low < high) {
        while (low < high && a[high] >= key)
            high--;
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        while (low < high && a[low] <= key)
            low++;
        if (low < high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = key;
    return low;
}
void quicksort (long long int low, long long int high) {
    long long int newmid;
    if (low < high) {
        newmid = interchange(low, high);
        quicksort(low, newmid - 1);
        quicksort(newmid + 1, high);
    }
}

int main() {
    long long int n, i, length, first, counter, pos;
    while (scanf("%lld", &n) == 1) {
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        quicksort(0, n - 1);
        length = n;
        pos = n - 1;
        first = counter = 0;
        while (length > 1) {
            if (a[first] == 0) {
                first++;
            }
            a[first]--;
            counter++;
            a[pos - 1] += a[pos] + 1;
            a[pos] = 0;
            pos--;
            if (a[first] == 0)
                length -= 2;
            else
                length--;
        }
        printf("%lld\n", counter);
    }
    return 0;
}                                 
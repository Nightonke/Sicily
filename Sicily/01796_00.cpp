// Problem#: 1796
// Submission#: 2700146
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct pl {
    long long int p, intel;
};

pl a[1000010];

bool should_change(pl a1, pl a2) {
    if (a1.p > a2.p)
        return true;
    if (a1.p == a2.p) {
        if (a1.intel > a2.intel)
            return true;
    }
    return false;
}

int interchange(int low, int high) {
    pl key = a[low];
    while (low < high) {
        for (; low < high && !should_change(key, a[high]); high--);
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        for (; low < high && !should_change(a[low], key); low++);
        if (low < high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = key;
    return low;
}

void quicksort(int low, int high) {
    if (low < high) {
        int mid = interchange(low, high);
        quicksort(low, mid - 1);
        quicksort(mid + 1, high);
    }
}

int main() {
    int n, i, counter;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++) {
            scanf("%lld%lld", &a[i].p, &a[i].intel);
        }
        if (n == 1) {
            printf("%lld %lld\n", a[0].p, a[0].intel);
            continue;
        }
        quicksort(0, n - 1);
        a[n].p = a[n - 1].p + 1;
        for (counter = 1, i = 1; i <= n; i++) {
            if (a[i].p == a[i - 1].p)
                counter++;
            else {
                if (counter % 2)
                    printf("%lld %lld\n", a[i - 1].p, a[(2 * i - counter - 1) / 2].intel);
                else
                    printf("%lld %lld\n", a[i - 1].p, (a[(2 * i - counter - 1) / 2].intel + a[(2 * i - counter - 1) / 2 + 1].intel) / 2);
                counter = 1;
            }
        }
    }
    return 0;
}                                 
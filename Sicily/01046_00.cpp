// Problem#: 1046
// Submission#: 2693359
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct period {
    int f;
    int l;
    int num;
};

period p[90000];

bool should_change(struct period a, struct period b) {
    if (a.num * (b.l - b.f + 1) < b.num * (a.l - a.f + 1))
        return true;
    else if (a.num * (b.l - b.f + 1) > b.num * (a.l - a.f + 1))
        return false;
    else if (a.num * (b.l - b.f + 1) == b.num * (a.l - a.f + 1)) {
        if (a.l - a.f > b.l - b.f)
            return false;
        else if (a.l - a.f < b.l - b.f)
            return true;
        else if (a.l - a.f == b.l - b.f) {
            if (a.l < b.l)
                return false;
            else if (a.l > b.l)
                return true;
            else if (a.l == b.l)
                return false;
        }
    }
}

int interchange(int low, int high) {
    period key = p[low];
    while (low < high) {
        for (; low < high && !should_change(key, p[high]); high--);
        if (low < high) {
            p[low] = p[high];
            low++;
        }
        for (; low < high && !should_change(p[low], key); low++);
        if (low < high) {
            p[high] = p[low];
            high--;
        }
    }
    p[low] = key;
    return low;
}

void psort(int low, int high) {
    int mid;
    if (low < high) {
        mid = interchange(low, high);
        psort(mid + 1, high);
        psort(low, mid - 1);
    }
}

int main() {
    int counter = 0, i, j, sum, n, length, t, need, a[301], k;
    scanf("%d", &t);
    while (t--) {
        counter++;
        scanf("%d%d%d", &n, &need, &length);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        k = 0;
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = i; j < n; j++) {
                sum = sum + a[j];
                if (j - i + 1 >= length) {
                    p[k].f = i;
                    p[k].l = j;
                    p[k++].num = sum;
                }
            }
        }
        psort(0, k - 1);
        printf("Result for run %d:\n", counter);
        for (i = 0; i < need && i < k; i++) {
            printf("%d-%d\n", p[i].f + 1, p[i].l + 1);
        }
    }
    return 0;
}                                 
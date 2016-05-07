// Problem#: 1747
// Submission#: 2699526
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct p {
    int ing;
    int ed;
};

p a[100000];

int interchange(int low, int high) {
    p key = a[low];
    while (low < high) {
        for (; low < high && key.ing >= a[high].ing; high--);
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        for (; low < high && key.ing <= a[high].ing; low++);
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
    int t, all, n, sum, i, is_ok;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &all, &n);
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &a[i].ing, &a[i].ed);
            sum += a[i].ed;
        }
        if (sum > all) {
            printf("No\n");
            continue;
        }
        quicksort(0, n - 1);
        is_ok = 1;
        for (i = 0; i < n; i++) {
            if (a[i].ing > all) {
                is_ok = 0;
                break;
            } else {
                all -= a[i].ed;
            }
        }
        if (is_ok)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}                                 
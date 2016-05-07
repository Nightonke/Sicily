// Problem#: 1097
// Submission#: 2695150
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

struct resistors {
    int resistance;
    char name[41];
};

resistors r[10001];

int interchange(int low, int high) {
    resistors key = r[low];
    while (low < high) {
        for (; low < high && key.resistance < r[high].resistance; high--);
        if (low < high) {
            r[low] = r[high];
            low++;
        }
        for (; low < high && key.resistance > r[low].resistance; low++);
        if (low < high) {
            r[high] = r[low];
            high--;
        }
    }
    r[low] = key;
    return low;
}

void quicksort(int low, int high) {
    if (low < high) {
        int mid = interchange(low, high);
        quicksort(mid + 1, high);
        quicksort(low, mid - 1);
    }
}

int main() {
    int give_v, need_v, need_ma, n, i;
    double need_r;
    while (scanf("%d", &give_v) == 1) {
        scanf("%d%d%d", &need_v, &need_ma, &n);
        for (i = 0; i < n; i++) {
            memset(r[i].name, '\0', sizeof(r[i].name));
            scanf("%s %d", r[i].name, &r[i].resistance);
        }
        if (need_v >= give_v) {
            printf("---\n");
            continue;
        }
        need_r = (double)(give_v - need_v) / (0.001 * need_ma);
        quicksort(0, n - 1);
        for (i = 0; i < n; i++) {
            if (r[i].resistance >= need_r) {
                break;
            }
        }
        if (i == n)
            printf("IMPOSSIBLE\n");
        else
            printf("%.2lf %s\n", need_r, r[i].name);
    }
    return 0;
}                                 
// Problem#: 1566
// Submission#: 2594926
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct com {
    int sum;
    int add1;
    int add2;
};

com add[510 * 510];

int interchange(int low, int high) {
    com key = add[low];
    while (low < high) {
        while (low < high && add[high].sum <= key.sum)
            high--;
        if (low < high) {
            add[low] = add[high];
            low++;
        }
        while (low < high && add[low].sum >= key.sum)
            low++;
        if (low < high) {
            add[high] = add[low];
            high--;
        }
    }
    add[low] = key;
    return low;
}
void quicksort (int low, int high) {
    int newmid;
    if (low < high) {
        newmid = interchange(low, high);
        quicksort(low, newmid - 1);
        quicksort(newmid + 1, high);
    }
}

int bsearch(int target, int low, int high) {
    if (low <= high) {
        if (add[(high + low) / 2].sum == target)
            return (high + low) / 2;
        if (add[(high + low) / 2].sum > target)
            return bsearch(target, (high + low) / 2 + 1, high);
        if (add[(high + low) / 2].sum < target)
            return bsearch(target, low, (high + low) / 2 - 1);
    }
    if (low > high)
        return -1;
}

int main() {
    int an, bn, cn, dn, i, j, a[510] = {0}, b[510] = {0}, c[510] = {0}, d[510] = {0}, find;
    scanf("%d%d%d%d", &an, &bn, &cn, &dn);
    for (i = 0; i < an; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < bn; i++) {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < cn; i++) {
        scanf("%d", &c[i]);
    }
    for (i = 0; i < dn; i++) {
        scanf("%d", &d[i]);
    }
    for (i = 0; i < cn; i++) {
        for (j = 0; j < dn; j++) {
            add[i * dn + j].sum = c[i] + d[j];
            add[i * dn + j].add1 = c[i];
            add[i * dn + j].add2 = d[j];
        }
    }
    find = -1;
    quicksort(0, cn * dn - 1);
    for (i = 0; i < an && find == -1; i++) {
        for (j = 0; j < bn && find == -1; j++) {
            find = bsearch(0 - a[i] - b[j], 0, cn * dn - 1);
            if (find != -1) {
                printf("%d %d %d %d\n", a[i], b[j], add[find].add1, add[find].add2);
            }
        }
    }
    return 0;
}                                 
// Problem#: 1587
// Submission#: 2595033
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int intercharge(int a[], int low, int high) {
    int key = a[low];
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

void quicksort(int a[], int low, int high) {
    int newmid;
    if (low < high) {
        newmid = intercharge(a, low, high);
        quicksort(a, newmid + 1, high);
        quicksort(a, low, newmid - 1);
    }
}

int main() {
    int t, an, bn, a[20010], b[20010], sum, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &an, &bn);
        for (i = 0; i < an; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < bn; i++) {
            scanf("%d", &b[i]);
        }
        quicksort(a, 0, an - 1);
        quicksort(b, 0, bn - 1);
        sum = 0;
        for (i = 0; i < an; i++) {
            for (j = bn - 1; j >= 0 && a[i] <= b[j]; j--);
            if (j != -1) {
                sum += j + 1;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}                                 
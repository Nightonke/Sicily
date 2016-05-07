// Problem#: 9094
// Submission#: 2709386
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int a[1010];

int interchange(int low, int high) {
    int key = a[low];
    while (low < high) {
        for (; a[high] >= key && low < high; high--);
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        for (; a[low] <= key && low < high; low++);
        if (low < high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = key;
    return low;
}

void quicksort(int low, int high) {
    int mid;
    if (low < high) {
        mid = interchange(low, high);
        quicksort(low, mid - 1);
        quicksort(mid + 1, high);
    }
}

int main() {
    int n, i, b[1010], before, j, max_length, length_now, before_2, c[1010], k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    before = -1;
    quicksort(0, n - 1);
    for (i = 0, max_length = 0; i < n; i++) {
        if (a[i] != before) {
            before = a[i];
            for (j = 0, k = 0; j < n; j++) {
                if (b[j] != a[i]) {
                    c[k++] = b[j];
                }
            }
            for (j = 1, length_now = 1, before_2 = c[0]; j < k; j++) {
                if (c[j] == before_2)
                    length_now++;
                else {
                    before_2 = c[j];
                    length_now = 1;
                }
                if (max_length < length_now)
                    max_length = length_now;
            }
        }
    }
    printf("%d\n", max_length);
    return 0;
}                                 
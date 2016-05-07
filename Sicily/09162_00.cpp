// Problem#: 9162
// Submission#: 2659047
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#define INF 100000000
int a[1000001], s[1000001];

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
    int n, k, i, min, min1, max, j, length, mem;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(0, n - 1);
    for (i = 0; i < n - 1; i++)
        s[i] = a[i + 1] - a[i];
    length = n - k;
    min = INF;
    mem = -1;
    for (i = 0; i < k + 1; i++) {
        max = a[length + i - 1] - a[i];
        if (max <= min) {
            if (mem >= i && mem <= length + i - 1 - 1) {
                if (s[mem] >= s[length + i - 1 - 1])
                    mem = length + i - 1 - 1;
            }
            else {
                min1 = INF;
                for (j = i; j < length + i - 1; j++) {
                    if (s[j] <= min1) {
                        mem = j;
                        min1 = s[j];
                    }
                }
            }
            min = max + s[mem] < min ? max + s[mem] : min;
        }
    }
    printf("%d\n", min);
    return 0;
}                                 
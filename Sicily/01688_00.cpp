// Problem#: 1688
// Submission#: 2600433
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int interchange(int add[], int low, int high) {
    int key = add[low];
    while (low < high) {
        while (low < high && add[high] >= key)
            high--;
        if (low < high) {
            add[low] = add[high];
            low++;
        }
        while (low < high && add[low] <= key)
            low++;
        if (low < high) {
            add[high] = add[low];
            high--;
        }
    }
    add[low] = key;
    return low;
}
void quicksort (int add[], int low, int high) {
    int newmid;
    if (low < high) {
        newmid = interchange(add, low, high);
        quicksort(add, low, newmid - 1);
        quicksort(add, newmid + 1, high);
    }
}
int main() {
    int t, n, i, j, a[10001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        quicksort(a, 0, n - 1);
        printf("%d", a[0]);
        i = 1;
        j = n - 1;
        while (i <= j) {
            printf(" %d", a[j--]);
            if (i <= j)
                printf(" %d", a[i++]);
        }
        printf("\n");
    }
    return 0;
}                                 
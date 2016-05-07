// Problem#: 1778
// Submission#: 2700212
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct p {
    int num, w;
};

p a[1000000];

int interchange(int low, int high) {
    p key = a[low];
    while (low < high) {
        for (; low < high && key.w <= a[high].w; high--);
        if (low < high) {
            a[low] = a[high];
            low++;
        }
        for (; low < high && a[low].w <= key.w; low++);
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
    int t, n, length, in, out, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        length = 0;
        while (n--) {
            scanf("%d%d", &in, &out);
            for (i = length; i < length + in; i++) {
                scanf("%d%d", &a[i].num, &a[i].w);
            }
            quicksort(0, length + in - 1);
            length += in - out;
        }
        printf("%d %d\n", a[length - 1].num, a[length - 1].w);
    }
    return 0;
}                                 
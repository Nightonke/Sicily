// Problem#: 1060
// Submission#: 2695269
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int s[40003];

int bsearch (int target, int low, int high) {
    int mid = (low + high) / 2;
    if (low <= high) {
        if (target > s[mid])
            return bsearch(target, mid + 1, high);
        if (target < s[mid])
            return bsearch(target, low, mid - 1);
    }
    return low;
}

int main () {
    int t, n, i, signals[40003], pos;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &signals[i]);
        }
        s[0] = 1;
        s[1] = signals[0];
        for (i = 1; i < n; i++) {
            if (signals[i] > s[s[0]]) {
                s[0]++;
                s[s[0]] = signals[i];
            } else {
                pos = bsearch(signals[i], 1, s[0]);
                s[pos] = signals[i];
            }
        }
        printf("%d\n", s[0]);
    }
    return 0;
}                                 
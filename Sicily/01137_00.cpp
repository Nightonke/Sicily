// Problem#: 1137
// Submission#: 2754493
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[30001], max_l, max_differ, i, j, max_pos, min_pos, may_max, max, min, k;
    scanf("%d%d", &max_l, &max_differ);
    for (i = 0; i < max_l; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0, max = min = a[0], max_pos = min_pos = 0, j = i + 1, may_max = 1; i < max_l; ) {
        
        if (max_l - i <= may_max)
            break;
        
        if (max_pos < i) {
            j = min_pos;
            for (k = i, max = 0; k < j; k++) {
                if (a[k] > max) {
                    max = a[k];
                    max_pos = k;
                }
            }
        }
        if (min_pos < i) {
            j = max_pos;
            for (k = i, min = 9999999; k < j; k++) {
                if (a[k] < min) {
                    min = a[k];
                    min_pos = k;
                }
            }
        }
        
        for (; j < max_l; j++) {
            if (a[j] > max) {
                max = a[j];
                max_pos = j;
            } else if (a[j] < min) {
                min = a[j];
                min_pos = j;
            }
            if (max - min <= max_differ) {
                if (j - i + 1 > may_max) {
                    may_max = j - i + 1;
                }
            } else {
                i = (min_pos < max_pos ? min_pos : max_pos) + 1;
                break;
            }
        }
    }
    printf("%d\n", may_max);
    return 0;
}                                 
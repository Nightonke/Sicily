// Problem#: 1663
// Submission#: 2608980
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

struct time{
    int s;
    int e;
};

int main() {
    int a[50], n, i, j, counter, k = 0;
    time t[110], temp;
    while (scanf("%d", &n), n) {
        k++;
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++) {
            scanf("%d %d", &t[i].s, &t[i].e);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - 1 - i; j++) {
                if (t[j].e > t[j + 1].e) {
                    temp = t[j];
                    t[j] = t[j + 1];
                    t[j + 1] = temp;
                }
            }
        }
        counter = 0;
        for (i = 0; i < n; i++) {
            for (j = 16; j <= 47; j++) {
                if (2 * t[i].s <= j && 2 * t[i].e >= (j + 1) && a[j] == 0) {
                    counter++;
                    a[j] = 1;
                    break;
                }
            }
        }
        printf("On day %d Emma can attend as many as %d parties.\n", k, counter);
    }
    return 0;
}                                 
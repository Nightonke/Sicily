// Problem#: 2386
// Submission#: 2811536
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

int c[5];

bool o(int k) {
    for (int i = 0; i < 5; i++)
        if (k == c[i])
            return false;
    int x[3], y[3];
    int per[3] = {0, 1, 2};
    x[0] = c[3];
    x[1] = c[4];
    x[2] = k;
    y[0] = c[0];
    y[1] = c[1];
    y[2] = c[2];
    while (1) {
        int u = 0;
        for (int i = 0; i < 3; i++) {
            if (y[per[i]] > x[i]) {
                u++;
            }
        }
        if (u >= 2)
            return false;
        if (!next_permutation(per, per + 3))
            return true;
    }
}

int main() {
    while (scanf("%d", &c[0]) && c[0]) {
        int i, k;
        for (i = 1; i < 5; i++) {
            scanf("%d", &c[i]);
        }
        for (k = 1; k <= 52; k++) {
            if (o(k)) {
                break;
            }
        }
        printf("%d\n", (k + 1) % 54 - 1);
    }
    return 0;
}                                 
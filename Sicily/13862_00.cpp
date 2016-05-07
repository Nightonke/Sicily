// Problem#: 13862
// Submission#: 3653674
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int stall[3000005];

int main() {
    int n, k, x, y, a, b;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        a %= n;
        int sum = b % n;
        while (y--) {
            sum += a;
            if (sum >= n) sum -= n;
            stall[sum] += x;
        }
    }
    int m = n - 1;
    for (int i = 0; i < m; i++) {
        if (stall[i] > 1) {
            stall[i + 1] += stall[i] - 1;
            stall[i] = 1;
        }
    }
    if (stall[m] > 1) {
        stall[0] += stall[m] - 1;
        stall[m] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (stall[i] == 0) {
            printf("%d\n", i);
            return 0;
        }
        if (stall[i] > 1) {
            stall[i + 1] += stall[i] - 1;
            stall[i] = 1;
        }
    }
    return 0;
}                                 
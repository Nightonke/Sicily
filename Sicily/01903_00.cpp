// Problem#: 1903
// Submission#: 3580805
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        int num1 = n / 2 + 1;
        if (k <= num1) printf("1/%d\n", n + 1 - k);
        else {
            k -= num1;
            int num2 = n & 1 ? n - 2 * n / 3 : n - 1 - 2 * n / 3;
            if (k <= num2) {
                int tmp = n & 1 ? n + 1 - k : n - k;
                if (tmp & 1) printf("2/%d\n", tmp);
                else printf("1/%d\n", tmp / 2);
            } else {
                k -= num2;
                if (n % 3 == 0) {
                    if (k == 1) {
                        printf("1/%d\n", n / 3);
                        continue;
                    }
                    else {
                        k--;
                        n--;
                    }
                }
                if (n % 3 == 1) {
                    n *= 2;
                    n -= (k - 1) / 4 * 6;
                    if (k % 4 == 1) printf("3/%d\n", n / 2);
                    else if (k % 4 == 2) printf("1/%d\n", (n - 2) / 6);
                    else if (k % 4 == 3) printf("3/%d\n", (n - 4) / 2);
                    else printf("2/%d\n", (n - 5) / 3);
                } else {
                    n *= 2;
                    n -= (k - 1) / 4 * 6;
                    if (k % 4 == 1) printf("3/%d\n", n / 2);
                    else if (k % 4 == 2) printf("2/%d\n", (n - 1) / 3);
                    else if (k % 4 == 3) printf("3/%d\n", (n - 2) / 2);
                    else printf("1/%d\n", (n - 4) / 6);
                }
            }
        }
    }

    return 0;
}                                 
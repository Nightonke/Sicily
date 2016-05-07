// Problem#: 1305
// Submission#: 2777057
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    long long n;
    while (~scanf("%lld", &n)) {
        if (n == 1) {
            printf("Nic wins.\n");
            continue;
        }
        long long temp = 1;
        while (1) {
            temp *= 9;
            if (temp >= n) {
                printf("Nic wins.\n");
                break;
            }
            temp *= 2;
            if (temp >= n) {
                printf("Susan wins.\n");
                break;
            }
        }
    }
    return 0;
}                                 
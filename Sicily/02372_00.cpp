// Problem#: 2372
// Submission#: 2470543
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    long long int a[65][11], i, sum = 0, j, counter, weishu, t;
    for (i = 0; i < 10; i++) {
        a[0][i] = 1;
        sum = sum + a[0][i];
    }
    for (i = 1; i < 65; i++) {
        a[i][0] = sum;
        for (j = 1; j < 10; j++) {
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
            sum = sum + a[i][j];
        }
    }
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &counter, &weishu);
        printf("%lld %lld\n", counter, a[weishu][0]);
    }
    return 0;
}                                 
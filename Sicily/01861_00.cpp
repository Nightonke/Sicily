// Problem#: 1861
// Submission#: 3590245
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 101;

int solve(int n) {
    int ret = 0, i, num1, num2, num3;
    num1 = n * n * (n + 1) * (n + 1) / 4;
    ret += num1;
    num2 = 0;
    for (i = 1; i <= n; i++) num2 += i * i;
    num3 = num1 - num2;
    ret += 3 * num3;
    for (i = 2; i <= n; i++) ret += (i - 1) * 2 * (n + 1 - i) * (n + 1 - i);
    return ret;
}

int main() {
    int n, tn;
    scanf("%d", &tn);
    while (tn--) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}                                 
// Problem#: 10330
// Submission#: 2763730
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", m - 1 - (gcd(n, m) - 1));
    return 0;
}                                 
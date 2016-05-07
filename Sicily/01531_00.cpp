// Problem#: 1531
// Submission#: 2599186
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int gcd(int i, int j) {
    if (j)
        return gcd(j, i % j);
    return i;
}

int main() {
    int t, n, counter, i, j, a, b, c, sum;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        counter = 0;
        for (i = 1; i * i < n; i++) {
            for (j = i + 1; 2 * i * j + j * j - i * i + j * j + i * i <= n; j++) {
                a = 2 * i * j;
                b = j * j - i * i;
                c = j * j + i * i;
                if (gcd(a, gcd(b, c)) == 1) {
                    sum = a + b + c;
                    if (n % sum == 0) {
                        counter++;
                    }
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 
// Problem#: 1500
// Submission#: 2494248
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int isprime(int n) {
    int i;
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}
int main() {
    int n, left, right;
    while (scanf("%d", &n), n) {
        if (n != 2 && n % 2 == 0) {
            left = n - 1;
            right = n + 1;
        }
        else {
            left = right = n;
        }
        while (1) {
            if (isprime(left))
                break;
            left -= 2;
        }
        while (1) {
            if (isprime(right))
                break;
            right += 2;
        }
        printf("%d\n", right - left);
    }
    return 0;
}                                 
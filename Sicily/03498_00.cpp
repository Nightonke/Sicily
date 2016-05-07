// Problem#: 3498
// Submission#: 2378950
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    long int t, v, i, n;
    scanf("%ld", &t);
    while (t--) {
        scanf("%ld", &n);
        while(n % 2 == 0 && n != 2) {
            printf("2 ");
            n = n / 2;
        }
        v = sqrt(n);
        for (i = 3; i <= v; i = i + 2) {
            while (v >= i) {
                if (n % i == 0) {
                    printf("%ld ", i);
                    n = n / i;
                    v = sqrt(n);
                }
                else
                    break;
            }
        }
        printf("%ld \n", n);
    }
    return 0;
}                                 
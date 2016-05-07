// Problem#: 1009
// Submission#: 2693618
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>

int j = 0, primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 100, 100};
long long f[100];

void fac(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            fac(i);
            fac(n / i);
            return;
        }
    }
    f[j++] = n;
}

void swap(int a, int b) {
    int temp = f[a];
    f[a] = f[b];
    f[b] = temp;
}

bool is_prime(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int k, i, max, u, o;
    scanf("%d", &k);
    for (i = 0; ; i++) {
        if (k < primes[i]) {
            max = i - 1;
            break;
        }
    }
    for (i = 0; i <= max; i++) {
        if (!is_prime((long long)pow(2.0, primes[i]) - 1)) {
            memset(f, 0, sizeof(f));
            j = 0;
            fac((long long)pow(2.0, primes[i]) - 1);
            for (u = 0; u < j; u++) {
                for (o = 0; o < j - u - 1; o++) {
                    if (f[o] > f[o + 1]) {
                        swap(o, o + 1);
                    }
                }
            }
            printf("%lld", f[0]);
            for (o = 1; o < j; o++) {
                printf(" * %lld", f[o]);
            }
            printf(" = %lld = ( 2 ^ %d ) - 1\n", (long long)pow(2.0, primes[i]) - 1, primes[i]);
            
        }
    }
    return 0;
}                                 
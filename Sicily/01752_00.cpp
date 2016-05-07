// Problem#: 1752
// Submission#: 2510740
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int primes[800000];
int numbers[2000001];
int makeprimes() {
    memset(numbers, 0, sizeof(numbers));
    int i = 0, k, j;
    for (k = 2; k < 1000001; k++) {
        if (numbers[k] == 0) {
            primes[i++] = k;
            for (j = 2; j * k < 1000001; j++)
                numbers[j * k] = 1;
        }
    }
    return i;
}
int bsearch(int n, int start, int end) {
    if (n == primes[(start + end) / 2])
        return (start + end) / 2;
    if (n > primes[(start + end) / 2])
        return bsearch(n, (start + end) / 2 + 1, end);
    if (n < primes[(start + end) / 2])
        return bsearch(n, start, (start + end) / 2 - 1);
}
int main() {
    int i, n;
    i = makeprimes();
    while (scanf("%d", &n), n != -1) {
        printf("%d\n", bsearch(n, 0, i) + 1);
    }
    return 0;
}                                 
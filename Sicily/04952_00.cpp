// Problem#: 4952
// Submission#: 2704578
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    long long int base[30], n;
    int i, counter;
    for (i = 0; i <= 26; i++) {
        base[i] = (long long int)pow(3, i);
    }
    while (scanf("%lld", &n), n) {
        counter = 0;
        while (n > 3) {
            for (i = 0; base[i] <= n; i++);
            n = n - base[i - 1];
            counter++;
        }
        if (n == 3)
            counter += 2;
        if (n == 2)
            counter += 1;
        if (n == 1)
            counter += 0;
        if (counter % 3 == 0)
            printf("P\n");
        if (counter % 3 == 1)
            printf("S\n");
        if (counter % 3 == 2)
            printf("R\n");
    }
    return 0;
}                                 
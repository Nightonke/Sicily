// Problem#: 2010
// Submission#: 2440407
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    long long int n, i, i1, j, counter, counter2 = 0, k, a[10];
    scanf("%lld", &n);
    for (i = 101; i <= n; i++) {
        a[0] = a[1] = a[2] = a[3] = a[4] = a[5] = a[6] = a[7] = a[8] = a[9] = a[10] = 0;
        i1 = i;
        j = 0;
        counter = 0;
        while (i1 > 0) {
            a[j] = i1 % 10;
            j++;
            i1 = i1 / 10;
        }
        for (k = 1; k < j - 1; k++)
            if ((a[k] == a[k - 1] + a[k + 1]) || (a[k] * a[k] == (a[k - 1] - a[k + 1]) * (a[k - 1] - a[k + 1])))
                counter++;
        if (counter == j - 2)
            counter2++;
    }
    if (n >= 101)
        printf("%lld\n", counter2 + 99);
    if (n == 100)
        printf("99\n");
    if (n < 100)
        printf("%lld\n", n);
    return 0;
}                                 
// Problem#: 3980
// Submission#: 2447800
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    long long int t, sum, k, i;
    char a[100];
    scanf("%lld", &t);
    while (t--) {
        sum = k = 0;
        scanf("%s", a);
        for (i = strlen(a) - 1; i >= 0; i--) {
            a[i] = a[i] - '0';
            sum = sum + a[i] * (int)pow(2, k);
            k++;
        }
        printf("%lld\n", sum);
    }
    return 0;
}                                 
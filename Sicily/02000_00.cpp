// Problem#: 2000
// Submission#: 2363955
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    long int n, cishu, b[25000], i = 0, j, counter, sum = 0, c[3], k = 0;
    double a[25000], m = 0;
    scanf("%ld", &n);
    cishu = 3;
    while (n--) {
        scanf("%lf%ld", &a[i], &b[i]);
        a[i] = a[i] / b[i];
        i++;}
    while (cishu--) {
        for (j = 0; j<=i; j++) {
            if (m < a[j]) {
                m = a[j];
                counter = j;
            }
        }
        sum = sum + b[counter];
        c[k] = counter;
        k++;
        a[counter] = b[counter] = 0;
        m = 0;
    }
    printf("%ld\n%ld\n%ld\n%ld\n", sum, c[0] + 1, c[1] + 1, c[2] + 1);
    return 0;
}                                 
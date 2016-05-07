// Problem#: 1766
// Submission#: 2511023
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, n, add1, add11, add1need, add2, add22, add2need, sum, sum1, sumneed, counter;
    while (scanf("%d", &n) == 1) {
        n = n - 4;
        counter = 0;
        for (add1 = 0; add1 < 1001; add1++) {
            add11 = add1;
            add1need = 0;
            if(add11 == 0)
                add1need = 6;
            while (add11 > 0 && add1need < n) {
                add1need = add1need + a[add11 % 10];
                add11 /= 10;
            }
            for (add2 = 0; add2 < 1001; add2++) {
                add22 = add2;
                add2need = 0;
                if (add22 == 0)
                    add2need = 6;
                while (add22 > 0 && add2need < n) {
                    add2need = add2need + a[add22 % 10];
                    add22 /= 10;
                }
                sum = add1 + add2;
                sum1 = sum;
                sumneed = 0;
                if (sum1 == 0)
                    sumneed = 6;
                while (sum1 > 0 && sumneed < n) {
                    sumneed = sumneed + a[sum1 % 10];
                    sum1 /= 10;
                }
                if (add1need + add2need + sumneed == n)
                    counter++;
            }
        }
        if (n > 8)
            printf("%d\n", counter);
        else
            printf("0\n");
    }
    return 0;
}                                 
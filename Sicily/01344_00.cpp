// Problem#: 1344
// Submission#: 2455382
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    int k, n, i, a[100], sum, j;
    while(scanf("%d%d",&k,&n)!=EOF) {
        sum = 0;
        for (i = 0; n > 0; i++) {
            a[i] = n % 2;
            n = n / 2;
        }
        for (j = 0; j < i; j++) {
            sum = sum + a[j] * (int)pow(k, j);
        }
        printf("%d\n", sum);
    }
    return 0;
}                                 
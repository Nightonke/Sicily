// Problem#: 3913
// Submission#: 2368833
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    long int i, j, n, mul = 1, sum = 0;
    scanf("%ld", &n);
    if (n <=30) {
    for(i = 1; i <=n; i++) {
        for(j = 1; j <=i; j++) {
            mul = mul * j % 1000000;}
        sum = sum + mul;
        mul = 1;}
    printf("%ld\n", sum % 1000000);}
    if (n > 30)
        printf("940313\n");
    return 0;
}                                 
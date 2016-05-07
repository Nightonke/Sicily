// Problem#: 1119
// Submission#: 2579422
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    int year, i;
    double sum, power;
    while (scanf("%d", &year), year) {
        power = pow(2, (year - 1960) / 10 + 2);
        sum = 0;
        i = 2;
        while (1) {
            sum += log(i) / log(2);
            if (sum >= power)
                break;
            i++;
        }
        printf("%d\n", i - 1);
    }
    return 0;
}                                 
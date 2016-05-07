// Problem#: 6582
// Submission#: 2709154
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    int counter = 0, i;
    double r[4], R, sum;
    while (scanf("%lf%lf%lf%lf", &R, &r[1], &r[2], &r[3]), r[1] != -1) {
        counter++;
        for (i = 1, sum = 0; i <= 3; i++) {
            sum += 2 * R * sqrt(R * r[i]) / (R - r[i]);
        }
        printf("Case %d: %.2lf\n", counter, sum * R);
    }
    return 0;
}                                 
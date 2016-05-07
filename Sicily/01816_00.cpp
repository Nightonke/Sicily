// Problem#: 1816
// Submission#: 2701271
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main() {
    int t;
    double r1;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf", &r1);
        printf("%.4lf %.4lf\n", PI * r1 * r1, PI * 2 * r1);
        printf("%.4lf %.4lf %.4lf\n", pow(2 * r1, 2), 8 * r1, 2 * pow(r1 * r1 * 2, 0.5));
        printf("%.4lf %.4lf\n", pow(pow(r1 * r1 * 2, 0.5), 2) * PI, 2 * PI * pow(r1 * r1 * 2, 0.5));
        printf("%.4lf %.4lf\n", pow(pow(r1 * r1 * 2, 0.5), 2) * 3 * pow(3, 0.5), 6 * pow(3, 0.5) * pow(r1 * r1 * 2, 0.5));
    }
    return 0;
}                                 
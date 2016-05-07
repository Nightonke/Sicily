// Problem#: 1621
// Submission#: 2602081
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#define PI 2*acos(0)

int findsame(int t1, int t2, int t3) {
    if (t1 != t2)
        return t3;
    else
        return t1;
}

int main() {
    int t, t1, t2, t3, a, b;
    double r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &t1, &t2, &t3);
        a = findsame(t1, t2, t3);
        b = t1 + t2 + t3 - 2 * a;
        if (3 * b <= 2 * a) {
            printf("%.3lf\n", 2 * a * 2 * a * PI);
        }
        else {
            r = ((a + b) * (a + b) + 2 * b * sqrt((1.0 * a + b) * (a + b) - a * a) + b * b - a * a) / (2 * sqrt((a + b) * (a + b) - a * a) + 2.0 * b - 2 * a);
            printf("%.3lf\n", r * r * PI);
        }
    }
    return 0;
}                                 
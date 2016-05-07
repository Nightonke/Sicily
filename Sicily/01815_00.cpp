// Problem#: 1815
// Submission#: 2448456
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    int t;
    double x1, x2, y1, y2;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        printf("%.2lf\n", sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    }
    return 0;
}                                 
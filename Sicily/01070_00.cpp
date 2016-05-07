// Problem#: 1070
// Submission#: 2568730
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#define pi 3.14159265
#define esp 0.0005

double judge(double n) {
    if (n < 90)
        return tan((90 - n) / 180 * pi);
    if (n >= 90 && n < 180)
        return tan((270 - n) / 180 * pi);
    if (n > 180 && n < 270)
        return tan((270 - n) / 180 * pi);
    if (n >= 270)
        return tan((450 - n) / 180 * pi);
}

int main() {
    int t, kongzhi, k1inex, k2inex;
    double x1, x2, a1, y1, y2, a2, x, y, k1, k2;
    scanf("%d", &t);
    while (t--) {
        kongzhi = k1inex = k2inex = 0;
        scanf("%lf %lf %lf", &x1, &y1, &a1);
        scanf("%lf %lf %lf", &x2, &y2, &a2);
        if (a1 == 90 || a1 == 270) {
            y = y1;
            kongzhi++;
        }
        if (a1 == 0 || a1 == 180) {
            x = x1;
            kongzhi++;
            k1inex = 1;
            
        }
        if (a2 == 90 || a2 == 270) {
            y = y2;
            kongzhi++;
        }
        if (a2 == 0 || a2 == 180) {
            x = x2;
            kongzhi++;
            k2inex = 1;
        }
        if (kongzhi == 2) {
            printf("%.4lf %.4lf\n", x, y);
            continue;
        }
        if (a1 != 0 && a1 != 180) {
            k1 = judge(a1);
        }
        if (a2 != 0 && a2 != 180) {
            k2 = judge(a2);
        }
        if (k1inex == 0 && k2inex == 0) {
            x = (k1 * x1 - k2 * x2 + y2 - y1) / (k1 - k2);
            y = k1 * (x - x1) + y1;
        }
        if (k1inex) {
            x = x1;
            y = k2 * (x - x2) + y2;
        }
        if (k2inex) {
            x = x2;
            y = k1 * (x - x1) + y1;
        }
        if (fabs(x) < esp)
            x = 0;
        if (fabs(y) < esp)
            y = 0;
        printf("%.4lf %.4lf\n", x, y);
    }
    return 0;
}                                 
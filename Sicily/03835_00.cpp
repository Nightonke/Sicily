// Problem#: 3835
// Submission#: 2367924
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main () {
    double x1, x2, x3, y1, y2, y3, c1, c2, c3, zhouchang;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
        c1 = pow((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2), 0.5);
        c2 = pow((x1 - x3)*(x1 - x3)+(y1 - y3)*(y1 - y3), 0.5);
        c3 = pow((x2 - x3)*(x2 - x3)+(y2 - y3)*(y2 - y3), 0.5);
        zhouchang = c1+c2+c3;
        printf("%.5lf\n", zhouchang);
    }
    return 0;
}                                 
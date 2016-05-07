// Problem#: 1741
// Submission#: 2508078
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
struct point{
    double x, y;
}p[1001];
double s(int n) {
    double s = 0;
    int i;
    for (i = 0; i < n - 1; i++) {
        s = s + p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
    }
    s = s + p[n - 1].x * p[i].y - p[n - 1].y * p[i].x;
    return fabs(s) / 2;
}
int main() {
    int t, n;
    int i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        n = n + 2;
        for (i = 1; i < n - 1; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        p[0].x = p[1].x;
        p[0].y = 0;
        p[n - 1].x = p[n - 2].x;
        p[n - 1].y = 0;
        printf("%.1lf\n", s(n));
    }
    return 0;
}                                 
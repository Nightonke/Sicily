// Problem#: 1179
// Submission#: 2486114
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
struct point{
    float x;
    float y;
}p[600];
float get_area(int n) {
    float s = 0;
    int i;
    for (i = 0; i < n - 1; i++) {
        s = s + p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
    }
    s = s + p[n - 1].x * p[0].y - p[n - 1].y * p[0].x;
    return s > 0 ? s / 2 : -s / 2;
}
int main() {
    int n, i;
    float v;
    while (scanf("%d", &n),n >= 3) {
        for (i = 0; i < n; i++)
            scanf("%f %f", &p[i].x, &p[i].y);
        scanf("%f", &v);
        printf("BAR LENGTH: %.2f\n", v / get_area(n));
    }
    return 0;
}                                 
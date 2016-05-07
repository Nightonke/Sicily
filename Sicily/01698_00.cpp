// Problem#: 1698
// Submission#: 2610669
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#define PI acos(-1)

double solve1(int a, int b, int c) {
    double l = a, d = b, s = c;
    return PI * 1.0 * s * s;
}

double solve2(int a, int b, int c) {
    double l = a, d = b, s = c;
    double An, S;
    An = 2 * PI - 2 * acos(1.0 * d / s);
    S = 1.0 * d * sqrt(1.0 * s * s - d * d);
    return PI * s * s * (An / (2 * PI)) + S;
}

double solve3(int a, int b, int c) {
    double l = a, d = b, s = c;
    double r, R, an, An, S;
    S = 1.0 * d * l / 2;
    r = s - sqrt(1.0 * d * d + (1.0 * l / 2) * (1.0 * l / 2));
    R = 1.0 * s;
    An = 2 * PI - 2 * acos(1.0 * d / (sqrt(1.0 * d * d + (1.0 * l / 2) * (1.0 * l / 2))));
    an = PI - (PI / 2 - acos(1.0 * d / (sqrt(1.0 * d * d + (1.0 * l / 2) * (1.0 * l / 2)))));
    return S + 2 * (an / (2 * PI) * r * r * PI) + An / (2 * PI) * R * R * PI;
}

double solve4(int a, int b, int c) {
    double l = a, d = b, s = c;
    double r, R, an, An, x1, x2, twice, S;
    S = 1.0 * d * l / 2;
    r = s - sqrt(1.0 * d * d + (1.0 * l / 2) * (1.0 * l / 2));
    R = 1.0 * s;
    An = 2 * PI - 2 * acos(1.0 * d / (sqrt(1.0 * d * d + (1.0 * l / 2) * (1.0 * l / 2))));
    an = PI - (PI / 2 - acos(1.0 * d / (sqrt(1.0 * d * d + (1.0 * l / 2) * (1.0 * l / 2)))));
    x1 = 1.0 * l / 2 - r;
    x2 = 0;
    twice = 2 * ((acos((l / 2) / r) / (2 * PI)) * r * r * PI - (1.0 / 2) * (l / 2) * r * sin(acos((l / 2) / r)));
    return S + 2 * (an / (2 * PI) * r * r * PI) + An / (2 * PI) * R * R * PI - twice;
}
    
int main() {
    int t, l, d, s;
    double ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &l, &d, &s);
        if (s == 0) {
            printf("0.00\n");
            continue;
        }
        if (s <= d)
            ans = solve1(l, d, s);
        else if (l * l + 4 * d * d >= 4 * s * s)
            ans = solve2(l, d, s);
        else if (l * l + 4 * d * d < 4 * s * s && s * s - s * l <= d * d)
            ans = solve3(l, d, s);
        else if (s * s - s * l > d * d)
            ans = solve4(l, d, s);
        printf("%.2lf\n", ans);
    }
    return 0;
}                                 
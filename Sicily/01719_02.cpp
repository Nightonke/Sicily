// Problem#: 1719
// Submission#: 3585206
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

const double pi = acos(-1.0);
double a1, b1, a2, b2;

double solve() {
    if (a1 <= a2) return pi * a1 * b1;
    if (b1 >= b2) return pi * a2 * b2;
    double ans;
    double x, y;
    x = sqrt((b1 * b1 - b2 * b2) * a1 * a1 * a2 * a2 / (b1 * b1 * a2 * a2 - b2 * b2 * a1 * a1));
    y = sqrt((a1 * a1 - a2 * a2) * b1 * b1 * b2 * b2 / (a1 * a1 * b2 * b2 - b1 * b1 * a2 * a2));
    double theta1 = asin(y / b1), theta2 = asin(y / b2);
    ans = a1 * b1 * ((pi - 2 * theta1) + sin(2 * theta1)) + a2 * b2 * (2 * theta2 + sin(2 * theta2)) - 4 * x * y;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
        printf("%.3lf\n", solve());
    }
    return 0;
}                                 
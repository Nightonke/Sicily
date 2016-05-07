// Problem#: 1237
// Submission#: 2727623
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int step;
    double c, tolerance = 0.00001, rate_b_in_b, rate_b_in_w, rate, b, w;
    while (scanf("%lf%lf%lf", &b, &w, &c), b || w || c) {
        step = 0;
        rate_b_in_b = 1;
        rate_b_in_w = 0;
        rate = b / w;
        b *= 16;
        w *= 16;
        while (fabs(rate_b_in_b / (1 - rate_b_in_b) - rate) > tolerance || fabs(rate_b_in_w / (1 - rate_b_in_w) - rate) > tolerance) {
            rate_b_in_w = (c * rate_b_in_b + w * rate_b_in_w) / (c + w);
            rate_b_in_b = (c * rate_b_in_w + (b - c) * rate_b_in_b) / b;
            step++;
        }
        printf("%d\n", step);
    }
    return 0;
}                                 
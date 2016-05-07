// Problem#: 2658
// Submission#: 3592930
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

struct Line {
    double p1[3], p2[3];
}l1, l2;

double getDis(double t1, double t2) {
    double ret = 0;
    for (int i = 0; i < 3; i++) {
        double a = l1.p1[i] + (l1.p2[i] - l1.p1[i]) * t1;
        double b = l2.p1[i] + (l2.p2[i] - l2.p1[i]) * t2;
        ret += (a - b) * (a - b);
    }
    return sqrt(ret);
}

double getMinDis(double t1) {
    double t2 = 0.0, step = 100.0;
    double ret = 1e10;
    while (step > 1e-6) {
        double last_ret;
        do {
            last_ret = ret;
            double tmp = getDis(t1, t2 + step);
            if (tmp < ret) {
                t2 += step;
                ret = tmp;
            }
            tmp = getDis(t1, t2 - step);
            if (tmp < ret) {
                t2 -= step;
                ret = tmp;
            }
        } while (ret != last_ret);
        step /= 2;
    }
    return ret;
}

int main() {
    int n;
    while (scanf("%d", &n), n) {
        if (n == 2) {
            scanf("%lf%lf", &l1.p1[0], &l1.p1[1]);
            scanf("%lf%lf", &l1.p2[0], &l1.p2[1]);
            scanf("%lf%lf", &l2.p1[0], &l2.p1[1]);
            scanf("%lf%lf", &l2.p2[0], &l2.p2[1]);
            l1.p1[2] = l1.p2[2] = l2.p1[2] = l2.p2[2] = 0;
        } else {
            scanf("%lf%lf%lf", &l1.p1[0], &l1.p1[1], &l1.p1[2]);
            scanf("%lf%lf%lf", &l1.p2[0], &l1.p2[1], &l1.p2[2]);
            scanf("%lf%lf%lf", &l2.p1[0], &l2.p1[1], &l2.p1[2]);
            scanf("%lf%lf%lf", &l2.p2[0], &l2.p2[1], &l2.p2[2]);
        }
        double t1 = 0.0, step = 100.0;
        double ans = 1e10;
        while (step > 1e-6) {
            double last_ans;
            do {
                last_ans = ans;
                double tmp = getMinDis(t1 + step);
                if (tmp < ans) {
                    t1 += step;
                    ans = tmp;
                }
                tmp = getMinDis(t1 - step);
                if (tmp < ans) {
                    t1 -= step;
                    ans = tmp;
                }
            } while (ans != last_ans);
            step /= 2;
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}                                 
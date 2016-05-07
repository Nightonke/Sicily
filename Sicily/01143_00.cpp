// Problem#: 1143
// Submission#: 3587467
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#include <string.h>

const int maxn = 100;

long n;

struct point {
    double x, y;
}p[maxn + 1];

struct line {
    double a, b, c;
};

double ans;
point ans_p;
char ans_k;

void check(point p1, char k) {
    long i;
    double cur, min;
    for (i = 0; i < n; i++) {
        cur = (p[i].x - p1.x) * (p[i].x - p1.x) + (p[i].y - p1.y) * (p[i].y - p1.y);
        if (i == 0 || cur < min) min = cur;
    }
    if (min > ans) {
        ans = min;
        ans_p = p1; 
        ans_k = k;
    }
}

line straightline(point p1, point p2) {
    line l;
    l.a = p2.y - p1.y;
    l.b = p1.x - p2.x;
    l.c = -l.a * p1.x - l.b * p1.y;
    return l;
}

line midline(point p1, point p2) {
    line l;
    l.a = p1.x - p2.x;
    l.b = p1.y - p2.y;
    l.c = -l.a * (p1.x + p2.x) / 2.0 - l.b * (p1.y + p2.y) / 2.0;
    return l;
}

bool cross(point p1, point p2, line l) {
    return ((l.a * p1.x + l.b * p1.y + l.c) * (l.a * p2.x + l.b * p2.y + l.c) <= 0);
}

point crosspoint(line l1, line l2) {
    point p1;
    p1.x = (-l1.c * l2.b + l1.b * l2.c) / (l1.a * l2.b - l1.b * l2.a);
    p1.y = (-l1.a * l2.c + l1.c * l2.a) / (l1.a * l2.b - l1.b * l2.a);
    return p1;
}

void process() {
    long i, j, k;
    line l, l2;
    point la, lb, c;
    ans = 0;
    p[n] = p[0];
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++) {
            l = midline(p[i], p[j]);
            for (k = i; k != j; k = (k + 1) % n) {
                if (cross(p[k], p[k + 1], l)) {
                    la = crosspoint(straightline(p[k], p[k + 1]), l);
                    break;
                }
            }
            if (k == j) printf("ERROR\n");
            for (k = j; k != i; k = (k + 1) % n) {
                if (cross(p[k], p[k + 1], l)) {
                    lb = crosspoint(straightline(p[k], p[k + 1]), l);
                    break;
                }
            }
            if (k == i) printf("ERROR\n");
            check(la, 'e');
            check(lb, 'e');
            for (k = 0; k < n; k++) 
                if (k != i && k != j) {
                    l2 = midline(p[i], p[k]);
                    if (cross(la, lb, l2)) {
                        c = crosspoint(l2, l);
                        check(c, 'i');
                    }
                }
        }
    printf("%.3lf\n", sqrt(ans));
}

int main() {
    while (scanf("%ld", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        process();
    }
    return 0;
}                                 
// Problem#: 1724
// Submission#: 3585435
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string.h>
#include <stdio.h>
#include <math.h>

#define eps 1e-10
#define MAXN 310

struct point {
    double x, y;
};

struct cp {
    long n;
    point p[MAXN];
};

point reverseP(point inp, double a, double b, double c) {
    point ret;
    ret.x = -((a * a - b * b) * inp.x + 2.0 * a * b * inp.y + 2.0 * a * c) / (a * a + b * b);
    if (fabs(a) < eps) ret.y = -2.0 * c / b - inp.y;
    else ret.y = b * (ret.x - inp.x) / a + inp.y;
    return ret;
}

cp reverseCP(cp incp, double a, double b, double c) {
    long i, j;
    cp ret;
    ret.n = incp.n;
    for (i = incp.n - 1, j = 0; i >= 0; i--, j++) ret.p[j] = reverseP(incp.p[i], a, b, c);
    return ret;
}

point intersectL(double a1, double b1, double c1, double a2, double b2, double c2) {
    point ret;
    ret.y = (a1 * c2 - c1 * a2) / (b1 * a2 - a1 * b2);
    if (fabs(a2) < eps) ret.x = -(b1 * ret.y + c1) / a1;
    else ret.x = -(b2 * ret.y + c2) / a2;
    return ret;
}

bool isEqual(point inpA, point inpB) {
    if (fabs(inpA.x - inpB.x) < eps && fabs(inpA.y - inpB.y) < eps) return true;
    return false;
}

cp cut(point inpA, point inpB, cp incp) {
    cp ret;
    point cross;
    long i, j;
    double t1, t2;
    ret.n = 0;
    for (i = 0; i < incp.n; i++) {
        j = (i + 1) % incp.n;
        t1 = (inpB.x - inpA.x) * (incp.p[i].y - inpA.y) - (inpB.y - inpA.y) * (incp.p[i].x - inpA.x);
        t2 = (inpB.x - inpA.x) * (incp.p[j].y - inpA.y) - (inpB.y - inpA.y) * (incp.p[j].x - inpA.x);
        if (t1 < eps && t2 < eps) {
            ret.p[ret.n++] = incp.p[i];
            ret.p[ret.n++] = incp.p[j];
        } else if (t1 > eps && t2 > eps) continue;
        else {
            cross = intersectL(inpB.y - inpA.y,
                               inpA.x - inpB.x,
                               inpA.y * (inpB.x - inpA.x) - inpA.x * (inpB.y - inpA.y),
                               incp.p[j].y - incp.p[i].y,
                               incp.p[i].x - incp.p[j].x,
                               incp.p[i].y * (incp.p[j].x - incp.p[i].x) - incp.p[i].x * (incp.p[j].y - incp.p[i].y));
            if (t1 < eps) {
                ret.p[ret.n++] = incp.p[i];
                ret.p[ret.n++] = cross;
            } else {
                ret.p[ret.n++] = cross;
                ret.p[ret.n++] = incp.p[j];
            }
        }
    }
    for (i = j = 1; i < ret.n; i++)
        if (!isEqual(ret.p[i - 1], ret.p[i])) ret.p[j++] = ret.p[i];
    ret.n = j;
    return ret;
}

cp intersectCP(cp incpA, cp incpB) {
    cp ret = incpB;
    for (long i = 0; i < incpA.n; i++) ret = cut(incpA.p[i], incpA.p[(i + 1) % incpA.n], ret);
    return ret;
}

point findCentriod(cp incp, double & area) {
    point ret;
    double sumx, sumy, t;
    long i, j;
    area = 0;
    sumx = sumy = 0.0;
    for (i = 1; i < incp.n - 1; i = j) {
        j = i + 1;
        t = (incp.p[j].x - incp.p[0].x) * (incp.p[i].y - incp.p[0].y) - (incp.p[j].y - incp.p[0].y) * (incp.p[i].x - incp.p[0].x);
        area += t;
        sumx += t * (incp.p[0].x + incp.p[i].x + incp.p[j].x) / 3.0;
        sumy += t * (incp.p[0].y + incp.p[i].y + incp.p[j].y) / 3.0;
    }
    if (area < eps) area = -area, sumx = -sumx, sumy = -sumy;
    if (fabs(area) < eps) ret.x = ret.y = 0;
    else ret.x = sumx / area, ret.y = sumy / area;
    area *= 0.5;
    return ret;
}

double calV(cp incp, double a, double b, double c) {
    double area = 0.0;
    point centriod = findCentriod(incp, area);
    double d = fabs(a * centriod.x + b * centriod.y + c) / sqrt(a * a + b * b);
    return 4.0 * acos(0.0) * area * d;
}

int main() {
    long T, i;
    cp input, image, inter;
    point pa, pb;
    double a, b, c, v1, v2, v3;
    
    scanf("%ld", &T);
    while (T--) {
        scanf("%ld", &input.n);
        for (i = 0; i < input.n; i++) scanf("%lf%lf", &input.p[i].x, &input.p[i].y);
        scanf("%lf%lf%lf", &a, &b, &c);
        image = reverseCP(input, a, b, c);
        inter = intersectCP(input, image);
        if (fabs(b) < eps) {
            pa.x = pb.x = -c / a;
            pa.y = -10000.0;
            pb.y = 10000.0;
        } else {
            pa.x = 0.0;
            pa.y = -c / b;
            pb.x = 10000.0;
            pb.y = -(c + a * 10000.0) / b;
        }
        v1 = calV(cut(pa, pb, input), a, b, c);
        v2 = calV(cut(pa, pb, image), a, b, c);
        v3 = calV(cut(pa, pb, inter), a, b, c);
        printf("%.1lf\n", v1 + v2 - v3);
    }
    return 0;
}                                 
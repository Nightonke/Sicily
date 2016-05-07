// Problem#: 1943
// Submission#: 3589408
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

class point {
public:
    int x, y;
    bool operator < (const point & that) const {
        long long result;
        result = ((long long)x) * that.y - ((long long)y) * that.x;
        if (result == 0) return x * x + y * y < that.x * that.x + that.y * that.y;
        else return result > 0;
    }
    bool operator > (const point & that) const {
        return ((long long)x) * that.y < ((long long)y) * that.x;
    }
    bool operator == (const point & that) const {
        return x == that.x && y == that.y;
    }
};

point operator - (const point & a, const point & b) {
    point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

void covex_hull(point pointset[], int & n) {
    if (n <= 1) return;
    int i, k, top;
    point tmp, origin;
    for (k = 0, i = 1; i < n; i++)
        if ((pointset[i].y < pointset[k].y) || ((pointset[i].y == pointset[k].y) && (pointset[i].x < pointset[k].x))) k = i;
    tmp = pointset[0], pointset[0] = pointset[k], pointset[k] = tmp;
    for (i = 1; i < n; i++) pointset[i] = pointset[i] - pointset[0];
    sort(pointset + 1, pointset + n);
    origin = pointset[0];
    pointset[0].x = pointset[0].y = 0;
    top = 1;
    for (i = 2; i < n; i++) {
        while (!(pointset[i] - pointset[top - 1] > pointset[top] - pointset[top - 1]) && top >= 1) top--;
        pointset[++top] = pointset[i];
    }
    n = top + 1;
    for (i = 0; i < n; i++) {
        pointset[i].x += origin.x;
        pointset[i].y += origin.y;
    }
    if (n == 2 && pointset[0] == pointset[1]) n = 1;
}

const int MAXN = 100000 * 2;
int n;
point p[MAXN];
double ans;

long long mydis2(point a, point b) {
    return ((long long)(a.x - b.x)) * (a.x - b.x) + ((long long)(a.y - b.y)) * (a.y - b.y);
}

long double myabs(long double a) {
    if (a < 0) return -a; return a;
}

long double pointtoline(point p, point a, point b) {
    long double la2, lb2, ab2;
    double cosa;
    la2 = mydis2(p, a);
    if (la2 == 0) return 0;
    lb2 = mydis2(p, b);
    ab2 = mydis2(a, b);
    cosa = (((long double)la2) + ab2 - lb2) / (2 * sqrtl(la2) * sqrtl(ab2));
    return myabs(sqrtl(la2) * sqrtl(1 - cosa * cosa));
}

double dis(point a, point b) {
    long double r = a.x, r1 = a.y;
    r = (r - b.x) * (r - b.x) + (r1 - b.y) * (r1 - b.y);
    return sqrtl(r);
}

void check(point a, point b) {
    if ((a.x < 0) != (b.x < 0)) {
        double tmp1 = dis(a, b);
        if (tmp1 > ans) ans = tmp1;
    }
}

int main() {
    int cs;
    scanf("%d", &cs);
    while (cs--) {
        n = 0;
        int i, j, k;
        scanf("%d%d", &i, &j);
        while (i--) scanf("%d%d", &p[n].x, &p[n].y), n++;
        while (j--) scanf("%d%d", &p[n].x, &p[n].y), n++;
        covex_hull(p, n);
        double tmp1, tmp2;
        ans = 0;
        j = 1;
        for (i = 0; i < n; i++) {
            while (1) {
                tmp1 = pointtoline(p[j], p[i], p[(i + 1) % n]);
                tmp2 = pointtoline(p[(j + 1) % n], p[i], p[(i + 1) % n]);
                if (tmp2 < tmp1 - 1e-6) break;
                else j = (j + 1) % n;
            }
            check(p[i], p[j]);
            check(p[(i + 1) % n], p[j]);
            check(p[i], p[(j + 1) % n]);
            check(p[(i + 1) % n], p[(j + 1) % n]);
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}                                 
// Problem#: 1955
// Submission#: 3593362
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>

const int MAXN = 100005;
const int MAXV = 20005;
const double EPS = 1e-4;
const double INF = 1e12;

class node {
public:
    node() {}
    node(double px, double py) {
        x = px;
        y = py;
    }
    node& operator = (node b) {
        x = b.x;
        y = b.y;
        return *this;
    }
    double x, y;
};

int n;
double minY[MAXV], maxY[MAXV];
node p[MAXN];

void preProcess() {
    int i;
    for (i = 0; i < MAXV; i++) minY[i] = INF, maxY[i] = -INF;
    for (i = 0; i < n; i++) {
        int x = (int)p[i].x;
        if (minY[x] > p[i].y) minY[x] = p[i].y;
        if (maxY[x] < p[i].y) maxY[x] = p[i].y;
    }
}

double crossProduct(node a, node b, node c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

void findConvexHull() {
    node stackUp[MAXV], stackDown[MAXV];
    int topUp, topDown;
    preProcess();
    int i;
    for (i = 0; i < MAXV; i++)
        if (maxY[i] > -INF) break;
    stackUp[0] = node(i, maxY[i]);
    stackDown[0] = node(i, minY[i]);
    topUp = topDown = 0;
    for (i++; i < MAXV; i++) {
        if (maxY[i] > -INF) {
            while (topUp >= 1 && crossProduct(stackUp[topUp - 1], stackUp[topUp], node(i, maxY[i])) >= -EPS)
                topUp--;
            stackUp[++topUp] = node(i, maxY[i]);
            while (topDown >= 1 && crossProduct(stackDown[topDown - 1], stackDown[topDown], node(i, minY[i])) <= EPS)
                topDown--;
            stackDown[++topDown] = node(i, minY[i]);
        }
    }
    n = 0;
    for (i = 0; i <= topDown; i++) p[n++] = stackDown[i];
    int from = topUp, to = 0;
    if (stackUp[topUp].x == stackDown[topDown].x && stackUp[topUp].y == stackDown[topDown].y)
        from--;
    if (stackUp[0].x == stackDown[0].x && stackUp[0].y == stackDown[0].y)
        to++;
    for (i = from; i >= to; i--) p[n++] = stackUp[i];
}

double calcPolygonArea(node p[], int n) {
    double res = 0;
    for (int i = 0; i < n; i++)
        res += p[i].x * p[(i + 1) % n].y - p[i].y * p[(i + 1) % n].x;
    res *= 0.5;
    return fabs(res);
}

double calcTriangleArea(node a, node b, node c) {
    double res = 0;
    res += a.x * b.y - a.y * b.x;
    res += b.x * c.y - b.y * c.x;
    res += c.x * a.y - c.y * a.x;
    res *= 0.5;
    return fabs(res);
}

bool intersectXaxis(node p[], int n) {
    bool upper = false, lower = false;
    for (int i = 0; i < n; i++) {
        if (fabs(p[i].y) < EPS) return true;
        if (p[i].y > EPS) upper = true;
        else lower = true;
    }
    return upper && lower;
}

double calcXaxisIntersection(node a, node b) {
    if (a.y >= -EPS && b.y - a.y >= -EPS || a.y <= EPS && b.y - a.y <= EPS)
        return INF;
    return ((0 - a.y) * (b.x - a.x)) / (b.y - a.y) + a.x;
}

double MoveAndCalc(node p[], int n, double area) {
    double res, sum;
    int from = -1, to;
    double px = INF;
    for (int i = 0; i < n; i++) {
        double x = calcXaxisIntersection(p[i], p[(i + 1) % n]);
        if (from < 0 || x < px) {
            px = x;
            from = i;
        }
    }
    sum = 0;
    for (to = from; to != (from + n - 1) % n; to = (to + 1) % n) {
        double t = crossProduct(p[to], p[(to + 1) % n], node(px, 0));
        if (t >= EPS) break;
        sum += p[to].x * p[(to + 1) % n].y - p[to].y * p[(to + 1) % n].x;
    }
    res = area - (sum + p[to].x * p[from].y - p[to].y * p[from].x) / 2 + calcTriangleArea(p[from], node(px, 0), p[to]);
    do {
        sum -= p[from].x * p[(from + 1) % n].y - p[from].y * p[(from + 1) % n].x;
        from = (from + 1) % n;
        px = calcXaxisIntersection(p[from], p[(from + 1) % n]);
        if (px - INF >= -EPS) break;
        for (; ; to = (to + 1) % n) {
            double t = crossProduct(p[to], p[(to + 1) % n], node(px, 0));
            if (t >= -EPS) break;
            sum += p[to].x * p[(to + 1) % n].y - p[to].y * p[(to + 1) % n].x;
        }
        double t = area - (sum + p[to].x * p[from].y - p[to].y * p[from].x) / 2 + calcTriangleArea(p[from], node(px, 0), p[to]);
        if (t < res) res = t;
    } while (true);
    return res;
}

double solve() {
    int i;
    double res, area;
    findConvexHull();
    area = calcPolygonArea(p, n);
    if (intersectXaxis(p, n)) return area;
    if (p[0].y < -EPS) {
        for (i = 0; i + i < n; i++) {
            node temp = p[i];
            p[i] = p[n - 1 - i];
            p[n - 1 - i] = temp;
        }
        for (i = 0; i < n; i++) p[i].y = -p[i].y;
    }
    res = MoveAndCalc(p, n, area);
    for (i = 0; i + i < n; i++) {
        node temp = p[i];
        p[i] = p[n - 1 - i];
        p[n - 1 - i] = temp;
    }
    for (i = 0; i < n; i++) p[i].x = MAXV - 1 - p[i].x;
    double t = MoveAndCalc(p, n, area);
    if (t < res) res = t;
    return res;
}

int main() {
    int tn;
    scanf("%d", &tn);
    while (tn--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            p[i].x += MAXV / 2;
        }
        printf("%.3lf\n", solve());
    }
    return 0;
}                                 
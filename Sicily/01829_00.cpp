// Problem#: 1829
// Submission#: 3589892
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 300;
const double eps = 1e-4;

struct node {
    double x, y;
    double dist, angle;
}p[MAXN], ch[MAXN * 2];

int id[MAXN];
int stack[MAXN], top;
int n, k, chn;

double C(node & p1, node & p2, node & p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double area(node & p1, node & p2, node p3) {
    return fabs((p1.x * p2.y - p1.y * p2.x) + (p2.x * p3.y - p2.y * p3.x) + (p3.x * p1.y - p3.y * p1.x)) / 2.0;
}

void init() {
    int i, mid;
    mid = 0;
    for (i = 0; i < n; i++) {
        id[i] = i;
        if (p[i].y - p[mid].y < eps)
            if (fabs(p[i].y - p[mid].y) < eps) {
                if (p[i].x - p[mid].x < eps) mid = i;
            } else mid = i;
    }
    id[0] = mid;
    id[mid] = 0;
    p[id[0]].dist = 0;
    p[id[0]].angle = 0;
    for (i = 1; i < n; i++) {
        p[id[i]].dist = sqrt((p[id[i]].x - p[id[0]].x) * (p[id[i]].x - p[id[0]].x) + (p[id[i]].y - p[id[0]].y) * (p[id[i]].y - p[id[0]].y));
        p[id[i]].angle = acos((p[id[i]].x - p[id[0]].x) / p[id[i]].dist);
    }
}

bool cmp(const int & i, const int & j) {
    if (p[i].angle - p[j].angle < eps)
        if (fabs(p[i].angle - p[j].angle) < eps)
            if (p[i].dist - p[j].dist < eps)
                if (fabs(p[i].dist - p[j].dist) < eps)
                    return true;
                else
                    return true;
            else 
                return false;
        else 
            return true;
    else 
        return false;
}

void graham() {
    int i, t;
    top = 0;
    stack[top] = id[0];
    if (n == 1) return;
    stack[++top] = id[1];
    if (n == 2) return;
    stack[++top] = id[2];
    if (n == 3) return;
    for (i = 3; i < n; i++) {
        while (C(p[id[i]], p[stack[top]], p[stack[top - 1]]) > eps) top--;
        stack[++top] = id[i];
    }
    t = stack[top];
    for (i = n - 2; i >= 3; i--) {
        if (fabs(p[t].angle) < eps) break;
        if (fabs(p[id[i]].angle - p[t].angle) < eps) stack[++top] = id[i];
    }
}

void convexHull() {
    init();
    sort(id, id + n, cmp);
    graham();
    for (int i = 0; i <= top; i++) ch[i] = p[stack[i]];
    chn = top + 1;
}

double maxArea[MAXN][MAXN];
double maxResult;

double dynamic() {
    for (int i = 0; i < chn; i++) ch[i + chn] = ch[i];
    maxResult = 0;
    for (int i = 0; i < chn; i++) {
        memset(maxArea, 0, sizeof(maxArea));
        for (int j = i + 1; j < i + chn; j++) {
            maxArea[j][0] = -1;
            maxArea[j][1] = 0;
            for (int t = 2; t <= min(j - i + 1, k - 1); t++) {
                maxArea[j][t] = 0;
                for (int q = i + t - 1; q <= j - 1; q++)
                    if (maxArea[q][t - 1] != -1)
                        maxArea[j][t] = max(maxArea[q][t - 1] + area(ch[i], ch[j], ch[q]), maxArea[j][t]);
                if (maxArea[j][t] > maxResult) maxResult = maxArea[j][t];
            }
        }
    }
    return maxResult;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        convexHull();
        printf("%.2lf\n", dynamic());
    }
    return 0;
}                                 
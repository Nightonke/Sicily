// Problem#: 1092
// Submission#: 3416882
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <math.h>
#include <list>
using namespace std;

int N, W, H;
const int MAXN = 20010;

struct point {
    long long x, y, s;
    point() {}
    point(long long a, long long b, long long c) {
        x = a, y = b, s = c;
    }
};

point p[MAXN];
long long Y[MAXN], sum[MAXN << 2], Max[MAXN << 2];

bool cmp(const point & p1, const point & p2) {
    if (p1.x == p2.x) return p1.s < p2.s;
    return p1.x < p2.x;
}

int Find(int l, int r, long long target) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (Y[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}

void up(int idx) {
    int ls = idx << 1, rs = idx << 1 | 1;
    sum[idx] = sum[ls] + sum[rs];
    Max[idx] = Max[ls];
    if (Max[idx] < sum[ls] + Max[rs]) Max[idx] = sum[ls] + Max[rs];
}

void update(int l, int r, int idx, int pos, long long val) {
    if (l == r) {
        sum[idx] += val;
        Max[idx] += val;
        return;
    }
    int mid = (l + r) >> 1;
    int ls = idx << 1, rs = idx << 1 | 1;
    if (pos <= mid) update(l, mid, ls, pos, val);
    else update(mid + 1, r, rs, pos, val);
    up(idx);
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> N >> W >> H;
        if (cin.eof()) break;
        long long x, y, v;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> v;
            p[i << 1] = point(x, y, v);
            p[i << 1 | 1] = point(x + W, y, -v);
            Y[i << 1] = y;
            Y[i << 1 | 1] = y + H;
        }
        int m = N << 1;
        sort(Y, Y + m);
        sort(p, p + m, cmp);
        int n = 1;
        for (int i = 1; i < m; i++) {
            if (Y[i] != Y[i - 1]) Y[n++] = Y[i];
        }
        n--;
        memset(sum, 0, sizeof(sum));
        memset(Max, 0, sizeof(Max));
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            int s = Find(0, n, p[i].y);
            int e = Find(0, n, p[i].y + H);
            if (ans < Max[1]) ans = Max[1];
            update(0, MAXN, 1, s, p[i].s);
            update(0, MAXN, 1, e, -p[i].s);
        }
        cout << ans << endl;
    }

    return 0;
}                                 
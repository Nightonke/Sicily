// Problem#: 1912
// Submission#: 3591077
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 50005;
const int INF = 0x7fffffff;
const double EPS = 1e-9;

int n, k;
int x[MAXN], y[MAXN], r[MAXN], v[MAXN];
int fa[MAXN];
int cur[MAXN];
int Prev[MAXN];

inline long long sqr(long long x) {return x * x;}

struct Event {
    int id, type;
    Event(int id = 0, int type = 0) {
        this->id = id;
        this->type = type;
    }
    long long x_pos() const {
        return x[id] + r[id] * type;
    }
    bool operator < (const Event & t) const {
        long long dt = (long long)x_pos() - t.x_pos();
        if (dt != 0) return dt < 0;
        return id < t.id;
    }
}e[MAXN * 2];

int x_cut;

struct Intersection {
    int id, type;
    Intersection(int id = 0, int type = 0) {
        this->id = id;
        this->type = type;
    }
    double y_pos() const {
        long long s = sqr(r[id]) - sqr(x_cut - x[id]);
        if (s < 0) s = 0;
        return y[id] + sqrt((double)s) * type;
    }
    bool operator < (const Intersection & t) const {
        double dt = y_pos() - t.y_pos();
        if (fabs(dt) > EPS) return dt < 0;
        if (id != t.id) return id < t.id;
        return type < t.type;
    }
};

set<Intersection> bst;

void build() {
    for (int i = 0; i < n; i++) {
        e[i] = Event(i, - 1);
        e[i + n] = Event(i, 1);
    }
    sort(e, e + n * 2);
    bst.clear();
    for (int i = 0; i < n * 2; i++) {
        x_cut = e[i].x_pos();
        int cur = e[i].id;
        if (e[i].type < 0) {
            bst.insert(Intersection(cur, 1));
            set<Intersection>::iterator it;
            it = bst.insert(Intersection(cur, -1)).first;
            if (it == bst.begin()) {
                fa[cur] = n;
            } else {
                it--;
                if (it->type == -1) {
                    fa[cur] = it->id;
                } else {
                    fa[cur] = fa[it->id];
                }
            }
        } else {
            bst.erase(Intersection(cur, 1));
            bst.erase(Intersection(cur, -1));
        }
    }
}

int main() {
    int cs;
    scanf("%d", &cs);
    for (int cid = 1; cid <= cs; cid++) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d%d%d%d", x + i, y + i, r + i, v + i);
        build();
        v[n] = INF;
        memcpy(cur, v, sizeof(int) * (n + 1));
        for (int i = 1; i <= k; i++) {
            memcpy(Prev, cur, sizeof(int) * (n + 1));
            for (int a = 0; a < n; a++) {
                int b = fa[a];
                cur[a] = min(cur[a], Prev[b]);
                cur[b] = min(cur[b], Prev[a]);
            }
        }
        int ret = 0;
        for (int a = 0; a < n; a++) ret = max(ret, v[a] - cur[a]);
        printf("Case %d: %d\n", cid, ret);
    }
    return 0;
}                                 
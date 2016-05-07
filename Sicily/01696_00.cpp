// Problem#: 1696
// Submission#: 3588488
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

const int MAXN = 100;
const int MAXM = 100;
const long long INF = ((long long)1 << 60);

long n, m;
long long h[MAXN][MAXM], v[MAXN][MAXM];
long tot;
long heap[MAXN * MAXM], pos[MAXN * MAXM];
long long cost[MAXN * MAXM];

void input() {
    long i, j;
    scanf("%ld%ld", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m - 1; j++) scanf("%lld", &h[i][j]);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < m; j++) scanf("%lld", &v[i][j]);
}

void heap_up(int index) {
    long t1, temp;
    while (index) {
        t1 = (index - 1) / 2;
        if (cost[heap[t1]] > cost[heap[index]]) {
            pos[heap[index]] = t1;
            pos[heap[t1]] = index;
            temp = heap[index];
            heap[index] = heap[t1];
            heap[t1] = temp;
            index = t1;
        } else return;
    }
}

void heap_down(int index) {
    long t1, t2, temp;
    while (1) {
        t1 = index * 2 + 1;
        t2 = index * 2 + 2;
        if (t1 >= tot) return;
        if (t2 < tot && cost[heap[t2]] < cost[heap[t1]]) t1 = t2;
        if (cost[heap[t1]] < cost[heap[index]]) {
            pos[heap[index]] = t1;
            pos[heap[t1]] = index;
            temp = heap[index];
            heap[index] = heap[t1];
            heap[t1] = temp;
            index = t1;
        } else return;
    }
}

void heap_insert(int value) {
    heap[tot] = value;
    pos[value] = tot;
    heap_up(tot);
    tot++;
}

void heap_update(int index) {heap_up(index);}

long heap_pop() {
    long ret = heap[0];
    heap[0] = heap[tot - 1];
    pos[heap[0]] = 0;
    tot--;
    heap_down(0);
    return ret;
}

long long solve() {
    long i, j, t, tt;
    long long tv;
    tot = 0;
    for (i = 0; i < n * m; i++) cost[i] = INF, pos[i] = -1;
    for (j = 0; j < m - 2; j++) {
        t = j;
        cost[t] = h[0][t];
        heap_insert(t);
    }
    cost[m - 2] = h[0][m - 2] < v[0][m - 1] ? h[0][m - 2] : v[0][m - 1];
    heap_insert(m - 2);
    for (i = 1; i < n - 1; i++) {
        t = i * (m - 1) + m - 2;
        cost[t] = v[i][m - 1];
        heap_insert(t);
    }
    while (tot) {
        t = heap_pop();
        i = t / (m - 1);
        j = t % (m - 1);
        if (i > 0) {
            tt = (i - 1) * (m - 1) + j;
            tv = cost[t] + h[i][j];
            if (tv < cost[tt]) {
                cost[tt] = tv;
                if (pos[tt] == -1) heap_insert(tt);
                else heap_update(pos[tt]);
            }
        }
        if (i < n - 2) {
            tt = (i + 1) * (m - 1) + j;
            tv = cost[t] + h[i + 1][j];
            if (tv < cost[tt]) {
                cost[tt] = tv;
                if (pos[tt] == -1) heap_insert(tt);
                else heap_update(pos[tt]);
            }
        }
        if (j > 0) {
            tt = i * (m - 1) + j - 1;
            tv = cost[t] + v[i][j];
            if (tv < cost[tt]) {
                cost[tt] = tv;
                if (pos[tt] == -1) heap_insert(tt);
                else heap_update(pos[tt]);
            }
        }
        if (j < m - 2) {
            tt = i * (m - 1) + j + 1;
            tv = cost[t] + v[i][j + 1];
            if (tv < cost[tt]) {
                cost[tt] = tv;
                if (pos[tt] == -1) heap_insert(tt);
                else heap_update(pos[tt]);
            }
        }
    }
    long long ret = INF;
    for (i = 0; i < n - 1; i++) {
        tv = cost[i * (m - 1)] + v[i][0];
        if (tv < ret) ret = tv;
    }
    for (j = 0; j < m - 1; j++) {
        tv = cost[(n - 2) * (m - 1) + j] + h[n - 1][j];
        if (tv < ret) ret = tv;
    }
    return ret;
}

int main() {
    long T;
    scanf("%ld", &T);
    while (T--) {
        input();
        printf("%lld\n", solve());
    }
    return 0;
}                                 
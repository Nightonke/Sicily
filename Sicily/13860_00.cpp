// Problem#: 13860
// Submission#: 3650433
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

struct cow {
    int x, h;
}c[50005];

bool isLeftCrowded[50005];

bool cmp(const cow & c1, const cow & c2) {
    return c1.x < c2.x;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> c[i].x >> c[i].h;
    sort(c, c + n, cmp);
    int q[50005];
    int head, tail, ans = 0;
    head = tail = 0;
    q[0] = 0;
    for (int i = 1; i < n; i++) {
        int nearestPos = c[i].x - d;
        while (head <= tail && c[q[head]].x < nearestPos) head++;
        while (head <= tail && c[q[tail]].h <= c[i].h) tail--;
        if (head > tail) q[head] = i;
        if (c[q[head]].h >= c[i].h << 1) isLeftCrowded[i] = true;
        q[++tail] = i;
    }
    head = tail = 0;
    q[0] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        int nearestPos = c[i].x + d;
        while (head <= tail && c[q[head]].x > nearestPos) head++;
        while (head <= tail && c[q[tail]].h <= c[i].h) tail--;
        if (head > tail) q[head] = i;
        if (c[q[head]].h >= c[i].h << 1 && isLeftCrowded[i]) ans++;
        q[++tail] = i;
    }
    cout << ans << endl;
    return 0;
}                                 
// Problem#: 1907
// Submission#: 3590845
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Pt {
    int x, y, z;
};

bool operator < (Pt a, Pt b) {
    return a.x + a.y + a.z < b.x + b.y + b.z;
}

long long delta(int lower, int upper, int p) {
    if (p < lower) return lower - p;
    if (p > upper) return p - upper;
    return 0;
}

int main() {
    int cs;
    scanf("%d", &cs);
    while (cs--) {
        int xb, yb, zb, r;
        Pt v[8];
        for (int i = 0; i < 8; i++) scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].z);
        scanf("%lld%lld%lld%lld", &xb, &yb, &zb, &r);
        sort(v, v + 8);
        long long dx = delta(v[0].x, v[7].x, xb);
        long long dy = delta(v[0].y, v[7].y, yb);
        long long dz = delta(v[0].z, v[7].z, zb);
        if (dx * dx + dy * dy + dz * dz <= (long long)r * r) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}                                 
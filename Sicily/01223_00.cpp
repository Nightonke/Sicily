// Problem#: 1223
// Submission#: 3587773
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const long maxn = 100005;

long region(long x, long y) {
    if (y >= 0) if (x >= 0) return 1; else return 2;
    if (x < 0) return 3;
    return 4;
}

struct point {
    long x, y;
    bool operator < (const point & that) const {
        long r1 = region(x, y);
        long r2 = region(that.x, that.y);
        if (r1 != r2) return r1 < r2;
        return x * that.y - y * that.x > 0;
    }
};

long n;
point p[maxn];
point o;

long process() {
    long ans = n;
    long i, j, k;
    if (n <= 2) return 0;
    j = 1;
    for (i = 0; i < n; i++) {
        while (j != i && !(p[i].x * p[j].y - p[i].y * p[j].x < 0)) j = (j + 1) % n;
        if (j == i) return 0;
        k = n - ((j - i + n) % n);
        if (k < ans) ans = k;
    }
    return ans;
}

int main() {
    long i, j;
    scanf("%ld", &n);
    for (i = 0; i < n; i++) scanf("%ld%ld", &p[i].x, &p[i].y);
    scanf("%ld%ld", &o.x, &o.y);
    for (i = 0; i < n; i++) {
        p[i].x -= o.x;
        p[i].y -= o.y;
    }
    j = 0;
    for (i = 0; i < n; i++)
        if (!(p[i].x == 0 && p[i].y == 0)) {
            p[j] = p[i];
            j++;
        }
    n = j;
    sort(p, p + n);
    printf("%ld\n", process());
    return 0;
}                                 
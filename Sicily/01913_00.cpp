// Problem#: 1913
// Submission#: 3591128
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 100;

int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];

void insert_min(int a[2], int x) {
    if (x < a[0]) swap(x, a[0]);
    if (x < a[1]) swap(x, a[1]);
}

void insert_max(int a[2], int x) {
    if (x > a[0]) swap(x, a[0]);
    if (x > a[1]) swap(x, a[1]);
}

int exclude(int a[2], int x) {
    if (a[0] != x) return a[0];
    return a[1];
}

int main() {
    int cs;
    scanf("%d", &cs);
    while (cs--) {
        int left[2] = {-INF, -INF};
        int right[2] = {INF, INF};
        int bottom[2] = {-INF, -INF};
        int top[2] = {INF, INF};
        int n; 
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
            insert_max(left, x1[i]);
            insert_min(right, x2[i]);
            insert_max(bottom, y1[i]);
            insert_min(top, y2[i]);
        }
        if (n == 1) {
            printf("0\n");
        } else {
            int ret = 0;
            for (int i = 0; i < n; i++) {
                int dx = exclude(right, x2[i]) - exclude(left, x1[i]);
                if (dx < 0) dx = 0;
                int dy = exclude(top, y2[i]) - exclude(bottom, y1[i]);
                if (dy < 0) dy = 0;
                ret = max(ret, dx * dy);
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}                                 
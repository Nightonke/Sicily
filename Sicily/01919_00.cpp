// Problem#: 1919
// Submission#: 3591565
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int MAXH = 101;
const int MAXR = 102;

int N, H;

struct Disk {
    int r, h;
    bool operator < (Disk x) const {
        return r < x.r;
    }
}disk[MAXN];

double a[MAXR][MAXH], b[MAXR][MAXH];

int input() {
    if (scanf("%d%d", &N, &H) != 2) return 0;
    for (int i = 0; i < N; i++) scanf("%d%d", &disk[i].r, &disk[i].h);
    return 1;
}

int main() {
    while (1) {
        if (!input()) break;
        sort(disk, disk + N);
        double sa, sb;
        for (int h = H; h >= 0; h--) {
            sa = sb = 0.0;
            for (int r = 1, c = 0; r <= disk[N - 1].r + 1; r++) {
                for (; c < N && disk[c].r < r; c++) {
                    int rt = disk[c].r;
                    int ht = disk[c].h + h;
                    if (ht > H) continue;
                    sa += a[rt][ht];
                    sb += b[rt][ht];
                }
                a[r][h] = 1 / (c + 1 - sa);
                b[r][h] = (c + 1 + sb) / (c + 1 - sa);
            }
        }
        double ans = b[disk[N - 1].r + 1][0];
        printf(ans > 18000.0 ? "INF\n" : "%.3lf\n", ans);
    }
    return 0;
}                                 
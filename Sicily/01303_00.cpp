// Problem#: 1303
// Submission#: 3462789
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
#include <set>
using namespace std;

const int MAXN = 105;

int v[MAXN][MAXN];
bool g[MAXN][MAXN];
int mx[MAXN], my[MAXN];
int lx[MAXN], ly[MAXN];
int sx[MAXN], sy[MAXN];
int fx[MAXN], fy[MAXN];
int n;

int GetMaxMatch() {
    int i, j, p;
    i = 1;
    while (i <= n && mx[i] > 0) i++;
    while (i <= n) {
        memset(fx, 0, sizeof(fx));
        memset(fy, 0, sizeof(fy));
        sx[0] = 1;
        sx[1] = i;
        fx[i] = 1;
        sy[0] = 0;
        p = 1;
        for (j = 1; j <= n; j++) {
            if (g[i][j]) {
                fy[j] = i;
                sy[++sy[0]] = j;
            }
        }
        while (p <= sy[0]) {
            if (my[sy[p]] == 0) {
                i = sy[p];
                j = fy[i];
                while (mx[j] > 0) {
                    my[i] = j;
                    j = mx[j];
                    mx[my[j]] = i;
                    i = j;
                    j = fy[i];
                }
                mx[j] = i;
                my[i] = j;
                sx[0] = 0;
                break;
            }
            i = my[sy[p]];
            fx[i] = 1;
            sx[++sx[0]] = i;
            for (j = 1; j <= n; j++) {
                if (g[i][j] && fy[j] == 0) {
                    fy[j] = i;
                    sy[++sy[0]] = j;
                }
            }
            p++;
        }
        if (sx[0] == 0) {
            i = 1;
            while (i <= n && mx[i] > 0) i++;
        } else i = n + 1;
    }
    j = 0;
    for (i = 1; i <= n; i++) if (mx[i] > 0) j++;
    return j;
}

int GetPerfectMatch() {
    int i, j, min;
    for (i = 1; i <= n; i++) {
        lx[i] = 0;
        ly[i] = 0;
        for (j = 1; j <= n; j++) if (v[i][j] > lx[i]) lx[i] = v[i][j];
    }
    for (i = 1;i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (v[i][j] == lx[i]) g[i][j] = true;
            else g[i][j] = false;
        }
    }
    memset(mx, 0, sizeof(mx));
    memset(my, 0, sizeof(my));
    while (GetMaxMatch() < n) {
        j = sx[0];
        for (i = 1; i <= n; i++) if (fx[i] == 0) sx[++j] = i;
        j = sy[0];
        for (i = 1; i <= n; i++) if (fy[i] == 0) sy[++j] = i;
        min = 99999999;
        for (i = 1; i <= sx[0]; i++) {
            for (j = sy[0] + 1; j <= n; j++) {
                if (lx[sx[i]] + ly[sy[j]] - v[sx[i]][sy[j]] < min) {
                    min = lx[sx[i]] + ly[sy[j]] - v[sx[i]][sy[j]];
                }
            }
        }
        for (i = 1; i <= sx[0]; i++) lx[sx[i]] -= min;
        for (i = 1; i <= sy[0]; i++) ly[sy[i]] += min;
        for (i = 1; i <= sx[0]; i++) {
            for (j = sy[0] + 1; j <= n; j++) {
                if (lx[sx[i]] + ly[sy[j]] == v[sx[i]][sy[j]]) g[sx[i]][sy[j]] = true;
                else g[sx[i]][sy[j]] = false;
            }
        }
        for (i = sx[0] + 1; i <= n; i++) {
            for (j = 1; j <= sy[0]; j++) {
                if (lx[sx[i]] + ly[sy[j]] == v[sx[i]][sy[j]]) g[sx[i]][sy[j]] = true;
                else g[sx[i]][sy[j]] = false;
            }
        }
    }
    j = 0;
    for (i = 1; i <= n; i++) j += v[i][mx[i]];
    return j;
}
int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> n;
        if (!n) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> v[i][j];
            }
        }
        cout << GetPerfectMatch() << endl;
    }

    return 0;
}                                 
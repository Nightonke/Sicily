// Problem#: 1013
// Submission#: 3160682
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

#define MAX_POINT 101
#define INF 0xffffff


int w[MAX_POINT][MAX_POINT];  // 边权值
int lx[MAX_POINT], ly[MAX_POINT];  // 顶标
int linky[MAX_POINT];  // 存储求解过程
bool visx[MAX_POINT], visy[MAX_POINT];  // 记录两个集合中的点的访问情况
int slack[MAX_POINT];  // 松弛量
int fx, fy;  // 两个集合中点的数量

struct node {
    int pi, pj;
    node() {}
    node(int i, int j) {pi = i, pj = j;}
};

node H[MAX_POINT], M[MAX_POINT];

bool Find(int x) {
    visx[x] = true;
    for (int y = 0; y < fy; y++) {
        if (visy[y]) continue;
        int t = lx[x] + ly[y] - w[x][y];
        if (t == 0) {
            visy[y] = true;
            if (linky[y] == -1 || Find(linky[y])) {
                linky[y] = x;
                return true;
            }
        } else if (slack[y] > t) {
            slack[y] = t;
        }
    }
    return false;
}

int KM() {
    for (int i = 0; i < MAX_POINT; linky[i++] = -1);
    memset(ly, 0, sizeof(ly));
    for (int i = 0; i < fx; i++) {
        lx[i] = -INF;
        for (int j = 0; j < fy; j++) {
            if (w[i][j] > lx[i]) {
                lx[i] = w[i][j];
            }
        }
    }
    for (int x = 0; x < fx; x++) {
        for (int i = 0; i < fy; i++) slack[i] = INF;
        while (1) {
            memset(visx, false, sizeof(visx));
            memset(visy, false, sizeof(visy));
            if (Find(x)) break;
            int d = INF;
            for (int i = 0; i < fy; i++) {
                if (!visy[i] && d > slack[i]) d = slack[i];
            }
            for (int i = 0; i < fx; i++) {
                if (visx[i]) lx[i] -= d;
            }
            for (int i = 0; i < fy; i++) {
                if (visy[i]) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < fy; i++) {
        if (linky[i] > -1) ans += w[linky[i]][i];
    }
    return ans;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        
        int h, wid;
        char G[MAX_POINT][MAX_POINT];
        cin >> h >> wid;
        if (h == 0 && wid == 0) break;
        for (int i = 0; i < h; i++) cin >> G[i];
        
        fx = fy = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < wid; j++) {
                if (G[i][j] == 'm') {
                    M[fx++] = node(i, j);
                } else if (G[i][j] == 'H') {
                    H[fy++] = node(i, j);
                }
            }
        }
        for (int i = 0; i < fx; i++) {
            for (int j = 0; j < fy; j++) {
                w[i][j] = -(abs(M[i].pi - H[j].pi) + abs(M[i].pj - H[j].pj));
            }
        }
        cout << -KM() << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
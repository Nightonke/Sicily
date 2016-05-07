// Problem#: 1889
// Submission#: 2787817
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 505
#define INF 0x7f7f7f

char map[MAX][MAX];
int si, sj, ei, ej, h, w;

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool vis[MAX * MAX];

bool is_valid(int ii, int jj) {
    if (ii < 0 || ii >= h || jj < 0 || jj >= w || vis[ii * w + jj])
        return false;
    return true;
}

struct step {
    int to;
    int cost;
};

step p[MAX * MAX][4];

void make_map() {
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int temp = i * w + j;
            int oo = 0;
            for (int k = 0; k < 4; k++) {
                if (is_valid(i + dir[k][0], j + dir[k][1])) {
                    int c = (map[i][j] == map[i + dir[k][0]][j + dir[k][1]]) ? 0 : 1;
                    p[temp][oo].to = (i + dir[k][0]) * w + j + dir[k][1];
                    p[temp][oo++].cost = c;
                    //p[temp].push_back(step((i + dir[k][0]) * w + j + dir[k][1], c));
                    //printf("%d\n", p[temp][0].to);
                }
            }
            p[temp][oo].to = -1;
        }
    }
}

typedef pair <int, int> pr;

int Dijkstra() {
    
    int d[MAX * MAX];
    memset(d, INF, sizeof(d));
    d[si * w + sj] = 0;
    priority_queue<pr, vector<pr>, greater<pr> > q;
    q.push(pr(0, si * w + sj));
    pr top;
    
    while (!q.empty()) {
        top = q.top();
        q.pop();
        
        if (top.second == ei * w + ej)
            return d[top.second];
        
        if (vis[top.second] || d[top.second] < top.first)
            continue;
        
        vis[top.second] = true;
        
        for (int i = 0; i < 4 && p[top.second][i].to != -1; i++) {
            if (d[p[top.second][i].to] > d[top.second] + p[top.second][i].cost) {
                d[p[top.second][i].to] = d[top.second] + p[top.second][i].cost;
                q.push(pr(d[p[top.second][i].to], p[top.second][i].to));
            }
        }
    }
}
    
int main() {
    while (~scanf("%d %d\n", &h, &w)) {
        for (int i = 0; i < h; i++) {
            gets(map[i]);
        }
        make_map();
        scanf("%d %d %d %d", &si, &sj, &ei, &ej);
        printf("%d\n", Dijkstra());
    }
    return 0;
}                                 
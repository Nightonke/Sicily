// Problem#: 1889
// Submission#: 2788718
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 500
#define INF 0x7f7f7f

char map[MAX][MAX];
int si, sj, ei, ej, h, w;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool vis[MAX][MAX];

typedef pair <int, int> pr;

int Dijkstra() {
    
    int sp = si * w + sj, ep = ei * w + ej;
    int new_ii, new_jj;
    int d[MAX * MAX];
    memset(d, INF, sizeof(d));
    memset(vis, false, sizeof(vis));
    d[sp] = 0;
    priority_queue<pr, vector<pr>, greater<pr> > q;
    q.push(pr(0, sp));
    pr top;
    int cost, temp, ii, jj, i;
    
    while (!q.empty()) {
        top = q.top();
        q.pop();
        
        ii = top.second / w;
        jj = top.second % w;
        
        if (vis[ii][jj] || d[top.second] < top.first)
            continue;
        
        if (top.second == ep)
            return d[top.second];
        
        vis[ii][jj] = true;
        
        for (i = 0; i < 4; i++) {
            new_ii = ii + dir[i][0];
            new_jj = jj + dir[i][1];
            if (new_ii < 0 || new_ii >= h || new_jj < 0 || new_jj >= w || vis[new_ii][new_jj])
                continue;
            else {
                cost = map[ii][jj] ^ map[new_ii][new_jj] ? 1 : 0;
                temp = (new_ii) * w + new_jj;
                if (d[temp] > d[top.second] + cost) {
                    d[temp] = d[top.second] + cost;
                    q.push(pr(d[temp], temp));
                }
            }
        }
    }
}
    
int main() {
    while (~scanf("%d %d\n", &h, &w)) {
        for (int i = 0; i < h; i++) {
            gets(map[i]);
        }
        scanf("%d %d %d %d", &si, &sj, &ei, &ej);
        printf("%d\n", Dijkstra());
    }
    return 0;
}                                 
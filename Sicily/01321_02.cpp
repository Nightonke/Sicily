// Problem#: 1321
// Submission#: 2776591
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 105
#define INF 99999999

int h, w, mapp[MAX][MAX], si, sj, ei, ej;

struct edge {
    int to;
    int dis;
    edge(int new_to, int new_dis): to(new_to), dis(new_dis){}
};

vector<edge> e[MAX * MAX];

void make_roads() {
    
    int pos_i;
    
    for (int i = 0; i < MAX * MAX; i++) {
        e[i].clear();
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            
            pos_i = i * 100 + j;
            
            if (i > 0) {
                e[pos_i].push_back(edge(pos_i - 100, mapp[i - 1][j]));
            }
            
            if (j > 0) {
                e[pos_i].push_back(edge(pos_i - 1, mapp[i][j - 1]));
            }
            
            if (i < h - 1) {
                e[pos_i].push_back(edge(pos_i + 100, mapp[i + 1][j]));
            }
            
            if (j < w - 1) {
                e[pos_i].push_back(edge(pos_i + 1, mapp[i][j + 1]));
            }
        }
    }
    
    si--;
    sj--;
    ei--;
    ej--;
}

typedef pair<int, int> p;

int Dijkstra() {
    
    int sp = si * 100 + sj;
    int ep = ei * 100 + ej;
    
    int d[MAX * MAX];
    fill(d, d + MAX * MAX, INF);
    d[sp] = 0;
    
    priority_queue<p, vector<p>, greater<p> > q;
    q.push(p(0, sp));
    p top;
    
    while (!q.empty()) {
        
        top = q.top();
        q.pop();
        
        if (d[top.second] < top.first)
            continue;
        
        if (top.second == ep)
            return d[ep];
        
        for (int i = 0; i < (int)e[top.second].size(); i++) {
            if (d[e[top.second][i].to] > d[top.second] + e[top.second][i].dis) {
                d[e[top.second][i].to] = d[top.second] + e[top.second][i].dis;
                q.push(p(d[e[top.second][i].to], e[top.second][i].to));
            }
        }
    }
    
    return d[ep];
}

int main() {
    
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d%d", &h, &w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &mapp[i][j]);
            }
        }
        scanf("%d%d%d%d", &si, &sj, &ei, &ej);
        
        make_roads();
        printf("%d\n", Dijkstra() + mapp[si][sj]);
    }
    return 0;
}                                 
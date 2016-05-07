// Problem#: 1321
// Submission#: 2776502
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 105
#define INF 99999999

int h, w, mapp[MAX][MAX], si, sj, ei, ej;
bool vis[MAX][MAX];

struct edge {
    int to;
    int dis;
    edge(int new_to, int new_dis): to(new_to), dis(new_dis){}
};

vector<edge> e[MAX * MAX];

void make_roads() {
    
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < MAX * MAX; i++) {
        e[i].clear();
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            
            if (vis[i][j])
                continue;
            
            vis[i][j] = true;
            
            if (i > 0) {
                e[i * 100 + j].push_back(edge((i - 1) * 100 + j, mapp[i - 1][j]));
            }
            
            if (j > 0) {
                e[i * 100 + j].push_back(edge(i * 100 + j - 1, mapp[i][j - 1]));
            }
            
            if (i < h - 1) {
                e[i * 100 + j].push_back(edge((i + 1) * 100 + j, mapp[i + 1][j]));
            }
            
            if (j < w - 1) {
                e[i * 100 + j].push_back(edge(i * 100 + j + 1, mapp[i][j + 1]));
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
    
    std::ios::sync_with_stdio(false);
    
    int case_num;
    cin >> case_num;
    while (case_num--) {
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> mapp[i][j];
            }
        }
        cin >> si >> sj >> ei >> ej;
        
        make_roads();
        cout << Dijkstra() + mapp[si][sj] << endl;
    }
    return 0;
}                                 
// Problem#: 1321
// Submission#: 2776529
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
int e_to[MAX * MAX][5], e_dis[MAX * MAX][5];

void make_roads() {
    
    int k, pos_f;
    memset(e_dis, -1, sizeof(e_dis));
    memset(vis, false, sizeof(vis));
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            
            if (vis[i][j])
                continue;
            
            vis[i][j] = true;
            k = 0;
            pos_f = i * 100 + j;
            
            if (i > 0) {
                e_to[pos_f][k] = pos_f - 100;                
                e_dis[pos_f][k++] = mapp[i - 1][j];
            }
            
            if (j > 0) {
                e_to[pos_f][k] = pos_f - 1;                
                e_dis[pos_f][k++] = mapp[i][j - 1];
            }
            
            if (i < h - 1) {
                e_to[pos_f][k] = pos_f + 100;                
                e_dis[pos_f][k++] = mapp[i + 1][j];
            }
            
            if (j < w - 1) {
                e_to[pos_f][k] = pos_f + 1;                
                e_dis[pos_f][k++] = mapp[i][j + 1];
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
        
        for (int i = 0; e_dis[top.second][i] != -1; i++) {
            if (d[e_to[top.second][i]] > d[top.second] + e_dis[top.second][i]) {
                d[e_to[top.second][i]] = d[top.second] + e_dis[top.second][i];
                q.push(p(d[e_to[top.second][i]], e_to[top.second][i]));
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
// Problem#: 1823
// Submission#: 3161692
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
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

#define MAX_POINT 205
#define INF 99999999

struct edge {
    int to, cost;
    edge(int t, int c) {
        to = t;
        cost = c;
    }
};

int n;
vector<edge> E[MAX_POINT];
int d[MAX_POINT];

void DIJKSTRA(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    for (int i = 1; i <= n; d[i++] = INF);
    d[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        if (d[now.second] < now.first) continue;
        for (int i = 0; i < E[now.second].size(); i++) {
            edge e = E[now.second][i];
            if (d[e.to] > d[now.second] + e.cost) {
                d[e.to] = d[now.second] + e.cost;
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            E[from].push_back(edge(to, cost));
            E[to].push_back(edge(from, cost));
        }
        DIJKSTRA(1);
        if (d[n] == INF) cout << -1 << endl;
        else cout << d[n] << endl;
        for (int i = 0; i < n; i++) E[i].clear();
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
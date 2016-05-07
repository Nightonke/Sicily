// Problem#: 1120
// Submission#: 3417906
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
using namespace std;

const int MAX_N = 1005;
const int INF = 200000000;

struct edge {
    int to, cost;
    edge(int t = 0, int c = 0) {
        to = t;
        cost = c;
    }
};

int N, M;
int d[MAX_N];
vector<edge> G[MAX_N];
vector<int> SG[MAX_N];
int known[MAX_N];

void DIJKSTRA(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    for (int i = 1; i <= N; d[i++] = INF);
    d[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        if (d[now.second] < now.first) continue;
        for (int i = 0; i < G[now.second].size(); i++) {
            edge e = G[now.second][i];
            if (d[e.to] > d[now.second] + e.cost) {
                d[e.to] = d[now.second] + e.cost;
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}

void makeRightRoad() {
    for (int i = 1; i <= N; i++) {
        int s = G[i].size();
        for (int j = 0; j < s; j++) {
            int from = i, to = G[i][j].to;
            if (d[from] > d[to]) SG[from].push_back(to);
        }
    }
}

int getAns(int now) {
    if (known[now] != -1) return known[now];
    int s = SG[now].size();
    int sum = 0;
    for (int i = 0; i < s; i++) {
        sum += getAns(SG[now][i]);
    }
    return known[now] = sum;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> N;
        if (!N) break;
        cin >> M;
        for (int i = 1; i <= N; i++) {
            G[i].clear();
            SG[i].clear();
        }
        for (int i = 0; i < M; i++) {
            int v1, v2, d;
            cin >> v1 >> v2 >> d;
            G[v1].push_back(edge(v2, d));
            G[v2].push_back(edge(v1, d));
        }
        DIJKSTRA(2);
        makeRightRoad();
        for (int i = 1; i <= N; i++) known[i] = -1;
        known[2] = 1;
        cout << getAns(1) << endl;
    }

    return 0;
}                                 
// Problem#: 1402
// Submission#: 2991966
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
using namespace std;

#define MAX_POINT 30
#define INF 99999999

struct edge {
    int to;
    int cap;
    int rev;
    edge() {}
    edge(int tto, int ccap, int rrev) {

        to = tto;
        cap = ccap;
        rev = rrev;

    }
};

bool vis[MAX_POINT];
int points;
vector<edge> G[MAX_POINT];

void addEdge(int from, int to, int cap) {

    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));

}

int makeSuperStart(vector<int> start) {

    if (start.size() == 1) return start[0];

    int s = points;
    points++;

    for (int i = 0; i < start.size(); i++) {

        addEdge(s, start[i], INF);
        addEdge(start[i], s, INF);

    }

    return s;

}

int makeSuperEnd(vector<int> end) {

    if (end.size() == 1) return end[0];

    int e = points;
    points++;

    for (int i = 0; i < end.size(); i++) {

        addEdge(end[i], e, INF);
        addEdge(e, end[i], INF);

    }

    return e;

}

int dfs(int from, int to, int lastCap) {

    if (from == to) return lastCap;

    vis[from] = true;

    for (int i = 0; i < G[from].size(); i++) {

        edge & e = G[from][i];

        if (!vis[e.to] && e.cap > 0) {

            int nextFlow = dfs(e.to, to, min(lastCap, e.cap));

            if (nextFlow > 0) {
            
                e.cap -= nextFlow;
                G[e.to][e.rev].cap += nextFlow;
                return nextFlow;

            }

        }

    }

    return 0;

}

int MaxFlow(vector<int> start, vector<int> end) {

    int maxFlow = 0;

    int s = makeSuperStart(start);
    int e = makeSuperEnd(end);

    while (1) {

        memset(vis, false, sizeof(vis));

        int f = dfs(s, e, INF);

        if (f == 0) return maxFlow;

        maxFlow += f;

    }

    return maxFlow;

}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;

    cin >> caseNum;

    while (caseNum--) {

        int n, p;
        vector<int> start, end;

        cin >> n >> p;

        end.push_back(p);

        //reset
        for (int i = 0; i < MAX_POINT; i++) G[i].clear();
        points = n;
        //reset

        for (int i = 0; i < n; i++) {

            string s;
            int m;

            cin >> s >> m;

            if (s == "I") {

                start.push_back(i);

            }

            for (int j = 0; j < m; j++) {

                int to;

                cin >> to;

                addEdge(i, to, INF);
                addEdge(to, i, 1);

            }

        }

        int ans = MaxFlow(start, end);

        if (ans >= INF) cout << "PANIC ROOM BREACH" << endl;
        else cout << ans << endl;

    }

    //getchar();
    //getchar();
    return 0;
}                                 
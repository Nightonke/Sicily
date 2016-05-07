// Problem#: 1703
// Submission#: 3322831
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

const int MAX_P = 16000;
const int INF = 99999999;

struct edge {
    int to, cost;
    edge(int t = 0, int c = 0) {
        to = t;
        cost = c;
    }
};

int d[MAX_P];
vector<edge> G[MAX_P];
int N;
int P;
int M[130][130];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

bool isValid(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

void makeG() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int from = i * N + j;
            for (int k = 0; k < 4; k++) {
                int toi = i + dir[k][0], toj = j + dir[k][1];
                if (isValid(toi, toj)) {
                    G[from].push_back(edge(toi * N + toj, M[toi][toj]));
                }
            }
        }
    }
    P = N * N;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    fill(d, d + P, INF);
    d[0] = 0;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        int s = G[v].size();
        for (int i = 0; i < s; i++) {
            if (d[G[v][i].to] > d[v] + G[v][i].cost) {
                d[G[v][i].to] = d[v] + G[v][i].cost;
                q.push(make_pair(d[G[v][i].to], G[v][i].to));
            }
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int counter = 1;

    while (1) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> M[i][j];
            }
        }
        makeG();
        dijkstra();
        cout << "Problem " << counter << ": " << M[0][0] + d[P - 1] << endl;
        for (int i = 0; i < P; i++) G[i].clear();
        counter++;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
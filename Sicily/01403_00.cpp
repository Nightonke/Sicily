// Problem#: 1403
// Submission#: 3241342
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
#include <set>
using namespace std;

const int MAX_N = 105;

int N, E;
bool G[MAX_N][MAX_N];
bool isCyclic;
bool isConnected;
int visit[MAX_N];
int father[MAX_N];

void dfsVisit(int node) {
    visit[node] = 1;
    for (int i = 1; i <= N; i++) {
        if (i != node && G[node][i]) {
            if (visit[i] == 1 && i != father[node]) {
                isCyclic = true;
                return;
            } else if (visit[i] == 0) {
                father[i] = node;
                dfsVisit(i);
            }
        }
    }
    visit[node] = 2;
}

void dfsJudgeIsCyclic() {
    for (int i = 1; i <= N; visit[i++] = 0);
    for (int i = 1; i <= N; father[i++] = -1);
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0) {
            dfsVisit(i);
        }
    }
}

void dfsJudgeIsConnected() {
    for (int i = 1; i <= N; visit[i++] = 0);
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    int counter = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        counter++;
        for (int i = 1; i <= N; i++) {
            if (G[node][i] && !visit[i]) {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
    if (counter == N) isConnected = true;
}

int main() {

    std::ios::sync_with_stdio(false);

    int counter = 0;

    while (1) {
        cin >> N;
        if (N == 0) break;
        counter++;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                G[i][j] = false;
            }
        }
        cin >> E;
        for (int i = 0; i < E; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            G[n1][n2] = G[n2][n1] = true;
        }
        isConnected = isCyclic = false;
        dfsJudgeIsCyclic();
        dfsJudgeIsConnected();
        if (!isConnected || isCyclic) {
            cout << "Graph " << counter << " is not a caterpillar." << endl;
            continue;
        }

        int aloneNode[MAX_N];
        for (int i = 1; i <= N; aloneNode[i++] = 0);
        for (int i = 1; i <= N; i++) {
            int c = 0;
            int cNode;
            for (int j = 1; j <= N; j++) {
                if (G[i][j]) {
                    c++;
                    cNode = j;
                }
            }
            if (c == 1) aloneNode[i] = cNode;
        }
        for (int i = 1; i <= N; i++) {
            if (aloneNode[i] != 0) {
                G[i][aloneNode[i]] = G[aloneNode[i]][i] = false;
            }
        }
        bool isCaterpillar = true;
        for (int i = 1; i <= N; i++) {
            if (aloneNode[i] == 0) {
                int c = 0;
                for (int j = 1; j <= N; j++) {
                    if (G[i][j]) c++;
                }
                if (c >= 3) {
                    isCaterpillar = false;
                    break;
                }
            }
        }
        if (isCaterpillar) cout << "Graph " << counter << " is a caterpillar." << endl;
        else cout << "Graph " << counter << " is not a caterpillar." << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
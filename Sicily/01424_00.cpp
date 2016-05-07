// Problem#: 1424
// Submission#: 3254632
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 10005;

int N, M;
vector<vector<int> > G;
int award[MAX_N];
int inDegree[MAX_N];

int main() {

    std::ios::sync_with_stdio(false);

    cin >> N >> M;
    G.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int bigger, smaller;
        cin >> bigger >> smaller;
        G[smaller].push_back(bigger);
        inDegree[bigger]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        award[i] = 100;
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int counter = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        counter++;
        int nowSize = G[now].size();
        for (int i = 0; i < nowSize; i++) {
            if (award[now] + 1 > award[G[now][i]]) award[G[now][i]] = award[now] + 1;
            inDegree[G[now][i]]--;
            if (inDegree[G[now][i]] == 0) q.push(G[now][i]);
        }
    }

    if (counter != N) {
        cout << "Poor Xed" << endl;
    } else {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += award[i];
        }
        cout << ans << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
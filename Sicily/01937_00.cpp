// Problem#: 1937
// Submission#: 3369378
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
using namespace std;

const int MAX_N = 105;
const int INF = -1;

int G[MAX_N][MAX_N];
int N, R, S, E, P;

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        cin >> N >> R;
        init();
        for (int i = 0; i < R; i++) {
            int v1, v2, dis;
            cin >> v1 >> v2 >> dis;
            G[v1][v2] = G[v2][v1] = dis;
        }
        cin >> S >> E >> P;
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    G[i][j] = max(G[i][j], min(G[i][k], G[k][j]));
                }
            }
        }
        cout << P / (G[S][E]- 1) + (P % G[S][E] ? 1 : 0) << endl;
    }

    //cin >> N;

    return 0;
}                                 
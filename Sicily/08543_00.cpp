// Problem#: 8543
// Submission#: 3379576
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
using namespace std;

const int MAX_N = 505;

int N, M;
bool vis[MAX_N];
vector<int> E[MAX_N];
vector<int> P;
int e, p;

void dfs(int now) {
    int s = E[now].size();
    P.push_back(now);
    for (int i = 0; i < s; i++) {
        if (!vis[E[now][i]]) {
            p++;
            vis[E[now][i]] = true;
            dfs(E[now][i]);
        }
    }
}

void calE() {
    bool visFrom[MAX_N];
    int s = P.size();
    for (int i = 0; i < s; i++) visFrom[P[i]] = false;
    for (int i = 0; i < s; i++) {
        visFrom[P[i]] = true;
        int ss = E[P[i]].size();
        for (int j = 0; j < ss; j++) {
            if (!visFrom[E[P[i]][j]]) e++;
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int counter = 1;

    while (1) {
        cin >> N >> M;

        if (!N && !M) break;

        for (int i = 1; i <= N; i++) {
            vis[i] = false;
            E[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int f, t;
            cin >> f >> t;
            E[f].push_back(t);
            E[t].push_back(f);
        }

        int ans = 0;

        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                P.clear();
                e = 0;
                p = 1;
                vis[i] = true;
                dfs(i);
                calE();
                if (p == e + 1) ans++;
            }
        }

        if (ans == 0) cout << "Case " << counter++ << ": No trees." << endl;
        if (ans == 1) cout << "Case " << counter++ << ": There is one tree." << endl;
        if (ans > 1) cout << "Case " << counter++ << ": A forest of " << ans << " trees." << endl;

    }

    return 0;
}                                 
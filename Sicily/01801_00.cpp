// Problem#: 1801
// Submission#: 3327739
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

const int MAX_N = 105;

int N, M;
int cost[MAX_N];
bool vis[MAX_N];
vector<int> similar[MAX_N];
vector<int> connect;
int ans;

void dfs(int now) {
    vis[now] = true;
    connect.push_back(now);
    int s = similar[now].size();
    for (int i = 0; i < s; i++) {
        if (!vis[similar[now][i]]) {
            dfs(similar[now][i]);
        }
    }
}

void cal() {
    int sum = 0, s = connect.size(), Min = 99999999, MinP = -1;
    for (int i = 0; i < s; i++) {
        if (Min > cost[connect[i]]) {
            Min = cost[connect[i]];
            MinP = i;
        }
    }
    for (int i = 0; i < s; i++) if (i != MinP) sum += cost[connect[i]] / 2;
    ans += Min + sum;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        ans = 0;
        for (int i = 0; i < N; i++) cin >> cost[i];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++) similar[i].clear();
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            similar[a].push_back(b);
            similar[b].push_back(a);
        }
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                connect.clear();
                dfs(i);
                cal();
            }
        }
        cout << ans << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
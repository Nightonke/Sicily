// Problem#: 1373
// Submission#: 3308476
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
using namespace std;

const int MAX_N = 11;

int vis[MAX_N], que[MAX_N], h[MAX_N];
int N, K, ans = 0;

void dfs(int now) {
    if (now == N) {
        ans++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (vis[i] != 1 && abs(que[now - 1] - h[i]) <= K) {
            if (now == N - 1 && abs(h[i] - que[0]) > K) continue;
            que[now] = h[i];
            vis[i] = 1;
            dfs(now + 1);
            vis[i] = 0;
        }
    }
}

int main() {

    std::cout.sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> h[i];
    que[0] = h[0];
    vis[0] = 1;
    dfs(1);
    cout << ans << endl;

    return 0;
}                                 
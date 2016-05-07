// Problem#: 1428
// Submission#: 3307404
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1428
// Submission#: 3307337
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

const int MAX_G = 55;

char G[MAX_G][MAX_G];
int firstLine;
int H, W;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
vector<pair<int, int> > same;
bool vis[MAX_G][MAX_G];

bool isValid(int ni, int nj, int pi, int pj) {
    return (0 <= ni && ni < H) && (0 <= nj && nj < W) && !vis[ni][nj] && (G[ni][nj] == G[pi][pj]);
}

void dfs(int pi, int pj) {
    for (int i = 0; i < 4; i++) {
        int ni = pi + dir[i][0];
        int nj = pj + dir[i][1];
        if (isValid(ni, nj, pi, pj)) {  // if they are same
            same.push_back(make_pair(ni, nj));
            vis[ni][nj] = true;
            dfs(ni, nj);
        }
    }
}

int check() {
    for (int i = 0; i < same.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if ((0 <= same[i].first + dir[j][0] && same[i].first + dir[j][0] < H && 0 <= same[i].second + dir[j][1] && same[i].second + dir[j][1] < W) && (G[same[i].first + dir[j][0]][same[i].second + dir[j][1]] < G[same[i].first][same[i].second])) return 0;
        }
    }
    return 1;
}

void solve() {
    H = firstLine - 1;
    W = strlen(G[0]);
    int ans = 0;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!vis[i][j]) {
                vis[i][j] = true;
                same.push_back(make_pair(i, j));
                dfs(i, j);
                ans += check();
                same.clear();
            }
        }
    }

    cout << ans << endl;

}

int main() {

    std::cout.sync_with_stdio(false);

    firstLine = 0;

    while (1) {

        cin >> G[firstLine++];

        if (cin.eof()) {
            solve();
            break;
        }

        if (G[firstLine - 1][0] == '*') {
            solve();
            firstLine = 0;
        }

    }

    return 0;
}                                 
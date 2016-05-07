// Problem#: 13061
// Submission#: 3412393
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

const int MAX = 260;

char G[MAX][MAX];
int colSize[MAX];
int W, H;
vector<pair<int, int> > block;
bool vis[MAX][MAX];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void DFS(int nowi, int nowj) {
    vis[nowi][nowj] = true;
    block.push_back(make_pair(nowi, nowj));
    for (int i = 0; i < 4; i++) {
        int nexti = nowi + dir[i][0];
        int nextj = nowj + dir[i][1];
        if (0 <= nextj && nextj < W && 0 <= nexti && nexti < colSize[nextj] && G[nexti][nextj] == G[nowi][nowj] && !vis[nexti][nextj])
            DFS(nexti, nextj);
    }
}

void Slide() {
    for (int i = 0; i < W; i++) {
        queue<char> q;
        for (int j = 0; j < colSize[i]; j++) {
            if (G[j][i] != ' ') q.push(G[j][i]);
        }
        colSize[i] = q.size();
        for (int j = 0; j < colSize[i]; j++) {
            G[j][i] = q.front();
            q.pop();
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int counter = 1;

    while (1) {
        cin >> W >> H;
        if (!W && !H) break;
        for (int i = H - 1; i >= 0; i--) cin >> G[i];
        for (int i = 0; i < W; i++) colSize[i] = H;
        bool isEnd;
        while (1) {
            isEnd = true;
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < colSize[i]; j++) {
                    vis[j][i] = false;
                }
            }
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < colSize[i]; j++) {
                    block.clear();
                    if (G[j][i] != ' ') DFS(j, i);
                    if (block.size() >= 4) {
                        isEnd = false;
                        int s = block.size();
                        for (int k = 0; k < s; k++) G[block[k].first][block[k].second] = ' ';
                    }
                }
            }
            if (isEnd) break;
            Slide();
        }
        int ans = 0;
        for (int i = 0; i < W; i++) ans += colSize[i];
        cout << counter++ << ": " << ans << endl;
    }

    return 0;
}                                 
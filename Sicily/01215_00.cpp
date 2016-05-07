// Problem#: 1215
// Submission#: 3293563
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

char G[25][25];
int H, W;
short vis[21][21][21][21];

struct step {
    int pi, pj, hi, hj, num;
    step() {}
    step(int pii, int pjj, int hii, int hjj, int n) {
        pi = pii;
        pj = pjj;
        hi = hii;
        hj = hjj;
        num = n;
    }
};

int pdir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int hdir[4][2];
step firstStep;

bool isValid(step & s) {
    return G[s.pi][s.pj] != '#' && G[s.pi][s.pj] != '!' && G[s.hi][s.hj] != '!';
}

bool meet(step & now, step & next) {
    return (next.pi == next.hi && next.pj == next.hj) || (now.pi == next.hi && now.pj == next.hj && now.hi == next.pi && now.hj == next.pj);
}

void bfs() {
    queue<step> q;
    firstStep.num = 0;
    q.push(firstStep);
    vis[firstStep.pi][firstStep.pj][firstStep.hi][firstStep.hj] = 1;

    while (!q.empty()) {
        step now = q.front();
        q.pop();

        if (now.num > 255) break;

        for (int i = 0; i < 4; i++) {
            step next;
            next.pi = now.pi + pdir[i][0];
            next.pj = now.pj + pdir[i][1];
            next.hi = now.hi + hdir[i][0];
            next.hj = now.hj + hdir[i][1];
            next.num = now.num + 1;
            if (isValid(next)) {
                if (G[next.hi][next.hj] == '#') {
                    next.hi = now.hi;
                    next.hj = now.hj;
                }
                if (!vis[next.pi][next.pj][next.hi][next.hj]) {
                    vis[next.pi][next.pj][next.hi][next.hj] = true;
                    if (meet(now, next)) {
                        cout << next.num << endl;
                        return;
                    }
                    q.push(next);
                }
            }
        }
    }

    cout << "Impossible" << endl;

}

int main() {

    std::ios::sync_with_stdio(false);

    while (cin >> H >> W) {

        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < H; i++) cin >> G[i];

        string dir;
        cin >> dir;
        for (int i = 0; i < 4; i++) {
            if (dir[i] == 'N') hdir[i][0] = -1, hdir[i][1] = 0;
            if (dir[i] == 'S') hdir[i][0] = 1, hdir[i][1] = 0;
            if (dir[i] == 'E') hdir[i][0] = 0, hdir[i][1] = 1;
            if (dir[i] == 'W') hdir[i][0] = 0, hdir[i][1] = -1;
        }

        for (int i = 0; i < H; i++) 
            for (int j = 0; j < W; j++) 
                if (G[i][j] == 'H') firstStep.hi = i, firstStep.hj = j;
                else if (G[i][j] == 'P') firstStep.pi = i, firstStep.pj = j;

        bfs();

    }

    //cin >> N;

    return 0;
}                                 
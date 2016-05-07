// Problem#: 1754
// Submission#: 3326115
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

const int MAX_W = 1005;

bool visGas[MAX_W][MAX_W];
bool visP[MAX_W][MAX_W];
char G[MAX_W][MAX_W];
int H, W;
int Ei, Ej;
queue<pair<int, int> > gas;
queue<pair<int, int> > q;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int step;

bool isValidGas(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W && !visGas[i][j] && (G[i][j] == '.' || G[i][j] == 'P');
}

bool isValidP(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W && !visP[i][j] && G[i][j] == '.';
}

void GAS() {
    int s = gas.size();
    while (s--) {
        pair<int, int> p = gas.front();
        gas.pop();
        for (int i = 0; i < 4; i++) {
            int nextI = p.first + dir[i][0];
            int nextJ = p.second + dir[i][1];
            if (isValidGas(nextI, nextJ)) {
                G[nextI][nextJ] = 'D';
                visGas[nextI][nextJ] = true;
                gas.push(make_pair(nextI, nextJ));
            }
        }
    }
}

bool BFS() {
    step = 0;
    while (!q.empty()) {
        int s = q.size();
        GAS();
        step++;
        while (s--) {
            pair<int, int> p = q.front();
            q.pop();
            //if (G[p.first][p.second] == 'D') continue;
            for (int i = 0; i < 4; i++) {
                int nextI = p.first + dir[i][0];
                int nextJ = p.second + dir[i][1];
                if (nextI == Ei && nextJ == Ej) return true;
                if (isValidP(nextI, nextJ)) {
                    visP[nextI][nextJ] = true;
                    q.push(make_pair(nextI, nextJ));
                }
            }
        }
    }
    return false;
}

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;
        for (int i = 0; i < H; i++) {
            cin >> G[i];
            for (int j = 0; j < W; j++) {
                if (G[i][j] == '.') visP[i][j] = visGas[i][j] = false;
                if (G[i][j] == 'D') {
                    gas.push(make_pair(i, j));
                    visGas[i][j] = true;
                }
                if (G[i][j] == 'P') {
                    q.push(make_pair(i, j));
                    visP[i][j] = true;
                }
                if (G[i][j] == 'E') {
                    Ei = i;
                    Ej = j;
                }
            }
        }
        if (BFS()) cout << step << endl;
        else cout << "YYR is extremely dangerous!" << endl;
        while (!gas.empty()) gas.pop();
        while (!q.empty()) q.pop();
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
// Problem#: 1187
// Submission#: 3201685
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

#define MAX_N 55

char G[MAX_N][MAX_N];
int n, r;
bool vis[MAX_N][MAX_N][4];
int X, Y, dir;  // 0->east, 1->south, 2->west, 3->north
int endX, endY;
bool death;

void Go() {
    while (1) {
        if (dir == 0) {
            int i;
            for (i = X + 1; i <= n; i++) {
                if (G[Y][i] == 'M') break;
            }
            if (i > n) {
                endX = i;
                endY = Y;
                break;
            }
            if (vis[Y][i][1]) {
                death = true;
                break;
            }
            vis[Y][i][1] = true;
            X = i;
            dir = 1;
        } else if (dir == 1) {
            int i;
            for (i = Y - 1; i > 0; i--) {
                if (G[i][X] == 'M') break;
            }
            if (i == 0) {
                endX = X;
                endY = i;
                break;
            }
            if (vis[i][X][2]) {
                death = true;
                break;
            }
            vis[i][X][2] = true;
            Y = i;
            dir = 2;
        } else if (dir == 2) {
            int i;
            for (i = X - 1; i > 0; i--) {
                if (G[Y][i] == 'M') break;
            }
            if (i == 0) {
                endX = i;
                endY = Y;
                break;
            }
            if (vis[Y][i][3]) {
                death = true;
                break;
            }
            vis[Y][i][3] = true;
            X = i;
            dir = 3;
        } else {
            int i;
            for (i = Y + 1; i <= n; i++) {
                if (G[i][X] == 'M') break;
            }
            if (i > n) {
                endX = X;
                endY = i;
                break;
            }
            if (vis[i][X][0]) {
                death = true;
                break;
            }
            vis[i][X][0] = true;
            Y = i;
            dir = 0;
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        cin >> n >> r;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = '.';
            }
        }
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < r; i++) {
            int x, y;
            cin >> x >> y;
            G[y][x] = 'M';
        }
        cin >> X >> Y;
        if (X == n + 1) dir = 2;
        if (X == 0) dir = 0;
        if (Y == n + 1) dir = 1;
        if (Y == 0) dir = 3;

        death = false;
        Go();

        if (death) cout << "0 0" << endl;
        else cout << endX << " " << endY << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
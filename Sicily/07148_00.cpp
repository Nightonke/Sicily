// Problem#: 7148
// Submission#: 3406186
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

const int MAX_SIZE = 501;

int R, C, T, H, W;
char G[MAX_SIZE][MAX_SIZE];
int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

int main() {

    std::ios::sync_with_stdio(false);

    bool firstTime = true;

    while (1) {
        cin >> H >> W;
        if (cin.eof()) break;
        R = C = T = 0;
        int mini, minj, maxi, maxj;
        int broadSize, starSize;
        for (int i = 0; i < H; i++) cin >> G[i];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (G[i][j] == '#') {
                    starSize = 1;
                    maxi = mini = i;
                    maxj = minj = j;
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    G[i][j] = 'v';
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (int j = 0; j < 8; j++) {
                            int ii = p.first + dir[j][0];
                            int jj = p.second + dir[j][1];
                            if (0 <= ii && ii < H && 0 <= jj && jj < W && G[ii][jj] == '#') {
                                q.push(make_pair(ii, jj));
                                G[ii][jj] = 'v';
                                starSize++;
                                if (mini > ii) mini = ii;
                                if (minj > jj) minj = jj;
                                if (maxi < ii) maxi = ii;
                                if (maxj < jj) maxj = jj;
                            }
                        }
                    }
                    broadSize = (maxi - mini + 1) * (maxj - minj + 1);
                    if (1.0 * starSize >= broadSize * 0.88) R++;
                    else if (1.0 * starSize <= broadSize * 0.75) T++;
                    else C++;
                }
            }
        }
        cout << "Rectangle: " << R << endl;
        cout << "Circle: " << C << endl;
        cout << "Triangle: " << T << endl << endl;
    }

    return 0;
}                                 
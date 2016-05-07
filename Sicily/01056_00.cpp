// Problem#: 1056
// Submission#: 3458950
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
#include <set>
using namespace std;

const int MAX_W = 100;

int W, H, N, Si, Sj;
char G[MAX_W][MAX_W];
int StepSum;
char step[MAX_W * MAX_W];
bool finish;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

struct Next {
    int i, j, p;
    Next(int ii = 0, int jj = 0, int pp = 0) {
        i = ii;
        j = jj;
        p = pp;
    }
};

bool judge() {
    int w, b;
    w = b = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == ' ') {
                if ((i + j) & 1) b++;
                else w++;
            }
        }
    }
    return b == w;
}

bool isIn(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

int calPossibility(int i, int j) {
    int p = 0;
    for (int k = 0; k < 4; k++) {
        if (isIn(i + dir[k][0], j + dir[k][1]) && (G[i + dir[k][0]][j + dir[k][1]] == ' ' || (i + dir[k][0] == Si && j + dir[k][1] == Sj))) p++;
    }
    return p;
}

bool cmp(const Next & n1, const Next & n2) {
    return n1.p < n2.p;
}

void dfs(int nowStep, int lastI, int lastJ) {
    if (nowStep == StepSum) {
        bool canArrive = false;
        for (int i = 0;  i < 4; i++) {
            if (isIn(lastI + dir[i][0], lastJ + dir[i][1]) && lastI + dir[i][0] == Si && lastJ + dir[i][1] == Sj) {
                if (dir[i][0] == -1) step[nowStep] = 'N';
                if (dir[i][0] == 1) step[nowStep] = 'S';
                if (dir[i][1] == 1) step[nowStep] = 'E';
                if (dir[i][1] == -1) step[nowStep] = 'W';
                finish = true;
                break;
            }
        }
        return;
    }
    Next next[4];
    int num = 0;
    for (int i = 0; i < 4; i++) {
        int nexti = lastI + dir[i][0];
        int nextj = lastJ + dir[i][1];
        if (isIn(nexti, nextj) && G[nexti][nextj] == ' ') {
            next[num++] = Next(nexti, nextj, calPossibility(nexti, nextj));
        }
    }
    sort(next, next + num, cmp);
    bool mustGo = false;
    for (int i = 0; i < num; i++) {
        if (next[i].p == 0) return;
        if (next[i].p == 1) mustGo = true;
        G[next[i].i][next[i].j] = '.';
        if (next[i].i < lastI) step[nowStep] = 'N';
        if (next[i].i > lastI) step[nowStep] = 'S';
        if (next[i].j > lastJ) step[nowStep] = 'E';
        if (next[i].j < lastJ) step[nowStep] = 'W';
        dfs(nowStep + 1, next[i].i, next[i].j);
        if (!finish) {
            G[next[i].i][next[i].j] = ' ';
            if (mustGo) return;
        } else return;
    }
}

void specialSolve() {
    int all = H * W, now = 0;
    int nowi = Si, nowj = Sj;
    finish = true;
    if (W % 2 == 0) {  // 如果列数是偶数
        while (now < all) {
            if (nowi == 0) {  // 如果在第一行
                if (nowj == W - 1) {  // 如果在第一行最右向南
                    step[now] = 'S';
                    nowi++;
                } else {  // 否则都向东
                    step[now] = 'E';
                    nowj++;
                }
            } else {  // 如果不在第一行
                if (nowj % 2 == 0) {  // 如果在偶数列
                    if (nowi == 1 && nowj != 0) {  // 如果在第二行并且不是第一列的第二行向西
                        step[now] = 'W';
                        nowj--;
                    } else {  // 如果不在第二行，或者在第一列的第二行向北
                        step[now] = 'N';
                        nowi--;
                    }
                } else {  // 如果在奇数列
                    if (nowi == H - 1) {  // 如果在最后一行向西
                        step[now] = 'W';
                        nowj--;
                    } else {  // 否则都向南
                        step[now] = 'S';
                        nowi++;
                    }
                }
            }
            now++;
        }
    } else {
        while (now < all) {
            if (nowj == 0) {
                if (nowi == 0) {
                    step[now] = 'E';
                    nowj++;
                } else {
                    step[now] = 'N';
                    nowi--;
                }
            } else {
                if (nowi % 2 == 1) {
                    if (nowj == 1 && nowi != H - 1) {
                        step[now] = 'S';
                        nowi++;
                    } else {
                        step[now] = 'W';
                        nowj--;
                    }
                } else {
                    if (nowj == W - 1) {
                        step[now] = 'S';
                        nowi++;
                    } else {
                        step[now] = 'E';
                        nowj++;
                    }
                }
            }
            now++;
        }
    }
}

void output() {
    if (!finish) {
        cout << "NO SOLUTION" << endl << endl;
        return;
    }
    for (int i = 0, counter = 0; i <= StepSum; i++, counter++) {
        if (counter == 40) {
            counter = 0;
            cout << endl;
        }
        cout << step[i];
    }
    cout << endl << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> H >> W >> N >> Sj >> Si;
        if (!H) break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                G[i][j] = ' ';
            }
        }
        for (int i = 0; i < N; i++) {
            int ti, tj;
            cin >> tj >> ti;
            G[ti][tj] = 'X';
        }
        finish = false;
        StepSum = W * H - N - 1;
        if (H < 2 || W < 2 || !judge()) {
            output();
            continue;
        }
        if (N == 0) {
            specialSolve();
            output();
            continue;
        }
        G[Si][Sj] = '.';
        dfs(0, Si, Sj);
        output();
    }

    return 0;
}                                 
// Problem#: 1254
// Submission#: 3455276
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

char B[5][5];
int ans;
bool vis[2097152];
int ep[21] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};

struct peg {
    int i, j;
    int poss;
    peg(int ii = 0, int jj = 0, int pp = 0) {
        i = ii;
        j = jj;
        poss = pp;
    }
};

int canJump(int i, int j) {
    int re = 0;
    if (i < 3 && B[i + 1][j] == 'o' && B[i + 2][j] == '.') re++;
    if (j < 3 && B[i][j + 1] == 'o' && B[i][j + 2] == '.') re++;
    if (i > 1 && B[i - 1][j] == 'o' && B[i - 2][j] == '.') re++;
    if (j > 1 && B[i][j - 1] == 'o' && B[i][j - 2] == '.') re++;
    return re;
}

bool cmp(const peg & p1, const peg & p2) {
    return p1.poss < p2.poss;
}

void writeVIS() {
    int pos = 0;
    int counter = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (B[i][j] == 'o') {
                pos += 1 * ep[counter];
            }
            if (B[i][j] != '#') counter++;
        }
    }
    vis[pos] = true;
}

bool readVIS() {
    int pos = 0;
    int counter = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (B[i][j] == 'o') {
                pos += 1 * ep[counter];
            }
            if (B[i][j] != '#') counter++;
        }
    }
    return vis[pos];
}

void dfs(int now) {
    if (ans == 1) return;
    if (readVIS()) return;
    writeVIS();
    peg P[20];
    int num = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (B[i][j] == 'o') {
                int p = canJump(i, j);
                if (p) P[num++] = peg(i, j, p);
            }
        }
    }
    if (num == 0) {
        ans = min(ans, now);
        return;
    }
    sort(P, P + num, cmp);
    for (int i = 0; i < num; i++) {
        char temp[5][5];
        if (P[i].i < 3 && B[P[i].i + 1][P[i].j] == 'o' && B[P[i].i + 2][P[i].j] == '.') {
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) temp[q][p] = B[q][p];
            B[P[i].i][P[i].j] = '.';
            B[P[i].i + 1][P[i].j] = '.';
            B[P[i].i + 2][P[i].j] = 'o';
            dfs(now - 1);
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) B[q][p] = temp[q][p];
        }
        if (P[i].j < 3 && B[P[i].i][P[i].j + 1] == 'o' && B[P[i].i][P[i].j + 2] == '.') {
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) temp[q][p] = B[q][p];
            B[P[i].i][P[i].j] = '.';
            B[P[i].i][P[i].j + 1] = '.';
            B[P[i].i][P[i].j + 2] = 'o';
            dfs(now - 1);
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) B[q][p] = temp[q][p];
        }
        if (P[i].i > 1 && B[P[i].i - 1][P[i].j] == 'o' && B[P[i].i - 2][P[i].j] == '.') {
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) temp[q][p] = B[q][p];
            B[P[i].i][P[i].j] = '.';
            B[P[i].i - 1][P[i].j] = '.';
            B[P[i].i - 2][P[i].j] = 'o';
            dfs(now - 1);
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) B[q][p] = temp[q][p];
        }
        if (P[i].j > 1 && B[P[i].i][P[i].j - 1] == 'o' && B[P[i].i][P[i].j - 2] == '.') {
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) temp[q][p] = B[q][p];
            B[P[i].i][P[i].j] = '.';
            B[P[i].i][P[i].j - 1] = '.';
            B[P[i].i][P[i].j - 2] = 'o';
            dfs(now - 1);
            for (int q = 0; q < 5; q++) for (int p = 0; p < 5; p++) B[q][p] = temp[q][p];
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        ans = 0;
        for (int i = 0; i < 5; i++) {
            cin >> B[i];
            for (int j = 0; j < 5; j++) {
                if (B[i][j] == 'o') ans++;
            }
        }
        memset(vis, 0, sizeof(vis));
        dfs(ans);
        cout << "The best case ends with " << ans << " pegs." << endl;
    }

    return 0;
}                                 
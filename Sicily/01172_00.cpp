// Problem#: 1172
// Submission#: 3224536
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

#define MAX 1005

char board[MAX][MAX];
int w, h;
int qn ,kn, pn;
short qi[105], qj[105];
short ki[105], kj[105];
short pi[105], pj[105];
short ka[8][2] = {-1, -2, -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2};
short qa[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

int main() {

    //std::ios::sync_with_stdio(false);

    int counter = 1;

    while (1) {
        scanf("%d%d", &h, &w);
        if (h == 0 && w == 0) break;

        int i, j, k;
        for (i = 1; i <= h; i++) {
            for (j = 1; j <= w; j++) {
                board[i][j] = '\0';
            }
        }
        for (scanf("%d", &qn), i = 0; i < qn; i++) scanf("%d%d", &qi[i], &qj[i]);
        for (scanf("%d", &kn), i = 0; i < kn; i++) scanf("%d%d", &ki[i], &kj[i]);
        for (scanf("%d", &pn), i = 0; i < pn; i++) scanf("%d%d", &pi[i], &pj[i]);

        for (i = 0; i < kn; i++) {
            board[ki[i]][kj[i]] = 'K';
            for (j = 0; j < 8; j++) {
                int tempi = ki[i] + ka[j][0], tempj = kj[i] + ka[j][1];
                if (1 <= tempi && tempi <= h && 1 <= tempj && tempj <= w && board[tempi][tempj] == '\0') board[tempi][tempj] = 'X';
            }
        }

        for (i = 0; i < pn; i++) board[pi[i]][pj[i]] = 'P';
        
        for (i = 0; i < qn; i++) {
            board[qi[i]][qj[i]] = 'Q';
        }

        for (i = 0; i < qn; i++) {
            for (j = 0; j < 8; j++) {
                int tempi = qi[i] + qa[j][0], tempj = qj[i] + qa[j][1];
                while (1 <= tempi && tempi <= h && 1 <= tempj && tempj <= w && (board[tempi][tempj] == '\0' || board[tempi][tempj] == 'X')) {
                    board[tempi][tempj] = 'X';
                    tempi += qa[j][0];
                    tempj += qa[j][1];
                }
            }
        }

        int ans = 0;
        for (i = 1; i <= h; i++) {
            for (j = 1; j <= w; j++) {
                if (board[i][j] == '\0') ans++;
                board[i][j] = '\0';
            }
        }

        printf("Board %d has %d safe squares.\n", counter, ans);

        counter++;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
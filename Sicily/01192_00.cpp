// Problem#: 1192
// Submission#: 3419974
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

const int MAX_N = 505;

struct pupil {
    int h;
    char sex;
    string mu, sp;
};

bool love[MAX_N][MAX_N];
int N;
pupil B[MAX_N], G[MAX_N];
int BN, GN;
bool used[MAX_N];
int GsLover[MAX_N];

bool Find(int b) {
    for (int j = 0; j < GN; j++) {
        if (love[b][j] && !used[j]) {
            used[j] = true;
            if (GsLover[j] == -1 || Find(GsLover[j])) {
                GsLover[j] = b;
                return true;
            }
        }
    }
    return false;
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        cin >> N;
        BN = GN = 0;
        for (int i = 0; i < N; i++) {
            pupil temp;
            cin >> temp.h >> temp.sex >> temp.mu >> temp.sp;
            if (temp.sex == 'F') G[GN++] = temp;
            else B[BN++] = temp;
        }
        for (int i = 0; i < BN; i++) {
            for (int j = 0; j < GN; j++) {
                love[i][j] = false;
                if (abs(B[i].h - G[j].h) <= 40 && B[i].mu == G[j].mu && B[i].sp != G[j].sp) love[i][j] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < GN; i++) GsLover[i] = -1;
        for (int i = 0; i < BN; i++) {
            memset(used, false, sizeof(bool) * GN);
            if (Find(i)) ans++;
        }
        cout << N - ans << endl;
    }

    return 0;
}                                 
// Problem#: 1005
// Submission#: 3149053
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

#define MAX_SUM 1100

int d[25][MAX_SUM];
int require[15][2];
int ans[15];
int n;
int r;
int f;
bool possible;
bool found;
int MAX_X;
int MIN_X;
int Min;
int Max;

void make() {
    memset(d, 0, sizeof(d));
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        d[1][temp] += 1;
    }
    for (int i = 2; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            for (int k = 0; k < MAX_SUM; k++) {
                if (d[i - 1][k] != 0) {
                    d[i][k + temp] += d[i - 1][k];
                }
            }
        }
    }
    cin >> f;
    cin >> r;
    for (int i = 0; i < r; i++) {
        cin >> require[i][0] >> require[i][1];
    }
    for (int i = 0; i < MAX_SUM; i++) {
        if (d[n][i]) {
            Min = i;
            break;
        }
    }
    for (int i = MAX_SUM - 1; i >= 0; i--) {
        if (d[n][i]) {
            Max = i;
            break;
        }
    }
    for (int i = 0; i < r; i++) {
        if (require[i][1] != 0 && require[i][0] > Max + 50) {
            possible = false;
            return;
        }
    }
    MIN_X = 1;
    MAX_X = 50;
}

void DFS(int pos, int last) {

    if (pos == f) {
        for (int i = 0; i < r; i++) {
            if (require[i][1] != 0) return;
        }
        found = true;
        return;
    }
            
    for (int i = last; i <= 50; i++) {
        for (int j = 0; j < r; j++) {
            if (require[j][1] != 0 && Min + i > require[j][0]) return;
        }
        ans[pos] = i;
        bool goOn = true;
        for (int j = 0; j < r; j++) {
            if (require[j][0] - i > 0) {
                require[j][1] -= d[n][require[j][0] - i];
                if (require[j][1] < 0) goOn = false;
            }
        }
        if (goOn) DFS(pos + 1, i);
        if (found) return;
        for (int j = 0; j < r; j++) {
            if (require[j][0] - i > 0) {
                require[j][1] += d[n][require[j][0] - i];
            }
        }
    }
}

int main() {

    

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> n;
        if (!n) break;
        possible = true;
        found = false;
        make();
        if (possible) DFS(0, 1);
        if (possible && found) {
            cout << "Final die face values are";
            for (int i = 0; i < f; i++) {
                cout << " " << ans[i];
            }
            cout << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
// Problem#: 1224
// Submission#: 3281313
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
using namespace std;

const int MAX_N = 1005;

int N;
int men[MAX_N][MAX_N];
int women[MAX_N][MAX_N];
int point[MAX_N][MAX_N];
int menChoose[MAX_N];
vector<int> choosed[MAX_N];

int main() {

    std::ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> men[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> women[i][j];
            point[i][women[i][j]] = N - j;
        }
    }

    for (int i = 1; i <= N; i++) menChoose[i] = 1;

    while (1) {
        bool shouldEnd = true;
        for (int i = 1; i <= N; i++) choosed[i].clear();
        for (int i = 1; i <= N; i++) {
            choosed[men[i][menChoose[i]]].push_back(i);
        }
        for (int i = 1; i <= N; i++) {
            if (choosed[i].size() > 1) {
                shouldEnd = false;
                break;
            }
        }
        if (shouldEnd) break;
        for (int i = 1; i <= N; i++) {
            int s = choosed[i].size();
            if (s > 1) {
                int MaxPoint = -1;
                int MaxPos = -1;
                for (int j = 0; j < s; j++) {
                    if (point[i][choosed[i][j]] > MaxPoint) {
                        MaxPoint = point[i][choosed[i][j]];
                        MaxPos = choosed[i][j];
                    }
                }
                for (int j = 0; j < s; j++) {
                    if (choosed[i][j] != MaxPos) menChoose[choosed[i][j]]++;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << men[i][menChoose[i]] << endl;
    }

    return 0;
}                                 
// Problem#: 12993
// Submission#: 3411625
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

pair<int, int> T[10][520];
int N;

int LOG(int f, int n) {
    int ans = 0;
    int s = 1;
    for (; s != n; s *= f) ans++;
    return ans;
}

bool check(int line, int n) {
    if (n == 1) return (T[line][0].first == 0 && T[line][0].second == 0);
    for (int i = 0; i < n; i += 2) {
        if (T[line][i].first < 0 || T[line][i].second < 0 || max(T[line][i].first, T[line][i].second) < 4) return false;
        if (T[line][i + 1].first < 0 || T[line][i + 1].second < 0 || max(T[line][i + 1].first, T[line][i + 1].second) < 4) return false;
        pair<int, int> winner, loser;
        if (T[line][i].first > T[line][i + 1].first) {
            winner = T[line][i];
            loser = T[line][i + 1];
        } else if (T[line][i].first < T[line][i + 1].first) {
            winner = T[line][i + 1];
            loser = T[line][i];
        } else {
            return false;
        }
        if (loser.first > min(3, winner.second)) return false;
        if (loser.second > min(4, winner.first)) return false;
        if (winner.first < 4 || winner.first < loser.second) return false;
        if (winner.second < loser.first) return false;
    }
    return true;
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;
    int counter = 1;

    while (caseNum--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> T[0][i].first >> T[0][i].second;
        int times = LOG(2, N);
        int n = N;
        bool possible = true;
        for (int i = 0; i < times; i++) {
            if (!check(i, n)) {
                possible = false;
                break;
            }
            for (int j = 0; j < n; j += 2) {
                if (T[i][j].first > T[i][j + 1].first) {
                    T[i + 1][j / 2] = make_pair(T[i][j].first - T[i][j + 1].second, T[i][j].second - T[i][j + 1].first);
                } else {
                    T[i + 1][j / 2] = make_pair(T[i][j + 1].first - T[i][j].second, T[i][j + 1].second - T[i][j].first);
                }
            }
            n /= 2;
        }
        if (!check(times, 1)) possible = false;
        cout << "Tournament #" << counter++ << ": " << (possible ? "Possible" : "Impossible") << endl << endl;
    }

    return 0;
}                                 
// Problem#: 1404
// Submission#: 3245700
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
#include <set>
using namespace std;

const int MAX_N = 15;
const int MAX_STATUS = 1050;
const int INF = 99999999;

int N;
int G[MAX_N][MAX_N];
int dp[MAX_STATUS][MAX_N];

inline bool visitJ(int i, int j) {
    while (j--) i /= 2;
    return i % 2;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                cin >> G[i][j];
            }
        }
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    if (k != i && i != j && j != k && G[i][k] + G[k][j] < G[i][j]) G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
        int max_status = pow(2, N);
        for (int i = 0; i < max_status; i++) {
            for (int j = 0; j <= N; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < max_status; i++) {
            for (int j = 1; j <= N; j++) {
                if (visitJ(i, j - 1)) {
                    if (i == pow(2, j - 1)) {
                        dp[i][j] = G[0][j];
                    } else {
                        int lastI = i - pow(2, j - 1);
                        //cout << i << " " << j << " " << lastI << endl;
                        dp[i][j] = INF;
                        for (int k = 1; k <= N; k++) {
                            if (k != j && visitJ(i, k - 1) && dp[i][j] > dp[lastI][k] + G[k][j]) dp[i][j] = dp[lastI][k] + G[k][j];
                        }
                    }
                }
            }
        }
        int ans = dp[max_status - 1][1] + G[1][0];
        for (int i = 2; i <= N; i++) {
            if (dp[max_status - 1][i] + G[i][0] < ans) ans = dp[max_status - 1][i] + G[i][0];
        }
        cout << ans << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
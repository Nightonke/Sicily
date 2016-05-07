// Problem#: 1828
// Submission#: 3342649
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

const int MAX_N = 505;
const int INF = 99999999;

int a[MAX_N], b[MAX_N];
int dp[MAX_N][MAX_N];

int main() {

    std::ios::sync_with_stdio(false);
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) cin >> a[i];
        for (int i = 1; i <= M; i++) cin >> b[i];
        sort(a + 1, a + N + 1);
        sort(b + 1, b + M + 1);
        for (int i = 1; i <= N; i++) {
            if (i == 1) dp[i][i] = abs(a[i] - b[i]);
            else dp[i][i] = dp[i - 1][i - 1] + abs(a[i] - b[i]);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= M; j++) {
                dp[i][j] = min(dp[i - 1][j - 1] + abs(a[i] - b[j]), dp[i][j - 1]);
            }
        }
        cout << dp[N][M] << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
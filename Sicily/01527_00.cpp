// Problem#: 1527
// Submission#: 3318407
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

const int MAX_N = 1005;

int dp[MAX_N][16];

int main() {

    std::ios::sync_with_stdio(false);

    dp[1][0] = dp[1][3] = dp[1][6] = dp[1][12] = dp[1][15] = 1;

    for (int i = 2; i < MAX_N; i++) {

        for (int j = 0; j <= 15; j++) dp[i][j] += dp[i - 1][15 - j];

        //竖放0个
        //dp[i][0] += dp[i - 1][15];

        //竖放1个
        dp[i][3] += dp[i - 1][15];
        dp[i][6] += dp[i - 1][15];
        dp[i][12] += dp[i - 1][15];

        dp[i][7] += dp[i][1];
        dp[i][13] += dp[i][1];  // ?
        dp[i][14] += dp[i][2];
        dp[i][7] += dp[i][4];
        dp[i][14] += dp[i][8];
        dp[i][11] += dp[i][8];  // ?

        //竖放两个
        dp[i][15] += dp[i - 1][15];

        //混合2横一竖
        dp[i][15] += dp[i - 1][3];
        dp[i][15] += dp[i - 1][6];
        dp[i][15] += dp[i - 1][12];

    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int pos;
        cin >> pos;
        cout << i << " " << dp[pos][15] << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
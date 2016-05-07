// Problem#: 1148
// Submission#: 3237242
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

const int MAX = 10050;

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
    
        int L;
        int dp[MAX];
        int stone[MAX];
        int stonePos[105];
        int s, t, m;
        cin >> L >> s >> t >> m;
        if (cin.eof()) break;
        stonePos[0] = 0;
        for (int i = 1; i <= m; i++) cin >> stonePos[i];
        sort(stonePos + 1, stonePos + m + 1);

        if (s == t) {  // 由于后面有状态压缩，所以这里要进行特殊情况的处理
            int ans = 0;
            for (int i = 1; i <= m; i++) {
                if (stonePos[i] % s == 0) ans++;
            }
            cout << ans << endl;
            continue;
        }

        for (int i = 1; i <= m; i++) {  // 状态压缩，如果两个石头的距离大于90，就设为90
            if (stonePos[i] - stonePos[i - 1] > 90) {
                int moveDistance = stonePos[i] - (stonePos[i - 1] + 90);
                for (int j = i; j <= m; j++) stonePos[j] -= moveDistance;
            }
        }

        for (int i = 0; i < MAX; i++) stone[i] = 0;
        for (int i = 1; i <= m; i++) stone[stonePos[i]] = 1;
        for (int i = 1; i < MAX; i++) dp[i] = -1;
        dp[0] = 0;
        L = stonePos[m] + 90;
        for (int i = 0; i < L; i++) {
            if (dp[i] == -1) continue;
            for (int j = i + s; j <= i + t; j++) {
                if (dp[j] == -1 || dp[i] + stone[j] < dp[j]) dp[j] = dp[i] + stone[j];
            }
        }
        int ans = MAX;
        for (int i = L; i < L + t; i++) if (ans > dp[i] && dp[i] != -1) ans = dp[i];
        cout << ans << endl;

    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
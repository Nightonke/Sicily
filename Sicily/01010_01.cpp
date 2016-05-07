// Problem#: 1010
// Submission#: 3156442
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

#define MAX_C 205

bool dp[MAX_C][MAX_C];
char a[MAX_C], b[MAX_C], c[2 * MAX_C];

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;
    int counter = 1;

    while (caseNum--) {
        cin >> a >> b >> c;
        int alength = strlen(a);
        int blength = strlen(b);
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= blength; i++) {
            if (dp[0][i - 1] && b[i - 1] == c[i - 1]) dp[0][i] = true;
        }
        for (int i = 1; i <= alength; i++) {
            if (dp[i - 1][0] && a[i - 1] == c[i - 1]) dp[i][0] = true;  // 下标为i-1是第i个
        }
        for (int i = 1; i <= alength; i++) {
            for (int j = 1; j <= blength; j++) {
                if ((dp[i - 1][j] && a[i - 1] == c[i + j - 1]) || (dp[i][j - 1] && b[j - 1] == c[i + j - 1])) dp[i][j] = true;
            }
        }
        cout << "Data set " << counter++ << ": ";
        if (dp[alength][blength]) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
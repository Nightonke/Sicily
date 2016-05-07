// Problem#: 1902
// Submission#: 3368457
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
#include <math.h>
using namespace std;

int dp[505];

int main() {

    std::ios::sync_with_stdio(false);

    dp[0] = 1;
    for (int i = 2; i <= 500; i++) {
        for (int j = i; j <= 500; j++) {
            dp[j] += dp[j - i];
            if (dp[j] >= 1000007) dp[j] -= 1000007;
        }
    }
            
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int temp;
        cin >> temp;
        cout << dp[temp] << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
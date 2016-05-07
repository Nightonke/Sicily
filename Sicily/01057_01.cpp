// Problem#: 1057
// Submission#: 3240789
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

const int MAX_DIGIT = 1000;
const int MAX_SIZE = 51;

class NUM {
  public:
    NUM(string n = "0") {
        num = n;
    }
    NUM(int n) {
        while (n) {
            num += (n % 10) + '0';
            n /= 10;
        }
        reverse(num.begin(), num.end());
    }
    string num;
    friend NUM operator+(const NUM & left, const NUM & right) {
        int temp[MAX_DIGIT], l[MAX_DIGIT], r[MAX_DIGIT], ans[MAX_DIGIT];
        int lSize = left.num.size(), rSize = right.num.size();
        for (int i = 0; i < MAX_DIGIT; i++) {
            temp[i] = l[i] = r[i] = ans[i] = 0;
        }
        for (int i = 0; i < lSize; i++) {
            l[i] = left.num[lSize - i - 1] - '0';
        }
        for (int i = 0; i < rSize; i++) {
            r[i] = right.num[rSize - i - 1] - '0';
        }
    
        int maxlength = lSize > rSize ? lSize : rSize;
    
        for (int i = 0; i < maxlength; i++) {
            temp[i] += l[i] + r[i];
            temp[i + 1] += temp[i] / 10;
            temp[i] = temp[i] % 10;
        }
    
        int i = maxlength + 10;
        for (; temp[i] == 0 && i > 0; i--);
    
        for (int j = 0; j <= i; j++) {
            ans[j] = temp[i + 1 - j - 1];
        }
        NUM anss;
        anss.num.resize(i + 1);
        for (int j = 0; j < i + 1; j++) {
            anss.num[j] = ans[j] + '0';
        }
        return anss;
    }
    friend NUM operator*(const NUM & left, const NUM & right) {
        NUM counter("1");
        NUM one("1");
        NUM originalR = right;
        for (; counter != left; counter = counter + one) {
            originalR = originalR + right;
        }
        return originalR;
    }
    bool operator!=(const NUM & left) {
        return this->num != left.num;
    }
};


int main() {

    std::ios::sync_with_stdio(false);

    NUM dp[MAX_SIZE][MAX_SIZE];

    dp[0][0] = NUM("1");

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = NUM(j) * dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        NUM ans;
        for (int i = 1; i <= n; i++) {
            ans = ans + dp[n][i];
        }
        cout << n << " " << ans.num << endl;
    }
        
    //getchar();
    //getchar();
    
    return 0;
}                                 
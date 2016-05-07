// Problem#: 1874
// Submission#: 3272207
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
const int MAX_SIZE = 55;

string add(const string & left, const string & right) {
    int temp[MAX_DIGIT], l[MAX_DIGIT], r[MAX_DIGIT], ans[MAX_DIGIT];
    int lSize = left.size(), rSize = right.size();
    for (int i = 0; i < MAX_DIGIT; i++) {
        temp[i] = l[i] = r[i] = ans[i] = 0;
    }
    for (int i = 0; i < lSize; i++) {
        l[i] = left[lSize - i - 1] - '0';
    }
    for (int i = 0; i < rSize; i++) {
        r[i] = right[rSize - i - 1] - '0';
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
    string anss;
    anss.resize(i + 1);
    for (int j = 0; j < i + 1; j++) {
        anss[j] = ans[j] + '0';
    }
    return anss;
}

string multi(int n, const string & right) {
    string originalR = "0";
    for (int counter = 0; counter < n; counter++) {
        originalR = add(originalR, right);
    }
    return originalR;
}


int main() {

    std::ios::sync_with_stdio(false);

    string dp[MAX_SIZE][MAX_SIZE];

    dp[0][0] = "1";

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = add(multi(j, dp[i - 1][j]), dp[i - 1][j - 1]);
        }
        for (int j = i + 1; j < MAX_SIZE; j++) {
            dp[i][j] = "0";
        }
        dp[i][0] = "0";
    }

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int pigs, houses;
        cin >> pigs >> houses;
        cout << dp[pigs][houses] << endl;
    }
        
    //getchar();
    //getchar();
    
    return 0;
}                                 
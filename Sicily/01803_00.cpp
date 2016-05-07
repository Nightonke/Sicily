// Problem#: 1803
// Submission#: 3341060
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

const long long MOD = 1000000007;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        long long n, a1, da, b1, db;
        cin >> n >> a1 >> da >> b1 >> db;
        long long p1, p2, p3;
        p1 = ((a1 * b1) % MOD+ MOD) % MOD;
        p1 = (p1 * n) % MOD;
        p2 = ((a1 * db + b1 * da) % MOD + MOD) % MOD;
        p2 = (p2 * ((n * (n - 1) / 2) % MOD)) % MOD;
        p3 = ((da * db) % MOD + MOD) % MOD;
        long long temp = n * (n - 1) / 2;
        if (temp % 3 == 0) {
            temp = (temp / 3) % MOD;
            temp = (((2 * n - 1) % MOD) * temp) % MOD;
        } else {
            temp %= MOD;
            temp = ((((2 * n - 1) / 3) % MOD) * temp) % MOD;
        }
        p3 = (p3 * temp) % MOD;
        cout << (p1 + p2 + p3) % MOD << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
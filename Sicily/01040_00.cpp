// Problem#: 1040
// Submission#: 3283451
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
using namespace std;

const int MAX_N = 1005;

int N;
int men[MAX_N][MAX_N];
int women[MAX_N][MAX_N];
int point[MAX_N][MAX_N];
int menChoose[MAX_N];
vector<int> choosed[MAX_N];

int getDigits(int n) {
    int d = 0;
    while (n) {
        d++;
        n /= 10;
    }
    return d;
}

int main() {

    std::ios::sync_with_stdio(false);

    int maxPower, an, x, last;
    int c[105];
    int counter = 0;

    while (1) {
        counter++;
        cin >> maxPower >> an;
        if (maxPower == 0 && an == 0) break;
        for (int i = maxPower - 1; i >= 1; i--) {
            cin >> c[i];
        }
        cin >> last >> x;
        int ans = x;
        int cost = 0;
        for (int i = maxPower - 1; i >= 1; i--) {
            if (c[i]) {
                cost += 2;
                cost += getDigits(c[i]);
            } else {
                cost++;
            }
            ans = (ans + c[i]) * x;
        }
        ans += last;
        if (last) {
            cost += maxPower + 2 + getDigits(last);
        } else {
            cost += maxPower + 1;
        }
        if (maxPower) {
            cout << "Polynomial " << counter << ": " << ans << " " << cost << endl;
        } else {
            cout << "Polynomial " << counter << ": " << 1 << " " << 2 << endl;
        }
    }

    return 0;
}                                 
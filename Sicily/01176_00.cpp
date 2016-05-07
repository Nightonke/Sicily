// Problem#: 1176
// Submission#: 3290209
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

int dp[MAX_N][MAX_N];
int num[MAX_N];

int goDp(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l > r) return 0;
    int p1, p2;
    if (num[l + 1] >= num[r]) p1 = goDp(l + 2, r) + num[l] - num[l + 1];
    else p1 = goDp(l + 1, r - 1) + num[l] - num[r];
    if (num[l] >= num[r - 1]) p2 = goDp(l + 1, r - 1) + num[r] - num[l];
    else p2 = goDp(l, r - 2) + num[r] - num[r - 1];
    dp[l][r] = max(p1, p2);
    return dp[l][r];
}

int main() {

    std::ios::sync_with_stdio(false);
    
    int counter = 0;

    while (1) {
        counter++;
        int N;
        cin >> N;
        if (!N) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++) cin >> num[i];
        cout << "In game " << counter << ", the greedy strategy might lose by as many as " << goDp(0, N - 1) << " points." << endl;
    }


    //cin >> N;

    return 0;
}                                 
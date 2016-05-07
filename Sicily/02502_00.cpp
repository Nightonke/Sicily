// Problem#: 2502
// Submission#: 3233236
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

#define MAX 105

int main() {

    std::ios::sync_with_stdio(false);

    int needNum[MAX], val[MAX], cost[MAX];
    int n;
    cin >> n;
    needNum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> needNum[i];
        needNum[i] += needNum[i - 1];
    }
    for (int i = 1; i <= n; i++) cin >> val[i];

    for (int i = 1; i <= n; i++) {
        cost[i] = val[i] * (needNum[i] + 10);
        for (int j = 1; j < i; j++) {
            if (cost[j] + (needNum[i] - needNum[j] + 10) * val[i] < cost[i]) cost[i] = cost[j] + (needNum[i] - needNum[j] + 10) * val[i];
        }
    }

    cout << cost[n] << endl;

    //getchar();
    //getchar();
    
    return 0;
}                                 
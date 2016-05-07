// Problem#: 1499
// Submission#: 3393497
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
#include <map>
#include <string.h>
#include <math.h>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {

        int n, k, m, p, minK;
        cin >> n >> k >> m;
        if (!n) break;
        minK = k % n;
        int ans = (m - minK < 0 ? m - minK + n : m - minK);
        p = ans - 0;
        for (int i = 1; i <= n; i++) ans = (ans + k) % i;
        cout << (ans + p) % n + 1 << endl;


    }

    return 0;
}                                 
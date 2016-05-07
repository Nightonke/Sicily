// Problem#: 8536
// Submission#: 3378271
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

    int counter = 1;

    while (1) {
        int l, p, v;
        cin >> l >> p >> v;
        if (!l && !p && !v) break;
        cout << "Case " << counter++ << ": " << v / p * l + (v % p > l ? l : v % p) << endl;
    }

    return 0;
}                                 
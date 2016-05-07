// Problem#: 13060
// Submission#: 3417262
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
#include <list>
using namespace std;

bool ok[100005];

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        int N;
        cin >> N;
        if (cin.eof()) break;
        int sum = 0, temp;
        ok[0] = true;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            for (int j = sum; j >= 0; j--) {
                if (ok[j]) ok[j + temp] = true;
            }
            sum += temp;
        }
        for (int i = sum / 2; i >= 0; i--) {
            if (ok[i]) {
                cout << (long long)i * (sum - i) / 2 << endl;
                break;
            }
        }
        for (int i = 1; i <= sum; i++) ok[i] = false;
    }

    return 0;
}                                 
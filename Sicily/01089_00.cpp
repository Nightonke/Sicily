// Problem#: 1089
// Submission#: 3287981
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

const int MAX_N = 1000005;

int m[MAX_N], phi[MAX_N], p[MAX_N], pt;

void make() {
    phi[1] = 1;
    int N = MAX_N;
    int k;
    phi[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!m[i]) {
            p[pt++] = m[i] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < pt && (k = p[j] * i) < N; j++) {
            m[k] = p[j];
            if (m[i] == p[j]) {
                phi[k] = phi[i] * p[j];
                break;
            } else {
                phi[k] = phi[i] * (p[j] - 1);
            }
        }
    }
}

long long int ans[MAX_N];

void cal() {
    long long int sum = 0;
    for (int i = 2; i <= 1000000; i++) {
        sum += phi[i];
        ans[i] = sum;
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    make();
    cal();

    while (1) {
        int temp;
        cin >> temp;
        if (!temp) break;
        cout << ans[temp] << endl;
    }

    return 0;
}                                 
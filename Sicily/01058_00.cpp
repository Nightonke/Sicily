// Problem#: 1058
// Submission#: 3459542
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
#include <set>
using namespace std;

int N;
vector<vector<int> > v;

void output() {
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (j) cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> N;
        if (!N) break;
        if (((1 + N) * N / 2) % 2 == 1) {
            cout << 0 << endl << endl;
            continue;
        }
        v.clear();
        v.resize(N);
        int put;
        int vSize;
        if (N % 2) {
            put = 3;
            vSize = -1;
        } else {
            put = 4;
            vSize = 0;   
        }
        while (put <= N) {
            for (int i = 0; i <= vSize; i++) {
                v[i].push_back(put - 3);
                v[i].push_back(put - 2);
                v[i].push_back(put - 1);
                v[i].push_back(put);
            }
            v[vSize + 1].push_back(put - 2); v[vSize + 1].push_back(put);
            v[vSize + 2].push_back(put - 1); v[vSize + 2].push_back(put);
            v[vSize + 3].push_back(put - 1); v[vSize + 3].push_back(put);
            vSize += 4;
            put += 4;
        }
        output();
    }

    return 0;
}                                 
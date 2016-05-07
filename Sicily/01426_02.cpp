// Problem#: 1426
// Submission#: 2771683
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

string p[10005];

bool cmp(const string& a, const string& b) {
    for (int i = 0; i < (int)a.size() && i < (int)b.size(); i++) {
        if (a[i] == b[i])
            continue;
        else if (a[i] < b[i])
            return true;
        else
            return false;
    }
    return true;
}

bool is_ok(int n) {
    int k, j;
    for (int i = 0; i < n - 1; i++) {
        for (k = 0, j = i + 1; k < (int)p[i].size() && k < (int)p[j].size(); k++) {
            if (p[i][k] != p[j][k]) {
                break;
            }
        }
        if ((k >= (int)p[i].size()) || (k >= (int)p[j].size())) {
            //cout << i << j << k << endl;
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n, case_num;
    cin >> case_num;
    while (case_num--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            p[i].clear();
            cin >> p[i];
        }
        sort(p, p + n);
        if (is_ok(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}                                 
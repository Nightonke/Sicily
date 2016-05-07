// Problem#: 1142
// Submission#: 3289813
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

int s[30], num[30];
int N;

inline int minOpe() {
    int ope = 0;
    for (int i = 0; i < N - 1; i++) {
        ope += (s[i] - s[i + 1] > 1 || s[i + 1] - s[i] > 1);
    }
    return ope;
}

inline bool check() {
    for (int i = 0; i < N - 1; i++) {
        if (s[i] > s[i + 1]) return false;
    }
    return true;
}

bool dfs(int now) {
    if (now == 0) return check();
    if (now < minOpe()) return false;

    for (int i = 2; i <= N; i++) {
        reverse(s, s + i);
        if (dfs(now - 1)) return true;
        reverse(s, s + i);
    }
    return false;
}

bool cmp(const int & a, const int & b) {
    return num[a] < num[b];
}

int main() {

    std::ios::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        s[i] = i;
    }

    sort(s, s + N, cmp);

    int ans = minOpe();

    while (1) {
        if (dfs(ans++)) break;
    }

    cout << ans - 1 << endl;

    //cin >> N;

    return 0;
}                                 
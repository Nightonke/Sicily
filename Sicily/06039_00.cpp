// Problem#: 6039
// Submission#: 3376220
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

long long M[25];
long long N, m;
long long ans = 1000000005;

void dfs(int pos, long long sum) {
    if (pos == m) {
        if (sum >= N) ans = min(sum, ans);
        return;
    }
    if (sum >= ans) return;
    dfs(pos + 1, sum);
    dfs(pos + 1, sum + M[pos]);
}

int main() {

    std::ios::sync_with_stdio(false);

    cin >> N >> m;
    for (int i = 0; i < m; i++) cin >> M[i];
    dfs(0, 0);
    cout << ans << endl;

    return 0;
}                                 
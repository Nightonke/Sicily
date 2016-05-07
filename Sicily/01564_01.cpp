// Problem#: 1564
// Submission#: 3239937
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
#include <set>
using namespace std;

int put[50];
int N;
int ans;

void dfs(int pos, int sum, int last) {
    if (sum > N) return;
    if (sum == N) {
        ans++;
        return;
    }
    for (int i = last; i <= N - sum; i++) {
        put[pos] = i;
        dfs(pos + 1, sum + i, i);
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    cin >> N;
    dfs(0, 0, 5);
    cout << ans << endl;
        
    //getchar();
    //getchar();
    
    return 0;
}                                 
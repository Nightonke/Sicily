// Problem#: 1049
// Submission#: 3288301
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

int ans[1000005];

void make() {
    ans[0] = 1;
    ans[1] = 2;
    ans[2] = 7;
    for (int i = 3; i <= 1000000; i++) {
        ans[i] = (3 * ans[i - 1] + ans[i - 2] - ans[i - 3] + 10) % 10;
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    make();

    int N;
    cin >> N;

    while (N--) {
        int temp;
        cin >> temp;
        cout << ans[temp] << endl;
    }

    return 0;
}                                 
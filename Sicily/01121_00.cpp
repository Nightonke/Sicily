// Problem#: 1121
// Submission#: 3288659
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

int ans[31];

int main() {

    std::ios::sync_with_stdio(false);

    
    ans[0] = 1;
    ans[2] = 3;
    for (int i = 4; i <= 30; i += 2) {
        ans[i] = 3 * ans[i - 2];
        for (int j = i - 4; j >= 0; j -= 2) {
            ans[i] += 2 * ans[j];
        }
    }

    while (1) {
        int temp;
        cin >> temp;
        if (temp == -1) break;
        cout << ans[temp] << endl;
    }

    return 0;
}                                 
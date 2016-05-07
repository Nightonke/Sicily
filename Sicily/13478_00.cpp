// Problem#: 13478
// Submission#: 3516759
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

inline bool isOK(int n) {
    int n1, sum = 0;
    n1 = n;
    while (n1) {
        int temp = n1 % 10;
        sum += temp * temp * temp;
        n1 /= 10;
    }
    return sum == n;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    
    int n;
    vector<int> ans;
    for (int i = 100; i < 1000; i++) {
        if (isOK(i)) ans.push_back(i);
    }
    cin >> n;
    for (int i = 0; i < ans.size() && ans[i] <= n; i++) {
        cout << ans[i] << endl;
    }
    
    
    return 0;
}                                 
// Problem#: 13476
// Submission#: 3516803
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
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) sum += i;
            else sum += i + n / i;
        }
    }
    return sum == n;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) if (isOK(i)) cout << i << endl;
    
    return 0;
}                                 
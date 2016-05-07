// Problem#: 13290
// Submission#: 3519853
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int t['z' + 1];

int main() {
    
    std::ios::sync_with_stdio(false);
    
    bool isOK = true;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) t[s1[i]]++;
    for (int i = 0; i < s2.size(); i++) t[s2[i]]--;
    for (int i = 'a'; i <= 'z' && isOK; i++) if (t[i]) isOK = false;
    cout << (isOK ? "YES" : "NO") << endl;
    
    return 0;
}                                 
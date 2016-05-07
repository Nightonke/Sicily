// Problem#: 1278
// Submission#: 2777198
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    std::ios::sync_with_stdio(false);
    
    int case_num;
    cin >> case_num;
    
    while (case_num--) {
        int n;
        cin >> n;
        string s;
        while (n--) {
            string temp;
            cin >> temp;
            s += temp;
        }
        int i, pos, sum = 0;
        for (i = 0, pos = 0; i < (int)s.size(); i++) {
            if (s[i] == '<') {
                sum += i - pos;
                pos++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}                                 
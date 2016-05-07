// Problem#: 13460
// Submission#: 3684279
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < v.size(); i++) {
        string s = v[i];
        reverse(s.begin(), s.end());
        for (int j = 0; j < v.size(); j++) {
            if (s == v[j]) {
                cout << v[j].size() << " " << v[j][v[j].size() / 2] << endl;
                return 0;
            }
        }
    }
    
    return 0;
}                                 
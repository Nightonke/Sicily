// Problem#: 13980
// Submission#: 3681920
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, int> m;
    while (n--) {
        vector<string> v(3);
        for (int i = 0; i < 3; i++) cin >> v[i];
        sort(v.begin(), v.end());
        string s;
        for (int i = 0; i < 3; i++) s += v[i];
        map<string, int>::iterator iter = m.find(s);
        if (iter == m.end()) m[s] = 1;
        else iter->second++;
    }
    int ans = 0;
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > ans) ans = iter->second;
    }
    cout << ans << endl;

    return 0;
}                                 
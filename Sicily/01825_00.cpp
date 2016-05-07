// Problem#: 1825
// Submission#: 3161418
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1013
// Submission#: 3160682
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
using namespace std;

map<string, int> m;

int main() {

    std::ios::sync_with_stdio(false);
    
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        m.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) if ('A' <= s[j] && s[j] <= 'Z') s[j] += 32;
            if (m.find(s) == m.end()) m[s] = 1;
            else m[s]++;
        }
        for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) cout << iter->first << " " << iter->second << endl;
        cout << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
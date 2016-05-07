// Problem#: 14184
// Submission#: 3693422
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
int ans;
map<string, int> m;

int main() {

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s >> s;
            if (m.find(s) == m.end()) m[s] = 1;
            else m[s]++;
        }
        ans = 1;
        for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            ans *= iter->second + 1;
        }
        cout << ans - 1 << endl;
        m.clear();
    }

    return 0;
}                                 
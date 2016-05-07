// Problem#: 1486
// Submission#: 2755713
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <map>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

int main() {
    int control_blank = 0, n, m, i;
    std::ios::sync_with_stdio(false);
    while (cin >> n) {
        if (control_blank)
            cout << endl;
        control_blank = true;
        map<int, int> num;
        map<int, int> :: iterator numm;
        for (i = 0; i < n; i++) {
            cin >> m;
            numm = num.find(m);
            if (numm != num.end()) {
                (*numm).second++;
            } else {
                num.insert(pair<int, int> (m, 1));
            }
        }
        for (numm = num.begin(); numm != num.end(); numm++) {
            cout << (*numm).first << " " << (*numm).second << endl;
        }
    }
    return 0;
}                                 
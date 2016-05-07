// Problem#: 1021
// Submission#: 2735567
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stack>
using namespace std;

int couple_relation[200005];

int main() {
    int t1, t2, n, i;
    while (cin >> n && n) {
        stack<int> s;  //
        for (i = 0; i < n; i++) {
            cin >> t1 >> t2;
            couple_relation[t1] = t2;
            couple_relation[t2] = t1;
        }
        for (i = 1; i <= 2 * n; i++) {
            if (!s.empty() && couple_relation[i] == s.top())  //
                s.pop();
            else
                s.push(i);
        }
        if (s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}                                 
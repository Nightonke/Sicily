// Problem#: 1282
// Submission#: 3199464
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getNext(string pattern) {

    vector<int> next(pattern.size());
    next[0] = -1;

    for (int i = 0, j = -1; i + 1 < pattern.size(); ) {

        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            if (pattern[i] != pattern[j]) next[i] = j;
            else next[i] = next[j];
        } else {
            j = next[j];
        }

    }
    return next;
}

vector<int> KMP(string text, string pattern) {

    vector<int> position;

    if (text.empty() || pattern.empty()) return position;

    vector<int> next = getNext(pattern);
    int pos, i, j;
    pos = i = j = 0;

    while (i < text.size() && j < pattern.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == pattern.size()) {
                j = 0;
                position.push_back(pos);
                pos = i;
            }
        } else {
            pos += j - next[j];
            if (next[j] != -1) {
                j = next[j];
            } else {
                j = 0;
                i++;
            }
        }
    }
    return position;
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        string t, p;
        int tn, pn;
        cin >> pn;
        if (cin.eof()) break;
        for (int i = 0; i < pn; i++) {
            int c;
            cin >> c;
            p += c;
        }
        cin >> tn;
        for (int i = 0; i < tn; i++) {
            int c;
            cin >> c;
            t += c;
        }
        vector<int> ans = KMP(t, p);
        if (ans.empty()) {
            cout << "no solution" << endl;
        } else {
            cout << ans[0] << endl;
        }
    }






    return 0;
}                                 
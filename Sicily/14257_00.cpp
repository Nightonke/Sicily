// Problem#: 14257
// Submission#: 3709477
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string T;

bool OnlyLD(char C) { return (('0' <= C && C <= '9') || ('A' <= C && C <= 'Z') || ('a' <= C && C <= 'z')); }

void Part(int st, int ed) {

    string name, id, classes;
    int p = st;
    
    while (p <= ed) {
        if (OnlyLD(T[p])) {
            int sp = p;
            for (; p < ed && OnlyLD(T[p]); p++);
            name = T.substr(sp, p - sp);
            cout << (name.size() > 0 ? "<" : "") + name;
        }
        if (T[p] == '(') {
            int sp = ++p, count = 1;
            for (; p < ed; p++) {
                if (T[p] == ')') count--;
                if (T[p] == '(') count++;
                if (count == 0) break;
            }
            Part(sp, min(p, ed));
            p++;
        }
        if (T[p] == '.') {
            int sp = ++p;
            for (; p < ed && OnlyLD(T[p]); p++);
            classes += (classes.size() > 0 ? " " : "") +  T.substr(sp, p - sp);
        }
        if (T[p] == '#') {
            int sp = ++p;
            for (; p < ed && OnlyLD(T[p]); p++);
            id = T.substr(sp, p - sp);
        }
        if (p == ed || T[p] == '>') {
            if (id.size() > 0) cout << " id=\"" + id + "\"";
            if (classes.size() > 0) cout << " class=\"" + classes + "\"";
            cout << (name.size() > 0 ? ">" : "");

            if (T[p] == '>') Part(p + 1, min((int)T.size(), ed));

            break;
        }
    }

    cout << (name.size() > 0 ? "</" : "") + name + (name.size() > 0 ? ">" : "");
}

int main() {

    std::ios::sync_with_stdio(false);

    int CaseNum;
    cin >> CaseNum;
    getline(cin, T);
    while (CaseNum--) {
        getline(cin, T);
        Part(0, T.size());
        cout << endl;
    }
    return 0;
}                                 
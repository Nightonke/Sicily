// Problem#: 1161
// Submission#: 3381425
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <math.h>
using namespace std;

const int MAX_N = 65550;

struct song {
    int id, l;
    double f;
    double c;
};

song s[MAX_N];

inline bool cmp(const song & s1, const song & s2) {
    return s1.c < s2.c;
}

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {
        int N;
        cin >> N;
        if (cin.eof()) break;
        for (int i = 0; i < N; i++) {
            cin >> s[i].id >> s[i].l >> s[i].f;
            s[i].c = s[i].l / s[i].f;
        }
        sort(s, s + N, cmp);
        int pos;
        cin >> pos;
        cout << s[pos - 1].id << endl;
    }

    return 0;
}                                 
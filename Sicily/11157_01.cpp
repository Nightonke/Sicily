// Problem#: 11157
// Submission#: 3016168
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
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    int u, l, r, d;

    cin >> u >> l >> r >> d;

    vector<vector<char> > b(n + u + d);
    for (int i = 0; i < b.size(); i++) {

        vector<char> line(m + l + r);
        b[i] = line;

    }

    for (int i = 0; i < b.size(); i++) {

        for (int j = 0; j < b[i].size(); j++) {

            if ((i + j) % 2) b[i][j] = '.';
            else b[i][j] = '#';

        }

    }

    for (int i = 0; i < n; i++) {

        string s;

        cin >> s;

        for (int j = 0; j < s.size(); j++) {

            b[u + i][l + j] = s[j];

        }


    }

    for (int i = 0; i < b.size(); i++) {

        for (int j = 0; j < b[i].size(); j++) {

            cout << b[i][j];

        }

        cout << endl;


    }

    //getchar();
    //getchar();
    return 0;
}                                 
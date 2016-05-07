// Problem#: 1064
// Submission#: 3228142
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

#define MAX 3005

void findExpression(string & s, int st, int ed) {

    if (st >= ed) return;

    string * sub = new string[ed - st];
    int counter = 0;
    int num = 0;
    int pos = st;
    for (int i = st; i <= ed; i++) {
        if (s[i] == '1') counter++;
        else counter--;
        if (counter == 0) {
            sub[num++] = s.substr(pos, i - pos + 1);
            pos = i + 1;
        }
    }
    for (int i = 0; i < num; i++) {
        findExpression(sub[i], 1, sub[i].size() - 2);
    }
    sort(sub, sub + num);
    for (int i = 0, k = st; i < num; i++) {
        int length = sub[i].size();
        for (int j = 0; j < length; j++) {
            s[k++] = sub[i][j];
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        string a, b;
        cin >> a >> b;
        findExpression(a, 0, a.size() - 1);
        findExpression(b, 0, b.size() - 1);
        if (a == b) cout << "same" << endl;
        else cout << "different" << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
// Problem#: 1525
// Submission#: 3454278
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
#include <list>
using namespace std;

string s;

int dfs(int st, int en) {
    if (st >= en) return 2;
    int counter = 0, newSt;
    for (int i = st; i <= en; i++) {
        if (s[i] == '[') counter++;
        else counter--;
        if (counter == 0) {
            newSt = i + 1;
            break;
        }
    }
    int l1 = newSt - st, l2 = en - newSt + 1;
    if (l1 > l2) return 2 * dfs(st + 1, newSt - 2);
    else return 2 * dfs(newSt + 1, en - 1);
}

string delBlank(string in) {
    string re;
    int s = in.size();
    for (int i = 0; i < s; i++) if (in[i] != ' ') re.push_back(in[i]);
    return re;
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;
    getline(cin, s);
    int counter = 1;

    while (caseNum--) {
        getline(cin, s);
        s = delBlank(s);
        if (s.size() == 0) cout << counter++ << " " << 1 << endl;
        else cout << counter++ << " " << dfs(1, s.size() - 2) << endl;
    }

    return 0;
}                                 
// Problem#: 1515
// Submission#: 3316797
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

struct step {
    string way;
    string num;
    step() {}
    step(string w, string n) {
        way = w;
        num = n;
    }
};

string S[40325];
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool exist[40325];

inline int KT(string s) {
    int i, j, t, sum;
    sum = 0;
    for (int i = 0; i < s.size(); i++) {
        t = 0;
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] < s[i]) t++;
        }
        sum += t * fac[s.size() - i - 1];
    }
    return sum;
}

void BFS() {

    queue<step> q;
    q.push(step("", "12345678"));
    int pos = KT("12345678");
    exist[pos] = true;
    S[pos] = "";

    while (!q.empty()) {

        step temp = q.front();
        q.pop();

        string tempa, tempb, tempc;
        tempa = tempb = tempc = temp.num;

        // a reverse
        swap(tempa[0], tempa[2]);
        swap(tempa[1], tempa[3]);
        swap(tempa[4], tempa[6]);
        swap(tempa[5], tempa[7]);

        // b reverse
        char tempChar = tempb[0];
        tempb[0] = tempb[1];
        tempb[1] = tempb[2];
        tempb[2] = tempb[3];
        tempb[3] = tempChar;
        tempChar = tempb[4];
        tempb[4] = tempb[5];
        tempb[5] = tempb[6];
        tempb[6] = tempb[7];
        tempb[7] = tempChar;

        //c reverse
        tempChar = tempc[1];
        tempc[1] = tempc[2];
        tempc[2] = tempc[6];
        tempc[6] = tempc[5];
        tempc[5] = tempChar;

        int pos = KT(tempa);
        if (!exist[pos]) {
            exist[pos] = true;
            S[pos] = temp.way + "A";
            q.push(step(temp.way + "A", tempa));
        }
        pos = KT(tempb);
        if (!exist[pos]) {
            exist[pos] = true;
            S[pos] = temp.way + "B";
            q.push(step(temp.way + "B", tempb));
        }
        pos = KT(tempc);
        if (!exist[pos]) {
            exist[pos] = true;
            S[pos] = temp.way + "C";
            q.push(step(temp.way + "C", tempc));
        }
    }
}

int main() {

    BFS();

    std::ios::sync_with_stdio(false);

    while (1) {
        int n;
        cin >> n;
        if (n == -1) break;
        string s;
        s.resize(8);
        for (int i = 0; i < 8; i++) {
            cin >> s[i];
        }
        int pos = KT(s);
        if (S[pos].size() > n) cout << -1 << endl;
        else {
            cout << S[pos].size() << "  " << S[pos] << endl;
        }
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
// Problem#: 1729
// Submission#: 3325430
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

vector<int> v;
string temp;
char t[33] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ',-.?";

void cal() {
    int s = temp.size();
    for (int i = 0; i < s; ) {
        if (temp[i] == ' ') {
            int counter = 1, j;
            for (j = i + 1; j < s && temp[j] == ' '; j++) counter++;
            v.push_back((counter + 1) % 2);
            i = j;
        } else i++;
    }
}

void solve() {
    int s = (v.size() / 5 + (v.size() % 5 ? 1 : 0)) * 5;
    int os = v.size();
    for (int i = os; i < s; i++) v.push_back(0);
    vector<int> text;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i % 5 == 0) sum = 0;
        sum = sum * 2 + v[i];
        if ((i + 1) % 5 == 0) cout << t[sum];
    }
    cout << endl;
    v.clear();
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        getline(cin, temp);
        if (temp == "*") solve();
        else if (temp == "#") break;
        else cal();
    }

    

    //getchar();
    //getchar();
    
    return 0;
}                                 
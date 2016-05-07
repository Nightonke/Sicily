// Problem#: 1082
// Submission#: 3403497
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

const int MAX = 10005;

int main() {

    std::ios::sync_with_stdio(false);

    bool firstTime = true;

    while (1) {
        int M, N, counter = 1, p = 1;
        list<int> l;
        bool display[MAX];
        memset(display, false, sizeof(display));
        cin >> M;
        if (cin.eof()) break;
        if (!firstTime) cout << endl;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            display[temp] = true;
        }
        while (1) {
            char op;
            cin >> op;
            if (op == 'a') {
                int temp;
                cin >> temp;
                l.push_back(temp);
            }
            if (op == 'r') {
                if (l.empty()) {
                    cout << -1 << endl;
                    continue;
                }
                if (p == 1) {
                    list<int>::iterator iter = l.begin();
                    int Min = *iter;
                    list<int>::iterator pos = iter;
                    for (; iter != l.end(); iter++) {
                        if (*iter < Min) {
                            Min = *iter;
                            pos = iter;
                        }
                    }
                    l.erase(pos);
                    if (display[counter]) cout << Min << endl;
                } else {
                    list<int>::iterator iter = l.begin();
                    int Max = *iter;
                    list<int>::iterator pos = iter;
                    for (; iter != l.end(); iter++) {
                        if (*iter > Max) {
                            Max = *iter;
                            pos = iter;
                        }
                    }
                    l.erase(pos);
                    if (display[counter]) cout << Max << endl;
                }
                counter++;
            }
            if (op == 'p') {
                int temp;
                cin >> temp;
                p = temp;
            }
            if (op == 'e') break;
        }
        firstTime = false;
    }

    return 0;
}                                 
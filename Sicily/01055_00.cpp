// Problem#: 1055
// Submission#: 3458456
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
#include <set>
using namespace std;

string ex1, ex2, S;
int times[11] = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int val[11];

inline int prior(char op) {
    if (op == '|') return 1;
    if (op == '^') return 2;
    if (op == '&') return 3;
    if (op == '~') return 4;
    else return 0;
}

string delBlank(string in) {
    string re;
    int s = in.size();
    for (int i = 0; i < s; i++) if (in[i] != ' ') re.push_back(in[i]);
    return re;
}

string delContinuesCon(string in) {
    string re;
    int s = in.size();
    for (int i = 0; i < s; ) {
        if (i < s - 1 && in[i] == '~' && in[i + 1] == '~') {
            i += 2;
        } else {
            re.push_back(in[i]);
            i++;
        }
    }
    return re;
}

string transIn2Post(string in) {
    stack<char> op;
    string post;
    int s = in.size();
    for (int i = 0; i < s; i++) {
        char c = in[i];
        if ('a' <= c && c <= 'z') {
            post.push_back(c);
        } else {
            if (c == '(') {
                op.push('(');
            } else {
                if (c == ')') {
                    while (op.top() != '(') {
                        post.push_back(op.top());
                        op.pop();
                    }
                    op.pop();
                } else {
                    if (op.empty()) {
                        op.push(c);
                    } else {
                        if (prior(c) > prior(op.top())) {
                            op.push(c);
                        } else {
                            while (!op.empty() && prior(c) <= prior(op.top())) {
                                post.push_back(op.top());
                                op.pop();
                            }
                            op.push(c);
                        }
                    }
                }
            }
        }
    }
    while (!op.empty()) {
        post.push_back(op.top());
        op.pop();
    }
    return post;
}

int calFromPost(string in) {
    stack<int> ans;
    int s = in.size();
    for (int i = 0; i < s; i++) {
        int x, y;
        if ('a' <= in[i] && in[i] <= 'z') {
            ans.push(val[in[i] - 'a']);
        } else {
            if (in[i] != '~') {
                y = ans.top();
                ans.pop();
                x = ans.top();
                ans.pop();
                if (in[i] == '|') ans.push(x | y);
                if (in[i] == '^') ans.push(x ^ y);
                if (in[i] == '&') ans.push(x & y);
            } else {
                y = ans.top();
                ans.pop();
                ans.push(!y);
            }
        }
    }
    return ans.top();
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;
    getline(cin, S);
    int counter = 1;

    while (caseNum--) {
        getline(cin, S);
        S = delBlank(S);
        S = delContinuesCon(S);
        int s = S.size();
        int varNum = 0;
        bool var[26] = {false};
        for (int i = 0; i < s; i++) {
            if ('a' <= S[i] && S[i] <= 'z' && !var[S[i] - 'a']) {
                var[S[i] - 'a'] = true;
                varNum++;
            }
        }
        char takePlace = 'a';
        for (int i = 0; i < 26; i++) {
            if (var[i]) {
                for (int j = 0; j < s; j++) {
                    if (S[j] == i + 'a') S[j] = takePlace;
                }
                takePlace++;
            }
        }
        int t = times[varNum];
        bool found = false;
        for (int i = 1; i < s; i++) {
            if ((('a' <= S[i - 1] && S[i - 1] <= 'z') || S[i - 1] == ')') && (('a' <= S[i] && S[i] <= 'z') || S[i] == '~' || S[i] == '(')) {
                ex1 = S.substr(0, i);
                ex2 = S.substr(i, s - i + 1);
                int correctTimes = 0;
                string p1 = transIn2Post(ex1);
                string p2 = transIn2Post(ex2);
                for (int j = 0; j < t; j++) {
                    int temp = j;
                    for (int k = 0; k < varNum; k++) {
                        val[k] = temp % 2;
                        temp /= 2;
                    }
                    int ans1 = calFromPost(p1);
                    int ans2 = calFromPost(p2);
                    if (ans1 == ans2) correctTimes++;
                    else break;
                }
                if (correctTimes == t) {
                    found = true;
                    break;
                }
            }
        }
        cout << "Data set " << counter << ": " << (found ? "Equivalent" : "Different") << endl;
        counter++;
    }

    return 0;
}                                 
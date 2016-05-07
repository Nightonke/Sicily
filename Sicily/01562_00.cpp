// Problem#: 1562
// Submission#: 3259218
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int N;
    string order[1005];
    int num[1005];
    stack<int> s;
    int re = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> order[i];
        if (order[i] == "PUSH" || order[i] == "IFZERO") cin >> num[i];
    }

    int step = 0;
    while (1) {
        if (order[step] == "PUSH") s.push(num[step]);
        else if (order[step] == "STORE") {
            re = s.top();
            s.pop();
        }
        else if (order[step] == "LOAD") s.push(re);
        else if (order[step] == "PLUS") {
            int temp = s.top();
            s.pop();
            s.top() += temp;
        }
        else if (order[step] == "TIMES") {
            int temp = s.top();
            s.pop();
            s.top() *= temp;
        }
        else if (order[step] == "IFZERO") {
            if (s.top() == 0) {
                s.pop();
                step = num[step];
                continue;
            }
            s.pop();
        }
        else if (order[step] == "DONE") {
            cout << s.top() << endl;
            break;
        }
        step++;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
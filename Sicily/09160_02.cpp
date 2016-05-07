// Problem#: 9160
// Submission#: 2811154
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int counter = 0, n;
    cin >> n;
    char temp[100001];
    while (n--) {
        stack<char> s;
        cin >> temp;
        for (int i = 0; temp[i] != '\0'; i++) {
            if (s.empty()) {
                s.push(temp[i]);
            } else {
                if (temp[i] == s.top()) {
                    s.pop();
                } else {
                    s.push(temp[i]);
                }
            }
        }
        if (s.empty()) {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}                                 
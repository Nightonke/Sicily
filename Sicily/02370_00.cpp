// Problem#: 2370
// Submission#: 3375194
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

string text;
string ans;
char h[17] = "0123456789ABCDEF";
string alone;
int aloneNum;

void checkAlone() {
    if (alone != "") {
        int shang = aloneNum / 128;
        int yu = aloneNum % 128;
        int k = 0;
        while (shang--) {
            ans += "7F";
            for (int k = 0; k < 128 * 2; k++) {
                ans.push_back(alone[k]);
            }
            alone = alone.substr(2 * 128, alone.size() - 2 * 128);
        }
        if (yu) {
            yu--;
            char c2 = h[yu % 16];
            yu /= 16;
            char c1 = h[yu % 16];
            ans.push_back(c1);
            ans.push_back(c2);
            ans += alone;
        }
        aloneNum = 0;
        alone = "";
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int counter, N;
        cin >> counter >> N;
        N *= 2;
        for (int i = 0; i < N / 80 + (N % 80 ? 1 : 0); i++) {
            string temp;
            cin >> temp;
            text += temp;
        }
        int s = text.size();
        ans = "";
        for (int i = 0; i < s; ) {
            int j, num = 1;
            for (j = i + 2; j < s && text[j] == text[j - 2] && text[j + 1] == text[j - 1]; j += 2) {
                num++;
            }
            if (num == 1) {
                aloneNum++;
                alone += text.substr(i, 2);
            } else if (num == 2) {
                aloneNum += 2;
                alone += text.substr(i, 2) + text.substr(i, 2);
            } else {
                checkAlone();
                int shang = num / 130;
                int yu = num % 130;
                while (shang--) {
                    ans += "FF" + text.substr(i, 2);
                }
                if (yu) {
                    if (yu < 3) {
                        aloneNum += yu;
                        while (yu--) alone += text.substr(i, 2);
                    } else {
                        yu -= 3;
                        char c2 = h[yu % 16];
                        yu /= 16;
                        yu += 8;
                        char c1 = h[yu % 16];
                        ans.push_back(c1);
                        ans.push_back(c2);
                        ans += text.substr(i, 2);
                    }
                }
            }
            i = j;
        }
        checkAlone();
        cout << counter << " " << ans.size() / 2 << endl;
        for (int i = 0, j = 0; i < ans.size(); i++) {
            cout << ans[i];
            j++;
            if (j == 80) {
                cout << endl;
                j = 0;
            }
        }
        if (ans.size() % 80) cout << endl;
        text.clear();
        ans.clear();
    }

    return 0;
}                                 
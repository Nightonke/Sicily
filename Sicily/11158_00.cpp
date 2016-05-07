// Problem#: 11158
// Submission#: 3023001
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

#define MAX_N 1005

string num[MAX_N];



string tenandunitPos(int i) {

    vector<string> one2nineteen(20);

    one2nineteen[0] = "";
    one2nineteen[1] = "one";
    one2nineteen[2] = "two";
    one2nineteen[3] = "three";
    one2nineteen[4] = "four";
    one2nineteen[5] = "five";
    one2nineteen[6] = "six";
    one2nineteen[7] = "seven";
    one2nineteen[8] = "eight";
    one2nineteen[9] = "nine";
    one2nineteen[10] = "ten";
    one2nineteen[11] = "eleven";
    one2nineteen[12] = "twelve";
    one2nineteen[13] = "thirteen";
    one2nineteen[14] = "fourteen";
    one2nineteen[15] = "fifteen";
    one2nineteen[16] = "sixteen";
    one2nineteen[17] = "seventeen";
    one2nineteen[18] = "eighteen";
    one2nineteen[19] = "nineteen";

    vector<string> ten(10);

    ten[0] = "twenty";
    ten[1] = "thirty";
    ten[2] = "forty";
    ten[3] = "fifty";
    ten[4] = "sixty";
    ten[5] = "seventy";
    ten[6] = "eighty";
    ten[7] = "ninety";

    i = i % 100;

    if (i == 0) return "";

    if (i < 20) {

        return one2nineteen[(i)];

    } else {

        return ten[i / 10 - 2] + one2nineteen[i % 10];

    }

}

string hundredPos(int i) {

    i = i / 100;

    if (i == 0) return "";

    return tenandunitPos(i) + "hundred";

}

void makeNum() {

    for (int i = 0; i < MAX_N; i++) {

        num[i] = hundredPos(i) + tenandunitPos(i);

    }

}

int main() {

    std::ios::sync_with_stdio(false);

    makeNum();

    int n;

    cin >> n;
    
    vector<string> s(n + 5);

    int now = 0;

    for (int i = 0; i < n; i++) {

        cin >> s[i];

        if (s[i][0] != '$') now += s[i].size();

    }

    for (int i = now + 1; i < now + 100 && i < 1000; i++) {

        if (now + num[i].size() == i) {

            for (int j = 0; j < n; j++) {

                if (s[j] != "$") {

                    cout << s[j] << " ";

                } else {

                    cout << num[i] << " ";

                }

            }

            cout << endl;

            break;

        }


    }

    //getchar();
    //getchar();
    return 0;
}                                 
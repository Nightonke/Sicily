// Problem#: 13059
// Submission#: 3411778
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

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        int pages[25], p = 0;
        while (1) {
            int temp;
            cin >> temp;
            if (temp == 0) break;
            else pages[p++] = temp;
        }
        if (p == 0) break;
        bool first = true;
        for (int i = 0, j; i < p;) {
            j = i + 1;
            if (i < p - 1 && pages[i] + 1 == pages[i + 1]) {
                while (j < p && pages[j] == pages[j - 1] + 1) j++;
                if (!first) cout << ",";
                cout << pages[i] << "-" << pages[j - 1];
                first = false;
            } else {
                if (!first) cout << ",";
                cout << pages[i];
                first = false;
            }
            i = j;
        }
        cout << endl;
    }

    return 0;
}                                 
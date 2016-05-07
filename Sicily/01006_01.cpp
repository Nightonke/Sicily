// Problem#: 1006
// Submission#: 2736815
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//next_permutation()全排列的下一个
//prev_permutation()全排列的前一个，括号中都为数组的起始结束位置的指针

int main() {
    int n, len, i, j, k, min, difference, pos[100];
    string ranking[105], ans;
    char possible[100];
    while (cin >> n && n) {
        for (i = 0; i < n; i++) {
            cin >> ranking[i];
        }
        len = ranking[0].length();
        for (i = 0; i < len; i++) {
            possible[i] = 'A' + i;
        }
        min = 999999;
        while (1) {
            for (i = 0; i < len; i++) {
                pos[possible[i] - 'A'] = i;
            }
            for (i = 0, difference = 0; i < n; i++) {
                for (j = 0; j < len; j++) {
                    for (k = j + 1; k < len; k++) {
                        if (pos[ranking[i][j] - 'A'] > pos[ranking[i][k] - 'A']) {
                            difference++;
                        }
                    }
                }
            }
            if (difference < min) {
                min = difference;
                ans = possible;
            }
            if (!next_permutation(possible, possible + len)) {
                break;
            }
        }
        cout << ans <<  " is the median ranking with value " << min << "." << endl;
    }
    return 0;
}                                 
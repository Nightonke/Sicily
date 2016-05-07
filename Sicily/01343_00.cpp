// Problem#: 1343
// Submission#: 3300282
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

int main() {

    std::cout.sync_with_stdio(false);

    while (1) {
        int s, t, w;
        string first;
        bool used[26];
        cin >> s >> t >> w >> first;
        if (cin.eof()) break;
        bool isEnd = false;
        int counter = 0;
        
        while (!isEnd && counter < 5) {

            memset(used, false, sizeof(used));
            for (int i = 0; i < first.size(); i++) used[first[i] - 'a'] = true;

            bool oneOK = true;

            for (int j = first.size() - 1; j >= 0 && oneOK; j--) {

                for (int k = 1; 1; k++) {
                    char now = first[j];
                    if (now + k <= 'a' + t - 1 && used[now + k - 'a'] == false) {
                        first[j] = now + k;
                        memset(used, false, sizeof(used));
                        for (int p = 0; p <= j; p++) used[first[p] - 'a'] = true;
                        for (int p = j + 1; p < first.size(); p++) {
                            for (char q = now + k + 1; q <= t + 'a'; q++) {
                                if (!used[q - 'a']) {
                                    used[q - 'a'] = true;
                                    first[p] = q;
                                    break;
                                }
                            }
                        }
                        cout << first << endl;
                        counter++;
                        oneOK = false;
                        break;
                    } else if (now + k > 'a' + t - 1) {
                        if (j == 0) isEnd = true;
                        break;
                    }

                }

            }

        }

    }

    return 0;
}                                 
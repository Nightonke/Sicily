// Problem#: 1356
// Submission#: 3383221
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

const int MAX_N = 10005;

int num[MAX_N];
int N;
int M;

int main() {

    //std::ios::sync_with_stdio(false);

    bool firstTime = true;

    while (1) {
        cin >> N;
        if (!N) break;

        if (!firstTime) cout << endl;

        for (int i = 0; i < N; i++) cin >> num[i];
        sort(num, num + N);
        
        int last = -1;
        int ans = 0;
        int counter = 0;
        for (int i = 0; i < N; i++) {
            if (num[i] == last) {
                counter++;
            } else {
                last = num[i];
                ans = max(ans, counter);
                counter = 1;
            }
        }
        ans = max(ans, counter);

        cout << ans << endl;
        for (int i = 0; i < ans; i++) {
            cout << num[i];
            for (int j = i + ans; j < N; j += ans) cout << " " << num[j];
            cout << endl;
        }

        firstTime = false;

    }

    return 0;
}                                 
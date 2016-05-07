// Problem#: 1448
// Submission#: 3391238
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1448
// Submission#: 3390774
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

const int MAX_N = 30005;

int n[MAX_N];
int N;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        
        cin >> N;
        for (int i = 0; i < N; i++) cin >> n[i];

        int ans = 1;
        int i;

        for (i = 0; i < N - 1;) {
            for (; i < N - 1; i++) {
                if (n[i] > n[i + 1]) {
                    ans++;
                    break;
                }
            }
            i++;
            for (; i < N - 1; i++) {
                if (n[i] < n[i + 1]) {
                    ans++;
                    break;
                }
            }
            i++;
        }

        cout << ans << endl;

    }

    return 0;
}                                 
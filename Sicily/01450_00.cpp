// Problem#: 1450
// Submission#: 3311929
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
#include <queue>
#include <set>
#include <iomanip>
using namespace std;

int r[15];
int f[15];
int R, F;
double d[150];

int main() {

    std::cout.sync_with_stdio(false);

    string temp;

    while (1) {
        cin >> F;
        if (F == 0) break;
        cin >> R;
        for (int i = 0; i < F; i++) cin >> f[i];
        for (int i = 0; i < R; i++) cin >> r[i];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < F; j++) {
                d[i * F + j] = r[i] * 1.0 / f[j];
            }
        }
        sort(d, d + R * F);
        double ans = -1;
        for (int i = 1; i < R * F; i++) 
            if (d[i] != d[i - 1]) ans = max(ans, d[i] / d[i - 1]);
        cout << fixed << setprecision(2) << ans << endl;
    }


    return 0;
}                                 
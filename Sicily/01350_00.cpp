// Problem#: 1350
// Submission#: 3304925
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1350
// Submission#: 3304217
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

const int MAX_N = 1000005;

int bank[MAX_N];
int vis[MAX_N];
int N;

int main() {

    std::cout.sync_with_stdio(false);

    while (1) {
        cin >> N;
        if (cin.eof()) break;
        for (int i = 1; i <= N; i++) vis[i] = 0;
        for (int key = 1; key <= N; key++) {
            cin >> bank[key];
        }
        int ans = 0;
        int color = 1;
        for (int i = 1; i <= N; i++) {
            if (vis[i]) continue;
            color++;
            int now = i;
            while (!vis[now]) {
                vis[now] = color;
                now = bank[now];
                if (vis[now] == color) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}                                 
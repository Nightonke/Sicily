// Problem#: 1346
// Submission#: 3302026
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

const int MAX_N = 32050;
const int MAX_M = 65;

int n, m;
int v[MAX_M], p[MAX_M], q[MAX_M], w[MAX_M];
int s[MAX_M][3];
int s_ind[MAX_M];
int f[MAX_M][MAX_N / 10];
int F[MAX_N / 10];

int main() {

    std::cout.sync_with_stdio(false);

    while (1) {

        cin >> n >> m;
        if (cin.eof()) break;
        n /= 10;
        memset(s_ind, 0, sizeof(s_ind));
        memset(F, 0, sizeof(F));
        for (int i = 1; i <= m; i++) {
            cin >> v[i] >> p[i] >> q[i];
            v[i] /= 10;
            w[i] = v[i] * p[i];
            if (q[i]) s[q[i]][s_ind[q[i]]++] = i;
        }

        for (int i = 1; i <= m; i++) {
            if (q[i]) continue;
            memset(f[i], 0, sizeof(f[i]));
            for (int j = 0; j < s_ind[i]; j++) {
                int cur_son = s[i][j];
                for (int k = n - v[i]; k >= v[cur_son]; k--) f[i][k] = max(f[i][k], f[i][k - v[cur_son]] + w[cur_son]);
            }
            for (int j = n; j >= v[i]; j--) 
                for (int k = j; k >= v[i]; k--) F[j] = max(F[j], F[j - k] + w[i] + f[i][k - v[i]]);
        }
        cout << 10 * F[n] << endl;

    }

    return 0;
}                                 
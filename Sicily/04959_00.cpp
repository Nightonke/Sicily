// Problem#: 4959
// Submission#: 3372676
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

int N;
vector<pair<string, string> > S;
string K;

void getK(int L) {
    K.push_back('A' + S[0].second[L - 1] - S[0].first[L - 1] + (S[0].second[L - 1] < S[0].first[L - 1] ? 26 : 0));
}

bool test(int n) {
    string P = S[n].first, C = S[n].second, k = K, c;
    c.resize(C.size());
    for (int i = 0, j = 0; i < P.size(); i++) {
        c[i] = (P[i] - 'A' + k[j] - 'A') % 26 + 'A';
        k[j] = c[i];
        if (c[i] != C[i]) return false;
        j = (j + 1) % K.size();
    }
    return true;
}

bool testK() {
    for (int i = 0; i < N; i++) {
        if (!test(i)) return false;
    }
    return true;
}

bool cmp(const pair<string, string> & p1, const pair<string, string> & p2) {
    return p1.first.size() > p2.first.size();
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        
        K.clear();
        cin >> N;
        if (!N) break;
        S.resize(N);
        for (int i = 0; i < N; i++) cin >> S[i].first >> S[i].second;
        sort(S.begin(), S.end(), cmp);
        int L = 1, maxL = S[0].first.size();
        bool success = false;
        while (L <= maxL) {

            getK(L);
            if (testK()) {
                success = true;
                break;
            } else L++;

        }
        cout << (success ? K : "Impossible") << endl;

    }

    return 0;
}                                 
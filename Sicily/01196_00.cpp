// Problem#: 1196
// Submission#: 3291486
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
using namespace std;

const int MAX_N = 205;

short G[MAX_N][MAX_N];
map<string, int> M;
vector<pair<int, int> > unEqual;
int N;
int counter = 0;
void solve() {
    bool ok = true;

    for (int i = 0; i < N; i++) G[i][i] |= 1;  // !!!
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] && G[k][j]) G[i][j] |= 1;
            }
        }
    }
    for (int i = 0; i < N && ok; i++) {
        for (int j = 0; j < N; j++) {
            if ((G[i][j] & 2) && G[j][i]) {
                ok = false;
                break;
            }
        }
    }
    int s = unEqual.size();
    for (int i = 0; i < s; i++) {
        if ((G[unEqual[i].first][unEqual[i].second] & 1) && (G[unEqual[i].second][unEqual[i].first] & 1)) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Case" << counter << ": YES" << endl;
    else  cout << "Case" << counter << ": NO" << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    bool firstTime = true;
    string text;

    while (1) {
        getline(cin, text);
        if (!firstTime && (cin.eof() || text[text.size() - 1] == ':')) {
            if (!firstTime) {
                counter++;
                solve();
                if (cin.eof()) break;
                memset(G, 0, sizeof(G));
                M.clear();
                unEqual.clear();
                N = 0;
            }
        } else if (text[text.size() - 1] != ':') {
            string v1, v2, rela;
            int s = text.size();
            int lastBlankPos = -1;
            for (int i = 0; i < s; i++) {
                if (text[i] == ' ') {
                    if (v1 == "") {
                        v1 = text.substr(0, i);
                        lastBlankPos = i;
                        continue;
                    }
                    if (rela == "") {
                        rela = text.substr(lastBlankPos + 1, i - lastBlankPos - 1);
                        lastBlankPos = i;
                    }
                }
            }
            v2 = text.substr(lastBlankPos + 1, s - lastBlankPos - 1);

            if (M.find(v1) == M.end()) M.insert(make_pair(v1, N++));
            if (M.find(v2) == M.end()) M.insert(make_pair(v2, N++));
            int n1 = M[v1], n2 = M[v2];

            if (rela == "<") G[n1][n2] = 2;
            if (rela == "<=") G[n1][n2] = 1;
            if (rela == "=") G[n1][n2] = G[n2][n1] = 1;
            if (rela == "!=") unEqual.push_back(make_pair(n1, n2));
            if (rela == ">") G[n2][n1] = 2;
            if (rela == ">=") G[n2][n1] = 1;
            if (firstTime) firstTime = false;
        }

    }

    //cin >> N;

    return 0;
}                                 
// Problem#: 1008
// Submission#: 3153591
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

#define MAX_N 30

struct Node {
    string s;
    int match;
    int inDegree;
    int outDegree;
    Node() {}
    Node(string sIn, int m = -1, int i = 0, int o = 0) {
        s = sIn;
        match = m;
        inDegree = i;
        outDegree = o;
    }
};

Node N1[MAX_N], N2[MAX_N];
bool G1[MAX_N][MAX_N], G2[MAX_N][MAX_N];
int n, n1, n2;
map<string, int> M1, M2;
bool succeed;

void makeG() {

    M1.clear();
    M2.clear();
    n1 = n2 = 0;
    memset(G1, false, sizeof(G1));
    memset(G2, false, sizeof(G2));

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (M1.find(s1) == M1.end()) {
            M1[s1] = n1;
            N1[n1] = Node(s1, -1, 0, 1);
            n1++;
        } else {
            N1[M1[s1]].outDegree++;
        }
        if (M1.find(s2) == M1.end()) {
            M1[s2] = n1;
            N1[n1] = Node(s2, -1, 1, 0);
            n1++;
        } else {
            N1[M1[s2]].inDegree++;
        }
        G1[M1[s1]][M1[s2]] = true;
    }

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (M2.find(s1) == M2.end()) {
            M2[s1] = n2;
            N2[n2] = Node(s1, -1, 0, 1);
            n2++;
        } else {
            N2[M2[s1]].outDegree++;
        }
        if (M2.find(s2) == M2.end()) {
            M2[s2] = n2;
            N2[n2] = Node(s2, -1, 1, 0);
            n2++;
        } else {
            N2[M2[s2]].inDegree++;
        }
        G2[M2[s1]][M2[s2]] = true;
    }
}

void cut() {
    for (int j, i = 0, k; i < n1; i++) {
        int sameDegreeNum = 0;
        for (j = 0; j < n2; j++) {
            if (N1[i].inDegree == N2[j].inDegree && N1[i].outDegree == N2[j].outDegree) {
                k = j;
                sameDegreeNum++;
            }
        }
        if (sameDegreeNum == 1) {
            N1[i].match = k;
            N2[k].match = i;
        }
    }
}

void DFS(int pos) {
    if (pos == n1) {
        succeed = true;
        return;
    }
    if (N1[pos].match != -1) {
        DFS(pos + 1);
        return;
    }
    for (int i = 0; i < n2; i++) {
        if (N2[i].match == -1 && N1[pos].inDegree == N2[i].inDegree && N1[pos].outDegree == N2[i].outDegree) {

            int j, k;
            for (j = 0; j < n1; j++) {
                if (j != pos && G1[pos][j] && N1[j].match != -1 && !G2[i][N1[j].match]) break;
            }
            for (k = 0; k < n1; k++) {
                if (k != pos && G1[k][pos] && N1[k].match != -1 && !G2[N1[k].match][i]) break;
            }

            if (j == n1 && k == n1) {
                N1[pos].match = i;
                N2[i].match = pos;
                DFS(pos + 1);
                if (succeed) return;
                N1[pos].match = N2[i].match = -1;
            }
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    bool firstTime = true;

    while (1) {
        cin >> n;
        if (n == 0) break;

        if (!firstTime) cout << endl;
        firstTime = false;

        makeG();
        cut();
        succeed = false;
        DFS(0);
        for (map<string, int>::iterator iter = M1.begin(); iter != M1.end(); iter++) {
            cout << iter->first << "/" << N2[N1[iter->second].match].s << endl;
        }
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
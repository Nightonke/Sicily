// Problem#: 1308
// Submission#: 3279120
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
using namespace std;

const int MAX_V = 10005;
const int INF = 99999999;

int N, M;
vector<int> G[MAX_V];
int cost[MAX_V];
char in[MAX_V * 1000];

void read() {
    for (int i = 1; i <= N; i++) {
        G[i].clear();
    }
    for (int i = 1; i <= N; i++) {
        gets(in);
        int j = 0;
        int c = 0;
        int t = 0;
        for (; in[j] != ' ' && in[j] != '\0'; j++) {
            c = c * 10 + in[j] - '0';
        }
        cost[i] = c;
        if (in[j] == '\0') continue;
        for (j++; 1; j++) {
            if (in[j] == ' ') {
                G[i].push_back(t);
                t = 0;
            } else if (in[j] == '\0') {
                G[i].push_back(t);
                break;
            } else {
                t = t * 10 + in[j] - '0';
            }
        }    
    }
}

bool haveTo[MAX_V];
bool vis[MAX_V];

void searchHaveTo(int from) {
    vis[from] = haveTo[from] = true;
    int s = G[from].size();
    for (int i = 0; i < s; i++) {
        if (!vis[G[from][i]]) {
            true;
            searchHaveTo(G[from][i]);
        }
    }
}

int findAns() {
    for (int i = 1; i <= N; i++) haveTo[i] = vis[i] = false;
    haveTo[M] = vis[M] = true;
    int s = G[M].size();
    for (int i = 0; i < s; i++) {
        if (!vis[G[M][i]]) {
            searchHaveTo(G[M][i]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (haveTo[i]) sum += cost[i];
    }
    return sum;
}

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        scanf("%d\n", &M);
        read();
        printf("%d\n", findAns());
    }

    return 0;
}                                 
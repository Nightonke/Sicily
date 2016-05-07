// Problem#: 7766
// Submission#: 3380544
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

const int MAX_N = 200005;
const int MAX_E = 200005;

struct edge {
    int u, v, cost;
};

int N, E;
int par[MAX_N];
edge ED[MAX_E];

inline bool cmp(const edge & e1, const edge & e2) {
    return e1.cost < e2.cost;
}

void init() {
    for (int i = 0; i < N; i++) par[i] = i;
}

inline int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

inline void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    else par[x] = y;
}

int KRUSKAL() {
    sort(ED, ED + E, cmp);
    init();
    int ans = 0;
    for (int i = 0; i < E; i++) {
        if (find(ED[i].u) != find(ED[i].v)) {
            unite(ED[i].u, ED[i].v);
            ans += ED[i].cost;
        }
    }
    return ans;
}

int main() {

    //std::ios::sync_with_stdio(false);

    char text[50];

    while (1) {
        scanf("%d%d", &N, &E);
        gets(text);
        if (!N && !E) break;
        int sum = 0, j;
        for (int i = 0; i < E; i++) {
            gets(text);
            ED[i].u = ED[i].v = ED[i].cost = 0;
            for (j = 0; text[j] != ' '; j++) ED[i].u = ED[i].u * 10 + text[j] - '0';
            j++;
            for (; text[j] != ' '; j++) ED[i].v = ED[i].v * 10 + text[j] - '0';
            j++;
            for (; text[j] != '\0'; j++) ED[i].cost = ED[i].cost * 10 + text[j] - '0';
            sum += ED[i].cost;
        }
        cout << sum - KRUSKAL() << endl;
    }

    return 0;
}                                 
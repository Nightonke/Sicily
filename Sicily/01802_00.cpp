// Problem#: 1802
// Submission#: 3591809
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 131072;
const int INF = 1000000000;

struct Node {
    int min, max, min_diff;
}node[N << 1];

void init() {
    for (int i = 1; i < (N << 1); i++) {
        node[i].min = INF;
        node[i].max = -INF;
        node[i].min_diff = INF;
    }
}

inline int query() {
    return node[1].min_diff < N ? node[1].min_diff : -1;
}

inline int get_left_child(int p) {
    return (p << 1);
}

inline int get_right_child(int p) {
    return (p << 1) + 1;
}

inline int get_parent(int c) {
    return (c >> 1);
}

inline int get_node(int m) {
    return m + N - 1;
}

void update(int p) {
    int left_child = get_left_child(p);
    int right_child= get_right_child(p);
    node[p].min = min(node[left_child].min, node[right_child].min);
    node[p].max = max(node[left_child].max, node[right_child].max);
    node[p].min_diff = min(node[left_child].min_diff, node[right_child].min_diff);
    node[p].min_diff = min(node[p].min_diff, node[right_child].min - node[left_child].max);
}

void add(int m) {
    int cur = get_node(m);
    if (node[cur].min == INF) {
        node[cur].min = m;
        node[cur].max = m;
        do {
            cur = get_parent(cur);
            update(cur);
        } while (cur > 1);
    }
}

void remove(int m) {
    int cur = get_node(m);
    if (node[cur].min < INF) {
        node[cur].min = INF;
        node[cur].max = -INF;
        do {
            cur = get_parent(cur);
            update(cur);
        } while (cur > 1);
    }
}

int main() {
    int casen;
    scanf("%d", &casen);
    while (casen--) {
        init();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            char cmd[10];
            scanf("%s", cmd);
            if (cmd[0] == 'q') printf("%d\n", query());
            else {
                int m;
                scanf("%d", &m);
                if (cmd[0] == 'g') add(m);
                else remove(m);
            }
        }
        if (casen > 0) puts("");
    }
    return 0;
}                                 
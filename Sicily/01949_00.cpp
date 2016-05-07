// Problem#: 1949
// Submission#: 3589918
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

const int MAXV = 101100;

int n, m, k;

struct node {
    int min, max;
};

node arr[MAXV];
int input[MAXV];
int c;
int parent[MAXV];

void buildtree(int s, int e,int & maximal, int & minimal) {
    if (e - s + 1 <= 0) {
        maximal = minimal = -1;
        return;
    }
    if (e - s + 1 == 1) {
        maximal = minimal = input[e];
        return;
    }
    if (e - s + 1 == 2) {
        maximal = input[s] > input[e] ? input[s] : input[e];
        minimal = input[s] > input[e] ? input[e] : input[s];
        return;
    }
    int temp = (s + e) / 2;
    arr[temp].max = input[temp];
    arr[temp].min = input[temp];
    int i, j;
    buildtree(s, temp - 1, i, j);
    if (i >= 0 && j >= 0) {
        if (i > arr[temp].max) arr[temp].max = i;
        if (j < arr[temp].min) arr[temp].min = j;
    }
    buildtree(temp + 1, e, i, j);
    if (i >= 0 && j >= 0) {
        if (i > arr[temp].max) arr[temp].max = i;
        if (j < arr[temp].min) arr[temp].min = j;
    }
    maximal = arr[temp].max;
    minimal = arr[temp].min;
}

void init() {
    int i, j;
    buildtree(0, n - 1, i, j);
}

void searchtree(int s, int e, int & maximal, int & minimal, int u, int v) {
    if (e - s + 1 <= 0) {
        maximal = minimal = -1;
        return;
    }
    if (s == u && v == e) {
        if (e - s + 1 <= 0) {
            maximal = minimal = -1;
            return;
        }
        if (e - s + 1 == 1) {
            maximal = minimal = input[e];
            return;
        }
        if (e - s + 1 == 2) {
            maximal = input[s] > input[e] ? input[s] : input[e];
            minimal = input[s] > input[e] ? input[e] : input[s];
            return;
        }
        maximal = arr[(s + e) / 2].max;
        minimal = arr[(s + e) / 2].min;
        return;
    }
    int temp = (s + e) / 2;
    int i, j;
    if (u <= temp && temp <= v) {
        maximal = input[temp];
        minimal = input[temp];
        if (u <= temp - 1) {
            searchtree(s, temp - 1, i, j, u, temp - 1);
            if (i > maximal) maximal = i;
            if (j >= 0 && j < minimal) minimal = j;
        }
        if (v >= temp + 1) {
            searchtree(temp + 1, e, i, j, temp + 1, v);
            if (i > maximal) maximal = i;
            if (j >= 0 && j < minimal) minimal = j;
        }
        return;
    }
    if (u > temp) {
        searchtree(temp + 1, e, maximal, minimal, u, v);
        return;
    }
    searchtree(s, temp - 1, maximal, minimal, u, v);
}

int find(int a) {
    int i = a;
    while (parent[a] >= 0) a = parent[a];
    while (i != a) {
        int temp = parent[i];
        parent[i] = a;
        i = temp;
    }
    return a;
}

void unionset(int a, int b) {
    int i = find(a), j = find(b);
    if (i == j) return;
    if (i < j) {
        parent[j] = i;
        parent[i]--;
    } else {
        parent[i] = j;
        parent[j]--;
    }
}

void process() {
    int i;
    if (c != 0) printf("\n");
    c++;
    printf("Case %d\n", c);
    for (i = 0; i < n; i++) {
        scanf("%d", input + i);
        input[i]--;
        parent[i] = -1;
    }
    init();
    scanf("%d", &m);
    int u, v;
    for (i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        u--;
        v--;
        searchtree(0, n - 1, u, v, u, v);
        unionset(u, v);
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d%d", &u, &v);
        u--;
        v--;
        if (find(u) == find(v)) printf("YES\n");
        else printf("NO\n");
    }
}

int main() {
    while (scanf("%d", &n) != EOF) process();
    return 0;
}                                 
// Problem#: 1000
// Submission#: 3582816
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

/*
汉诺塔/////////////////////////////////////////////////

#include <stdio.h>

void move(int n, char a, char b, char c) {
    if (n == 1) {
        printf("%c->%c\n", a, c);
        return;
    }
    move(n - 1, a, c, b);
    printf("%c->%c\n", a, c);
    move(n - 1, b, a, c);
}

int main() {
    
    move(1, 'A', 'B', 'C');
    
    return 0;
}

二分查找///////////////////////////////////////////////////////////

int binarySearchIncreaseFirstTarget(int l, int r, int target) {  // 在不下降的序列中寻找target第一次出现位置
    if (test.size() == 0) return -1;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (test[m] < target) l = m + 1;
        else r = m;
    }
    if (test[l] == target) return l;
    else return -1;
}

快速排序////////////////////////////////////////////////////////////

int AdjustArray(int a[], int l, int r) {
    int K = a[l];
    while (l < r) {
        while (l < r && K <= a[r]) r--;
        if (l < r) {
            a[l] = a[r];
            l++;
        }
        while (l < r && a[l] <= K) l++;
        if (l < r) {
            a[r] = a[l];
            r--;
        }
    }
    a[l] = K;
    return l;
}
void QuickSort(int A[], int l, int r) {
    if (l < r) {
        int mid = AdjustArray(A, l, r);
        QuickSort(A, l, mid - 1);
        QuickSort(A, mid + 1, r);
    }
}

Dijkstra/////////////////////////////////////////////////////////////

const int MAX_N = 10005;
const int INF = 88888888;

struct edge {
    int to, cost;
    edge(int t = 0, int c = 0) {
        to = t;
        cost = c;
    }
};

vector<edge> G[MAX_N];
int d[MAX_N];
int N;

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, s));
    for (int i = 0; i < N; i++) d[i] = INF;
    d[s] = 0;
    while (!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        int from = now.second;
        int cost = now.first;
        if (d[from] < cost) continue;
        int s = G[from].size();
        for (int i = 0; i < s; i++) {
            if (d[G[from][i].to] > d[from] + G[from][i].cost) {
                d[G[from][i].to] = d[from] + G[from][i].cost;
                q.push(make_pair(d[G[from][i].to], G[from][i].to));
            }
        }
    }
}

Prim///////////////////////////////////////////////////////////////

int G[MAX_N][MAX_N];
int d[MAX_N];
int vis[MAX_N];

int N;
int ans;

void PrimMinTree(int s) {
    for (int i = 0; i < N; i++) {
        d[i] = INF;
        vis[i] = false;
    }
    d[s] = 0;
    while (1) {
        int MIN = INF;
        int p = -1;
        for (int i = 0; i < N; i++) {
            if (!vis[i] && d[i] < MIN) {
                p = i;
                MIN = d[i];
            }
        }
        if (p == -1) return;
        ans += d[p];
        vis[p] = true;
        for (int i = 0; i < N; i++) if (!vis[i] && d[i] > G[p][i]) d[i] = G[p][i];
    }
}

*/

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a - b);    
    return 0;
  
}                                 
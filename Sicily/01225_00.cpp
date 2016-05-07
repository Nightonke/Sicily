// Problem#: 1225
// Submission#: 3587790
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 1000010;

int map[maxn * 2];
int Index[maxn + 1];
int k[maxn + 1];
int stack[maxn];
int ptr[maxn];
int a[maxn], b[maxn];
char flag[maxn + 1];
int n;
int p1, p2;

int dfs(int v) {
    int i, j, p;
    memset(flag, 0, sizeof(flag));
    stack[0] = v;
    ptr[0] = 0;
    flag[v] = 1;
    for (p = 0; p >= 0;) {
        i = stack[p];
        if (ptr[p] < k[i]) {
            j = map[Index[i] + ptr[p]];
            ptr[p]++;
            if (p == 0 || j != stack[p - 1]) {
                if (flag[j]) {p1 = i; p2 = j; return 1;}
                else {
                    p++;
                    stack[p] = j;
                    ptr[p] = 0;
                    flag[j] = 1;
                }
            }
        } else p--;
    }
    return 0;
}

int work(int v) {
    int i, j, p;
    stack[0] = v;
    ptr[0] = 0;
    a[0] = 1;
    b[0] = 1;
    for (p = 0; p >= 0;) {
        i = stack[p];
        if (ptr[p] < k[i]) {
            j = map[Index[i] + ptr[p]];
            ptr[p]++;
            if ((i != p1 || j != p2) && (i != p2 || j != p1) && (p == 0 || j != stack[p - 1])) {
                p++;
                stack[p] = j;
                ptr[p] = 0;
                a[p] = 1;
                b[p] = 0;
            }
        } else {
            if (p > 0) {
                a[p - 1] += min(a[p], b[p]);
                b[p - 1] += a[p];
            }
            p--;
        }
    }
    return a[0];
}

int main() {
    int i, j, t, c1, c2;
    scanf("%d", &n);
    for (i = 1, t = 0; i <= n; i++) {
        Index[i] = t;
        scanf("%d", &k[i]);
        for (j = 0; j < k[i]; j++) scanf("%d", &map[t++]);
    }
    dfs(1);
    c1 = work(p1);
    c2 = work(p2);
    printf("%d\n", min(c1, c2));
    return 0;
}                                 
// Problem#: 2680
// Submission#: 3592135
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 40009;

int N, L, U;
int * p, cnt, mem[MAXN];
int sum[MAXN];

void input() {
    int i, x;
    scanf("%d%d", &L, &U);
    sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
    }
}

void solve() {
    int i, j, ans;
    cnt = 0;
    ans = sum[L] - sum[0];
    p = mem;
    p[cnt++] = 1;
    for (i = L + 1; i <= N; i++) {
        while (cnt && i - p[0] + 1 > U) {
            --cnt;
            ++p;
        }
        for (j = cnt - 1; j >= 0; j--) 
            if (sum[i - L] < sum[p[j] - 1]) break;
        p[j + 1] = i - L + 1;
        cnt = j + 2;
        if (ans > sum[i] - sum[p[0] - 1]) ans = sum[i] - sum[p[0] - 1];
    }
    printf("%d\n", ans);
}

int main() {
    while (scanf("%d", &N) && N) {
        input();
        solve();
    }
    return 0;
}                                 
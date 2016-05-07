// Problem#: 1909
// Submission#: 3590857
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 50000;
const int MAXM = 3;

int alloc[MAXM][MAXN];
int request[MAXM][MAXN];
int avail[MAXM];
int n, m;
int order[MAXM][MAXN];
int counter[MAXN];
int ptr[MAXM];
int cmp_id;

void input(int table[MAXM][MAXN]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &table[i][j]);
}

bool cmp(int a, int b) {
    return request[cmp_id][a] < request[cmp_id][b];
}
int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        int i, j;
        input(alloc);
        input(request);
        for (i = 0; i < m; i++) scanf("%d", &avail[i]);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) order[i][j] = j;
            cmp_id = i;
            sort(order[i], order[i] + n, cmp);
        }
        memset(counter, 0, sizeof(int) * n);
        memset(ptr, 0, sizeof(int) * m);
        while (1) {
            int flag = 0;
            for (i = 0; i < m; i++) {
                while (1) {
                    if (ptr[i] >= n) break;
                    int pid = order[i][ptr[i]];
                    if (request[i][pid] > avail[i]) break;
                    counter[pid]++;
                    ptr[i]++;
                    flag = 1;
                    if (counter[pid] == m) {
                        for (j = 0; j < m; j++) avail[j] += alloc[j][pid];
                    }
                }
            }
            if (!flag) break;
        }
        for (i = 0; i < m && ptr[i] >= n; i++);
        printf(i < m ? "No\n" : "Yes\n");
    }
    return 0;
}                                 
// Problem#: 1739
// Submission#: 3584618
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

unsigned short n, m, w[101], t[101];
unsigned short a[101], id[101][101];

void input() {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d%d", &w[i], &t[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        for (j = 0; j < a[i]; j++) {
            scanf("%d", &id[i][j]);
            id[i][j]--;
        }
    }
}

int cal() {
    unsigned short ans[1010];
    unsigned short p[101], maxp[101], maxv[101][2];
    int i, j, t0, t1, temp, choice, ret, tot;
    
    tot = 0;
    memset(p, 0, sizeof(p));
    for (i = 0; i < m; i++) {
        maxp[i] = p[i];
        t0 = maxv[i][0] = w[id[i][p[i]]];
        t1 = maxv[i][1] = t[id[i][p[i]]];
        for (j = p[i] + 1; j < a[i]; j++) {
            t0 += w[id[i][j]];
            t1 += t[id[i][j]];
            if (t0 * maxv[i][1] > t1 * maxv[i][0]) {
                maxp[i] = j;
                maxv[i][0] = t0;
                maxv[i][1] = t1;
            }
        }
    }
    while (1) {
        choice = -1;
        for (i = 0; i < m; i++)
            if (p[i] < a[i] && (choice == -1 || maxv[choice][0] * maxv[i][1] < maxv[choice][1] * maxv[i][0])) {
                choice = i;
            }
        if (choice == -1) break;
        for (i = p[choice]; i <= maxp[choice]; i++) ans[tot++] = id[choice][i];
        
        p[choice] = maxp[choice] + 1;
        maxp[choice] = p[choice];
        t0 = maxv[choice][0] = w[id[choice][p[choice]]];
        t1 = maxv[choice][1] = t[id[choice][p[choice]]];
        for (i = p[choice] + 1; i < a[choice]; i++) {
            t0 += w[id[choice][i]];
            t1 += t[id[choice][i]];
            if (t0 * maxv[choice][1] > t1 * maxv[choice][0]) {
                maxp[choice] = i;
                maxv[choice][0] = t0;
                maxv[choice][1] = t1;
            }
        }
    }
    ret = temp = 0;
    for (i = 0; i < tot; i++) {
        temp += t[ans[i]];
        ret += w[ans[i]] * temp;
    }
    return ret;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        input();
        printf("%d\n", cal());
    }
    return 0;
}                                 
// Problem#: 1718
// Submission#: 3585200
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string.h>
#include <stdio.h>
#include <math.h>

#define MAXN 110
#define MAXM 110

long N, M;
long rank[MAXN][MAXM];
bool b[MAXN][MAXN];
long outd[MAXN];

void input() {
    long i, j, k, x;
    scanf("%ld%ld", &N, &M);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%ld", &x);
            x--;
            rank[x][i] = j;
        }
    }
    memset(b, 0, sizeof(b));
    memset(outd, 0, sizeof(outd));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            for (k = 0; k < M; k++)
                if (rank[i][k] >= rank[j][k]) break;
            if (k >= M) {
                b[i][j] = 1;
                outd[i]++;
            }
        }
}
    
long solve() {
    long v[MAXN], flag = 1, answer = 0, i, j, t;
    memset(v, 0xff, sizeof(v));
    while (flag) {
        flag = 0;
        for (i = 0; i < N; i++)
            if (!outd[i] && v[i] < 0) {
                flag = 1;
                for (t = 0, j = 0; j < N; j++)
                    if (b[i][j] && v[j] > t) t = v[j];
                v[i] = t + 1;
                if (v[i] > answer) answer = v[i];
                for (j = 0; j < N; j++) 
                    if (b[j][i]) outd[j]--;
            }
    }
    return answer;
}

int main() {
    long C;
    scanf("%ld", &C);
    while (C--) {
        input();
        printf("%ld\n", solve());
    }
    return 0;
}                                 
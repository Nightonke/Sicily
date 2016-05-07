// Problem#: 1918
// Submission#: 3577951
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

short G[305][305];
short row1[305][305], col1[305][305];
int sum[305][305];
int h, w;
int ans;

void init() {
    int last1;
    for (int i = 0; i < h; i++) {
        last1 = -1;
        for (int j = w - 1; j >= 0; j--) {
            if (G[i][j] == -1) last1 = -1;
            else if (last1 == -1) last1 = j;
            row1[i][j] = last1;
        }
    }
    for (int i = 0; i < w; i++) {
        last1 = -1;
        for (int j = h - 1; j >= 0; j--) {
            if (G[j][i] == -1) last1 = -1;
            else if (last1 == -1) last1 = j;
            col1[j][i] = last1;
        }
    }
    sum[0][0] = G[0][0];
    for (int i = 1; i < h; i++) sum[i][0] = sum[i - 1][0] + G[i][0];
    for (int i = 1; i < w; i++) sum[0][i] = sum[0][i - 1] + G[0][i];
    for (int i = 1; i < h; i++) 
        for (int j = 1; j < w; j++) 
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + G[i][j];
}

inline int abs(int a) {if (a < 0) return -a; return a;}

inline void cal(int si, int sj) {
    int li = si + 1, lj = sj + 1;
    while (li < h && lj < w && G[si][lj] == 1 && G[li][sj] == 1) {
        if (lj <= row1[li][sj] && li <= col1[si][lj])
            if (abs(sum[li - 1][lj - 1] - sum[si][lj - 1] - sum[li - 1][sj] + sum[si][sj]) <= 1) ans++;
        lj++;
        li++;
    }
}

int main() {
    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        scanf("%d%d\n", &h, &w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &G[i][j]);
                if (G[i][j] == 0) G[i][j] = -1;
            }
        }
        ans = 0;
        init();
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if (G[i][j] == 1) cal(i, j);
        printf("%d\n", ans);
    }
    return 0;
}                                 
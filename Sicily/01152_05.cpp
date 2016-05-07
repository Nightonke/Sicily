// Problem#: 1152
// Submission#: 2574565
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int h[6][7], st[31], now, go[] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};

void horse(int i, int j, int now) {
    int goi, goj;
    h[i][j] = 1;
    st[now] = i * 6 + j + 1;
    if (now == 29)
        return;
    for (int k = 0; k < 16; k += 2) {
        goi = i + go[k];
        goj = j + go[k + 1];
        if (goi >= 0 && goi <= 4 && goj >= 0 && goj <= 5 && h[goi][goj] == 0)
            horse(goi, goj, now + 1);
    }
    if (st[now + 1] == 0) {
        st[now] = 0;
        h[i][j] = 0;
    }
    return;
}

int main() {
    int n, i, j;
    while (scanf("%d", &n), n != -1) {
        now = 0;
        memset(h, 0, sizeof(h));
        memset(st, 0, sizeof(st));
        i = (n - 1) / 6;
        j = (n - 1) % 6;
        horse(i, j, now);
        printf("%d", st[0]);
        for (i = 1; i < 30; i++)
            printf(" %d", st[i]);
        printf("\n");
    }
    return 0;
}                                 
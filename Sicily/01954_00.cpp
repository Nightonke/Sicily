// Problem#: 1954
// Submission#: 3593222
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 20;
long long f[MAXN][MAXN];
long long Index;
int n;

char * str = "()[]{}";
char stack[MAXN * 2];

void init() {
    int i, j;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (j = 1; j < MAXN; j++) f[0][j] += f[0][j - 1];
    for (i = 1; i < MAXN; i++) {
        for (j = 0; j < MAXN; j++) {
            if (j + 1 < MAXN) f[i][j] += 3 * f[i - 1][j + 1];
            if (j > 0) f[i][j] += f[i][j - 1];
        }
    }
}

void show(int pos, int depth, int m, long long Index) {
    if (pos == n) return;
    int i;
    for (i = 0; i < 6; i++) {
        if (i % 2 == 0 && m >= 1) {
            if (Index < f[m - 1][depth + 1]) break;
            Index -= f[m - 1][depth + 1];
        } else if (depth >= 1 && str[i] == stack[depth - 1]) {
            if (Index < f[m][depth - 1]) break;
            Index -= f[m][depth - 1];
        }
    }
    printf("%c", str[i]);
    if (i % 2 == 0) {
        stack[depth] = str[i + 1];
        show(pos + 1, depth + 1, m - 1, Index);
    } else show(pos + 1, depth - 1, m, Index);
}

int main() {
    init();
    int tn;
    scanf("%d", &tn);
    while (tn--) {
        scanf("%d%lld", &n, &Index);
        if (Index >= f[n / 2][0]) printf("invalid");
        else show(0, 0, n / 2, Index);
        printf("\n");
    }
    return 0;
}                                 
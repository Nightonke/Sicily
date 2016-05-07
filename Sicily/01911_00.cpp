// Problem#: 1911
// Submission#: 3591065
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 100;
const int MAXC = 26;

char src[MAXN + 1];
char dst[MAXN + 1];
int f[MAXN][MAXN + 1][MAXC + 1];

int main() {
    while (scanf("%s%s", src, dst) == 2) {
        int n = strlen(src);
        for (int begin = 0; begin < n; begin++) {
            for (int letter = 0; letter < MAXC; letter++) {
                if (letter + 'a' == dst[begin]) f[begin][begin + 1][letter] = 0;
                else f[begin][begin + 1][letter] = 1;
            }
            if (src[begin] == dst[begin]) f[begin][begin + 1][MAXC] = 0;
            else f[begin][begin + 1][MAXC] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int begin = 0; begin + len <= n; begin++) {
                int end = begin + len;
                for (int letter = 0; letter <= MAXC; letter++) {
                    int & cur = f[begin][end][letter];
                    cur = f[begin + 1][end][dst[begin] - 'a'];
                    if (letter != dst[begin]) cur++;
                    for (int delimeter = begin + 1; delimeter < end; delimeter++) {
                        int tmp = f[begin][delimeter][letter] + f[delimeter][end][letter];
                        if (tmp < cur) cur = tmp;
                    }
                }
            }
        }
        printf("%d\n", f[0][n][MAXC]);
    }
    return 0;
}                                 
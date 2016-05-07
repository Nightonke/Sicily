// Problem#: 1156
// Submission#: 2579843
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int a[1010][3], judge[1010][3];
char b[1010];
void pre(int fa) {
    printf("%c", b[fa]);
    if (a[fa][0] != 0) {
        pre(a[fa][0]);
    }
    if (a[fa][1] != 0)
        pre(a[fa][1]);
    return;
}

int main() {
    int n, i, t1, t2, t3, t4, an;
    while (scanf("%d", &n) != EOF) {
        memset(judge, 0, sizeof(judge));
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++) {
            scanf("%d %c %d %d", &t1, &t2, &t3, &t4);
            a[t1][0] = t3;
            a[t1][1] = t4;
            b[t1] = t2;
            judge[t1][0] = 1;
            judge[t3][1] = 1;
            judge[t4][1] = 1;
        }
        for (i = 1; i < 1001; i++) {
            if (judge[i][0] == 1 && judge[i][1] == 0) {
                an = i;
                break;
            }
        }
        pre(an);
        printf("\n");
    }
    return 0;
}                                 
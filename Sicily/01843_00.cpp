// Problem#: 1843
// Submission#: 3590299
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int cs, n, l;
char ans[5001];
int a[50][50];

int main() {
    char s[50];
    int i, j, x, y;
    scanf("%d", &cs);
    while (cs--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%s", &s);
            for (j = 1; j <= i; j++)
                switch(s[j - 1]) {
                case 'R': a[i][j] = 0; break;
                case 'G': a[i][j] = 1; break;
                case 'B': a[i][j] = 2;
            }
        }
        x = y = 1;
        l = 0;
        for (i = 1; i < n; i++) {
            while (x < n) {
                x++;
                a[x][y] = (a[x][y] + 1) % 3;
                ans[l++] = '1';
            }
            while (x > i) {
                while (a[x][y] != 2) {
                    a[x - 1][y] = (a[x - 1][y] + 1) % 3;
                    ans[l++] = '9';
                    a[x][y] = (a[x][y] + 1) % 3;
                    ans[l++] = '1';
                }
                x--;
                a[x][y] = (a[x][y] + 1) % 3;
                ans[l++] = '9';
            }
            x++;
            y++;
            a[x][y] = (a[x][y] + 1) % 3;
            ans[l++] = '3';
        }
        while (x != 1 || y != 1) {
            while (a[x][y] != 2) {
                a[x - 1][y - 1] = (a[x - 1][y - 1] + 1) % 3;
                ans[l++] = '7';
                a[x][y] = (a[x][y] + 1) % 3;
                ans[l++] = '3';
            }
            x--;
            y--;
            a[x][y] = (a[x][y] + 1) % 3;
            ans[l++] = '7';
        }
        switch(a[x][y]) {
        case 0:
            ans[l - 1] = 0;
            printf("1 1\n");
            printf("%s\n", ans);
            break;
        case 1:
            ans[l] = 0;
            printf("2 1\n");
            printf("9%s\n", ans);
            break;
        case 2:
            ans[l] = 0;
            printf("1 1\n");
            printf("%s\n", ans);
        }
    }
    return 0;
}                                 
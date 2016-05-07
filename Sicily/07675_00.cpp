// Problem#: 7675
// Submission#: 2559127
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int a[60][60];
void dfs(int i, int j) {
    int x, y;
    a[i][j] = 0;
    for (x = -1; x <= 1; x++)
    {
        for (y = -1; y <= 1; y++)
        {
            if (a[i + x][j + y] == 1)
            {
                dfs(i + x, j + y);
            }
        }
    }
}
int main() {
    int n, m, i, j, counter;
    while (scanf("%d %d", &n, &m), n && m) {
        memset(a, 0, sizeof(a));
        counter = 0;
        for (i = 1; i <= m; i++) 
        {
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] == 1)
                {
                    dfs(i, j);
                    counter++;
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 
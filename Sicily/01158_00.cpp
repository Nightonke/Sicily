// Problem#: 1158
// Submission#: 2581670
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int store[1000000], k, a[15][15], m, n;

void dfs11(int i, int j, int sum) {
    if (i == m - 1 && j == n - 1 && sum + a[i][j] > 0) {
        store[k++] = sum + a[i][j];
    }
    if (i == m - 1 && j == n - 1)
        return;
    if (i == m - 1)
        dfs11(i, j + 1, sum + a[i][j]);
    if (j == n - 1)
        dfs11(i + 1, j, sum + a[i][j]);
    if (i < m - 1 && j < n - 1)    
        dfs11(i + 1, j, sum + a[i][j]);
    if (i < m - 1 && j < n - 1)
        dfs11(i, j + 1, sum + a[i][j]);
}

void findmin11() {
    int min = 1000000;
    if (k == 0) {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < k; i++)
        if (min > store[i] && store[i] > 0)
            min = store[i];
    printf("%d\n", min);
}

int main() {
    int i, j;
    while (scanf("%d %d", &m, &n) == 2) {
        for (i = 0; i < 11; i++)
            for (j = 0; j < 11; j++)
                a[i][j] = 0;
        for (i = 0; i < 10001; i++)
            store[i] = 0;
        k = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        dfs11(0, 0, 0);
        findmin11();
    }
    return 0;
}                                 
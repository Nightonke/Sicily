// Problem#: 1011
// Submission#: 2693384
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
unsigned long long a[11][2002];

void ready() {
    int i, j, k;
    memset(a, 0, sizeof(a));
    for (i = 1; i <= 2000; i++) {
        a[1][i] = 1;
    }
    for (i = 2; i <= 10; i++) {
        for (j = (int)pow(2, i - 1); j <= 2000; j++) {
            for (k = (int)pow(2, i - 2); k <= j / 2; k++) {
                a[i][j] += a[i - 1][k];
            }
        }
    }
}

int main() {
    int t, counter = 0, n, m, i;
    unsigned long long ans;
    ready();
    scanf("%d", &t);
    while(t--) {
        counter++;
        ans = 0;
        scanf("%d%d", &n, &m);
        for (i = (int)pow(2, n - 1); i <= m; i++) {
            ans += a[n][i];
        }
        printf("Case %d: n = %d, m = %d, # lists = %lld\n", counter, n, m, ans);
    }
    return 0;
}                                 
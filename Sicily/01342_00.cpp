// Problem#: 1342
// Submission#: 2488042
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
long long int V[26][30001] = {0};
long long int max(long long int a, long long int b) {
    return a > b ? a : b;
}
int main() {
    long long int maxrmb, n, i, j, eachprice[30], importance[30];
    while (scanf("%lld %lld", &maxrmb, &n) != EOF) {
        memset(V, 0, sizeof(V));
        for (i = 1; i <= n; i++) {
            scanf("%lld %lld", &eachprice[i], &importance[i]);
            importance[i] = importance[i] * eachprice[i];
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= maxrmb; j++)
                if (j < eachprice[i])
                    V[i][j] = V[i - 1][j];
                else
                    V[i][j] = max(V[i - 1][j], V[i - 1][j - eachprice[i]] + importance[i]);
        printf("%lld\n", V[n][maxrmb]);
    }
    return 0;
}                                 
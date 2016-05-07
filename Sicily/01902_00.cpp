// Problem#: 1902
// Submission#: 3590628
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 500;
const int M = 1000007;

int a[MAXN + 1];

void init() {
    memset(a, 0, sizeof(a));
    a[0] = 1;
    for (int i = 2; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j++) {
            a[j] += a[j - i];
            if (a[j] >= M) a[j] -= M;
        }
    }
}

int main() {
    init();
    int cs, n;
    scanf("%d", &cs);
    while (cs--) {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}                                 
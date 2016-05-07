// Problem#: 2014
// Submission#: 2753089
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int ans[305], n, i, c, N;
    scanf("%d%d", &N, &n);
    memset(ans, 0, sizeof(ans));
    while (n--) {
        scanf("%d", &c);
        ans[c] += 1;
        for (i = c + 1; i <= N; i++) {
            ans[i] += ans[i - c];
        }
    }
    printf("%d\n", ans[N]);
    return 0;
}                                 
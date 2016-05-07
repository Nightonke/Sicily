// Problem#: 13296
// Submission#: 3560831
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

long long da[100005];

int main() {

    long long N, M, K, st, ed, d, ans = 0, sum = 0;
    scanf("%lld%lld", &N, &M);
    while (M--) {
        scanf("%lld%lld%lld", &st, &ed, &d);
        da[st] += d;
        da[ed + 1] -= d;
    }
    for (int i = 1; i <= N; i++) da[i] = sum += da[i];
    for (int i = N - 1; i >= 1; i--) da[i] += da[i + 1];
    scanf("%lld", &K);
    while (K--) {
        scanf("%lld%lld", &d, &st);
        if (d > da[st]) ans++;
    }
    printf("%lld\n", ans);

    return 0;
}                                 
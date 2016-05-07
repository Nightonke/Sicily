// Problem#: 13295
// Submission#: 3560624
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    long long N, M, sum = 0, st, ed, da, K, H, ans = 0;
    scanf("%lld%lld", &N, &M);
    while (M--) {
        scanf("%lld%lld%lld", &st, &ed, &da);
        sum += (ed - st + 1) * da;
    }
    scanf("%lld", &K);
    while (K--) {
        scanf("%lld", &H);
        if (H > sum) ans++;
    }
    printf("%lld\n", ans);
    return 0;
}                                 
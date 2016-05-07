// Problem#: 1085
// Submission#: 3257689
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {

    //std::ios::sync_with_stdio(false);
    long long N, ans, kn, pnkn;
    while (scanf("%lld", &N) != EOF) {
        ans = 1;
        for (long long int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                kn = 0, pnkn = 1;
                while (N % i == 0) {
                    pnkn *= i;
                    kn++;
                    N /= i;
                }
                ans *= kn * (pnkn - pnkn / i) + pnkn;
            }
        }
        printf("%lld\n", ans * (2 * N - 1));
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
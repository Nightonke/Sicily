// Problem#: 1085
// Submission#: 3257750
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1085
// Submission#: 3257531
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        long long N;
        long long ans = 1;
        cin >> N;
        if (cin.eof()) break;
        for (long long i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                long long kn = 0, pnkn = 1;
                while (N % i == 0) {
                    pnkn *= i;
                    kn++;
                    N /= i;
                }
                ans *= kn * (pnkn - pnkn / i) + pnkn;
            }
        }
        cout << ans * (2 * N - 1) << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
// Problem#: 1894
// Submission#: 3593164
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(const int & a, const int & b) {
    return a > b;
}

int main() {
    long long mul, sum;
    int n, a[16], m;
    int i, j, t;
    while (scanf("%d", &n), n) {
        mul = 1;
        for (i = 1; i <= n; i++) {
            scanf("%d", a + i);
            mul *= a[i];
        }
        sort(a + 1, a + 1 + n);
        for (i = 1; i <= n; i++)
            if (a[i] >= 0) break;
        m = i - 1;
        sort(a + 1, a + 1 + m, cmp);
        if (mul < 0) mul = -mul;
        sum = 0;
        for (i = 1; i <= n; i++) sum += mul / a[i];
        if (sum > 0)
            if (mul % sum == 0)
                printf("%lld\n", mul / sum);
            else
                printf("%lld\n", mul / sum + 1);
        else {
            for (i = 1; i <= m; i++) {
                mul /= a[i];
                if (mul < 0) mul = -mul;
                sum = 0;
                for (j = i + 1; j <= n; j++) sum += mul / a[j];
                if (sum > 0) break;
            }
            if (i <= m) printf("NO %d\n", i);
            else printf("Impossible\n");
        }
    }
    return 0;
}                                 
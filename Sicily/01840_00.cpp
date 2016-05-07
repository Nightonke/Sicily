// Problem#: 1840
// Submission#: 3590265
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <map>
using namespace std;

map<long long, int> m;
int cs, n, ans;
long long d[100];

long long abs(long long a) {if (a < 0) return -a; return a;}

bool in_range(long long a, int k) {
    long long ret = 1;
    while (k--) {
        ret *= a;
        if (ret > 0x7fffffff || -ret > 0x80000000) return false;
    }
    return true;
}

long long power(long long a, int k) {
    long long ret = 1;
    while (k--) ret *= a;
    return ret;
}

void FIND(long long a, int k, int st) {
    long long i;
    int l = 0;
    switch(st) {
    case 1:
        for (i = a; ; i += k)
            if (m[i]) m[i]--, l++;
            else break;
        if (l > ans) ans = l;
        for (i = a; l; i += k) m[i]++, l--;
        break;
    case 2:
        for (i = a; ; i *= k)
            if (m[i]) m[i]--, l++;
            else break;
        if (l > ans) ans = l;
        for (i = a; l; i *= k) m[i]++, l--;
        break;
    case 3:
        i = a;
        while (1) {
            if (m[i]) m[i]--, l++;
            else break;
            if (in_range(i, k)) i = power(i, k);
            else break;
        }
        if (l > ans) ans = l;
        for (i = a; l; i = power(i, k)) m[i]++, l--;
    }
}

int main() {
    int i, j, k;
    scanf("%d", &cs);
    while (cs--) {
        scanf("%d", &n);
        m.clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &k);
            d[i] = k;
            m[d[i]]++;
        }
        ans = 1;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (i != j) {
                    FIND(d[i], d[j] - d[i], 1);
                    if (d[i] && d[j] % d[i] == 0) FIND(d[i], d[j] / d[i], 2);
                    switch (d[i]) {
                    case 0:
                        if (d[j] == 0) FIND(0, 1, 3);
                        break;
                    case 1:
                        if (d[j] == 1) FIND(1, 1, 3);
                        break;
                    case -1:
                        if (d[j] == -1) FIND(-1, 1, 3);
                        if (d[j] == 1) FIND(-1, 0, 3);
                        break;
                    default:
                        for (k = 0; in_range(d[i], k); k++) {
                            long long f = power(d[i], k);
                            if (f > abs(d[j])) break;
                            else if (f == d[j]) {
                                FIND(d[i], k, 3);
                                break;
                            }
                        }
                    }
                }
        printf("%d\n", ans);
    }
    return 0;
}                                 
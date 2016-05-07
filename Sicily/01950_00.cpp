// Problem#: 1950
// Submission#: 3591867
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 100;

class BigInteger {
    static const int MAXN_LEN = 200;
    int d[MAXN_LEN];
    int len;
public:
    BigInteger(int v = 0) {
        memset(d, 0, sizeof(d));
        len = 0;
        while (v > 0) {
            d[len++] = v % 10;
            v /= 10;
        }
        if (len == 0) len = 1;
    }
    BigInteger operator + (const BigInteger other) const {
        BigInteger ret;
        ret.len = max(len, other.len);
        for (int i = 0; i < ret.len; i++) ret.d[i] = d[i] + other.d[i];
        for (int i = 0; i < ret.len; i++) {
            if (ret.d[i] > 9) {
                ret.d[i] -= 10;
                ret.d[i + 1]++;
            }
        }
        if (ret.d[ret.len] > 0) ret.len++;
        return ret;
    }
    BigInteger operator * (const BigInteger other) const {
        BigInteger ret;
        ret.len = len + other.len - 1;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < other.len; j++) ret.d[i + j] += d[i] * other.d[j];
        for (int i = 0; i < ret.len; i++)
            if (ret.d[i] > 9) {
                ret.d[i + 1] += ret.d[i] / 10;
                ret.d[i] %= 10;
            }
        if (ret.d[ret.len] > 0) ret.len++;
        while (ret.len > 1 && ret.d[ret.len - 1] == 0) ret.len--;
        return ret;
    }
    void print() {
        for (int i = len - 1; i >= 0; i--) printf("%d", d[i]);
    }
};

int n, k;
BigInteger f[MAXN + 1][MAXN + 1];

void preprocess() {
    f[0][0] = 1;
    for (int i = 1; i <= MAXN; i++)
        for (int j = 1; j <= MAXN; j++) 
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j] * (i - 1);
}

bool input() {
    scanf("%d%d", &n, &k);
    return n || k;
}

int main() {
    preprocess();
    while (input()) {
        BigInteger ans(0);
        for (int i = 1; i <= k; i++) ans = ans + f[n][i];
        ans.print();
        puts("");
    }
    return 0;
}                                 
// Problem#: 2679
// Submission#: 3592109
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

class BigInteger {

    static const int MAXN_LEN = 2000;

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
        printf("\n");

    }

};

BigInteger ans[110], dp[110][110];
BigInteger sum;

int main() {
    int i, j;
    dp[1][0] = 1;
    ans[1] = 1;
    for (i = 2; i <= 100; i++) {
        sum = 0;
        for (j = 0; j < i; j++) {
            sum = sum + dp[i - 1][j];
            dp[i][j] = sum * (i - j);
            ans[i] = ans[i] + dp[i][j];
        }
    }
    int n;
    while (scanf("%d", &n) && n) ans[n].print();
    return 0;
}                                 
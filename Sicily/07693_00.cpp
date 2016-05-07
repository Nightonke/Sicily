// Problem#: 7693
// Submission#: 3686633
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int m, n;
bool isConnect[505][505];
int b[505], r[505], bConnectNum[505], rConnectNum[505];

inline int gcd(int a, int b) {
    int temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    char c[10000];
    int sum, k;
    while (1) {
        scanf("%d%d", &m, &n);
        if (m == 0 && n == 0) break;
        gets(c);
        k = 0;
        while (k < m) {
            gets(c);
            sum = 0;
            for (int i = 0; c[i] != '\0'; i++) {
                if (c[i] == ' ')  {
                    b[k++] = sum;
                    sum = 0;
                }
                else sum = sum * 10 + c[i] - '0';
            }
            b[k++] = sum;
        }
        k = 0;
        while (k < n) {
            gets(c);
            sum = 0;
            for (int i = 0; c[i] != '\0'; i++) {
                if (c[i] == ' ')  {
                    r[k++] = sum;
                    sum = 0;
                }
                else sum = sum * 10 + c[i] - '0';
            }
            r[k++] = sum;
        }
        for (int i = 0; i < m; i++) {
            int cn = b[i];
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (gcd(cn, r[j]) != 1) {
                    isConnect[i][j] = true;
                    num++;
                }
                else isConnect[i][j] = false;
            }
            bConnectNum[i] = num;
        }
        for (int j = 0; j < n; j++) {
            int num = 0;
            for (int i = 0; i < m; i++) {
                if (isConnect[i][j]) num++;
            }
            rConnectNum[j] = num;
        }
        int ans = 0;
        while (1) {
            int bpos = -1, rpos, min = n + 1;
            for (int i = 0; i < m; i++) {
                if (bConnectNum[i] && bConnectNum[i] < min) {
                    bpos = i;
                    min = bConnectNum[i];
                }
            }
            if (bpos == -1) break;
            ans++;
            min = m + 1;
            for (int j = 0; j < n; j++) {
                if (isConnect[bpos][j] && rConnectNum[j] < min) {
                    rpos = j;
                    min = rConnectNum[j];
                }
            }
            isConnect[bpos][rpos] = false;
            bConnectNum[bpos] = 0;
            rConnectNum[rpos] = 0;
            for (int i = 0; i < m; i++) {
                if (isConnect[i][rpos]) {
                    isConnect[i][rpos] = false;
                    bConnectNum[i]--;
                }
            }
            for (int j = 0; j < n; j++) {
                if (isConnect[bpos][j]) {
                    isConnect[bpos][j] = false;
                    rConnectNum[j]--;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}                                 
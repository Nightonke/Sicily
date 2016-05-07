// Problem#: 2500
// Submission#: 3543574
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

const int MAX_N = 1005;

int N;
int s[MAX_N];
int fromLLongest[MAX_N];
int fromRLongest[MAX_N];
int B[MAX_N];

inline int max(int a, int b) {if (a > b) return a; return b;}

inline int BSearch(int l, int r, int target) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (B[m] > target) r = m - 1;
        else if (B[m] < target) l = m + 1;
        else return m;
    }
    return l;
}

void LIS() {  // 提前算好在每个位置的从左到右和从右到左的最长子序列
    int longest = 1;
    int length = 1;
    B[0] = s[0];
    fromLLongest[0] = 1;
    for (int i = 1; i < N; i++) {
        if (s[i] > B[length - 1]) B[length++] = s[i];
        else B[BSearch(0, length - 1, s[i])] = s[i];
        longest = max(longest, length);  // 更新最长子序列
        fromLLongest[i] = longest;
    }
    longest = 0;
    length = 1;
    B[0] = s[N - 1];
    fromRLongest[N - 1] = 1;
    for (int i = N - 1; i >= 0; i--) {
        if (s[i] > B[length - 1]) B[length++] = s[i];
        else B[BSearch(0, length, s[i])] = s[i];
        longest = max(longest, length);  // 更新最长子序列
        fromRLongest[i] = longest;
    }
}

int main() {

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d", &s[i]);
        LIS();
        int ans = 0;
        for (int i = 0; i < N - 1; i++) ans = max(fromLLongest[i] + fromRLongest[i + 1], ans);
        ans = max(fromLLongest[N - 1], ans);
        printf("%d\n", N - ans);
    }

    return 0;
}                                 
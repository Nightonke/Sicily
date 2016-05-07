// Problem#: 8843
// Submission#: 3557676
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct man {
    int rank, length;
    char name[25];
};

man M[300005];

bool cmp(const man & m1, const man & m2) {
    if (m1.length == m2.length) return m1.rank < m2.rank;
    return m1.length < m2.length;
}

inline int ABS(int a) {if (a < 0) return -a; return a;}

int main() {
    int N, K;
    scanf("%d%d\n", &N, &K);
    for (int i = 0; i < N; i++) {
        M[i].rank = i;
        gets(M[i].name);
        M[i].length = strlen(M[i].name);
    }
    sort(M, M + N, cmp);
    int startPos = 0, endPos = 0;
    long long ans = 0;
    for (int i = 1; i < N; i++) {
        if (M[startPos].length == M[i].length)
            if (ABS(M[startPos].rank - M[i].rank) <= K) {
                ans += endPos - startPos + 1;
                endPos++;
            } else {
                while (startPos <= endPos && ABS(M[startPos].rank - M[i].rank) > K) startPos++;
                ans += endPos - startPos + 1;
                endPos++;
            }
        else startPos = endPos = i;    
    }
    printf("%lld\n", ans);

    return 0;
}                                 
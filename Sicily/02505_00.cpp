// Problem#: 2505
// Submission#: 3549439
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

long long tot, ave;
int sum[1000005], a[1000005];
int N;

inline long long ABS(long long a) {
    if (a < 0) return -a;
    return a;
}

int main() {

    scanf("%d\n", &N);
    char text[30];
    int s = 0;
    for (int i = 1; i <= N; i++) {
        gets(text);
        for (int j = 0; text[j] != '\0'; j++) s = s * 10 + text[j] - '0';
        a[i] = s;
        s = 0;
        tot += a[i];
    }
    ave = tot / N;
    for (int i = 1; i < N; i++) sum[i] = a[i] + sum[i - 1] - ave;
    sort(sum + 1, sum + N);
    long long median = sum[N / 2];
    long long ans = abs(median);
    for (int i = 1; i < N; i++) ans += abs(sum[i] - median);
    printf("%lld\n", ans);

    return 0;
}                                 
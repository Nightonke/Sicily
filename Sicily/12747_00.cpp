// Problem#: 12747
// Submission#: 3549626
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

struct cow {
    int id, pos;
}c[50005];

bool cmp(const cow & c1, const cow & c2) {
    if (c1.id != c2.id) return c1.id < c2.id;
    else return c1.pos < c2.pos;
}

int main() {

    int N, K, temp;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        c[i].pos = i;
        c[i].id = temp;
    }
    sort(c, c + N, cmp);
    int ans = -1;
    for (int i = 1; i < N; i++) {
        if (c[i].id == c[i - 1].id && c[i].pos - c[i - 1].pos <= K && c[i].id > ans) ans = c[i].id;
    }
    printf("%d\n", ans);

    return 0;
}                                 
// Problem#: 1088
// Submission#: 3410083
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <math.h>
#include <list>
using namespace std;

const int MAX = 100005;

struct range {
    int s, e, id;
};

int N;
range ori[MAX];
int C[MAX];
int ans[MAX];

inline bool cmp(const range & ra1, const range & ra2) {
    if (ra1.e != ra2.e) return ra1.e < ra2.e;
    else return ra1.s > ra2.s;
}

inline int Lowbit(int m) {return m & (-m);}

inline int Getsum(int k) {
    int sum = 0;
    while (k > 0) {
        sum += C[k];
        k -= Lowbit(k);
    }
    return sum;
}

inline void Change(int k, int m, int n) {
    while (k <= n) {
        C[k] += m;
        k += Lowbit(k);
    }
}

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {

        scanf("%d", &N);
        if (!N) break;
        int maxS = -1;
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &ori[i].s, &ori[i].e);
            ori[i].id = i;
            ori[i].s++;
            ori[i].e++;
            if (ori[i].s > maxS) maxS = ori[i].s;
        }
        sort(ori, ori + N, cmp);
        memset(C, 0, sizeof(int) * (maxS + 1));
        for (int i = N - 1; i >= 0; i--) {
            if (i != N - 1 && ori[i].e == ori[i + 1].e && ori[i].s == ori[i + 1].s)
                ans[ori[i].id] = ans[ori[i + 1].id];
            else
                ans[ori[i].id] = Getsum(ori[i].s);
            Change(ori[i].s, 1, maxS);
        }
        for (int i = 0; i < N; i++) printf("%d\n", ans[i]);
    }

    return 0;
}                                 
// Problem#: 1025
// Submission#: 3223309
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

#define MAX 10005

struct posAndVal {
    int p;
    int v;
};

int N;
posAndVal x[MAX];
posAndVal y[MAX];
int val[MAX];
long long valFrontSum[MAX];
long long valBackSum[MAX];
long long xvalFrontSum[MAX];
long long xvalBackSum[MAX];
long long yvalFrontSum[MAX];
long long yvalBackSum[MAX];

bool cmp(const posAndVal & a, const posAndVal & b) {
    return a.p < b.p;
}

void initX() {
    int i;
    for (i = 1, valFrontSum[0] = 0; i < N; i++) {
        valFrontSum[i] = valFrontSum[i - 1] + x[i - 1].v;
    }
    for (i = N - 2, valBackSum[N - 1] = 0; i >= 0; i--) {
        valBackSum[i] = valBackSum[i + 1] + x[i + 1].v;
    }
    for (i = 1, xvalFrontSum[0] = 0; i < N; i++) {
        xvalFrontSum[i] = xvalFrontSum[i - 1] + valFrontSum[i] * (x[i].p - x[i - 1].p);
    }
    for (i = N - 2, xvalBackSum[N - 1] = 0; i >= 0; i--) {
        xvalBackSum[i] = xvalBackSum[i + 1] + valBackSum[i] * (x[i + 1].p - x[i].p);
    }
}

void initY() {
    int i;
    for (i = 1, valFrontSum[0] = 0; i < N; i++) {
        valFrontSum[i] = valFrontSum[i - 1] + y[i - 1].v;
    }
    for (i = N - 2, valBackSum[N - 1] = 0; i >= 0; i--) {
        valBackSum[i] = valBackSum[i + 1] + y[i + 1].v;
    }
    for (i = 1, yvalFrontSum[0] = 0; i < N; i++) {
        yvalFrontSum[i] = yvalFrontSum[i - 1] + valFrontSum[i] * (y[i].p - y[i - 1].p);
    }
    for (i = N - 2, yvalBackSum[N - 1] = 0; i >= 0; i--) {
        yvalBackSum[i] = yvalBackSum[i + 1] + valBackSum[i] * (y[i + 1].p - y[i].p);
    }
}

long long findMin() {
    initX();
    long long minAns = -1;
    long long ans;
    for (int i = 0; i < N; i++) {
        long long temp = xvalFrontSum[i] + xvalBackSum[i];
        if (minAns == -1 || minAns > temp) minAns = temp;
    }
    ans = minAns;
    minAns = -1;
    initY();
    for (int i = 0; i < N; i++) {
        long long temp = yvalFrontSum[i] + yvalBackSum[i];
        if (minAns == -1 || temp < minAns) minAns = temp;
    }
    ans += minAns;
    return ans;
}

int main() {

    //std::ios::sync_with_stdio(false);

    while (scanf("%d", &N) != EOF) {

        for (int i = 0; i < N; i++) cin >> val[i];
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &x[i].p, &y[i].p);
            x[i].v = y[i].v = val[i];
        }

        if (N == 1) {
            printf("0.00\n");
            continue;
        }

        sort(x, x + N, cmp);
        sort(y, y + N, cmp);
        printf("%lld.00\n", findMin());
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
// Problem#: 13291
// Submission#: 3520549
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
#include <set>
using namespace std;

const int MAX_N = 100005;

int record_b[MAX_N], record_c[MAX_N];
long long ansb[MAX_N], ansc[MAX_N];
int N;
int num[MAX_N];

int main() {

    //std::ios::sync_with_stdio(false);

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &num[i]);

    for (int i = 1; i <= N; i++) {
        bool found = false;
        for (int j = i - 1; j > 0; j--) {
            if (num[j] % num[i] == 0) {
                ansb[i] = num[j];
                found = true;
                break;
            }
        }
        if (!found) ansb[i] = num[i];
    }

    for (int i = N; i > 0; i--) {
        bool found = false;
        for (int j = i + 1; j <= N; j++) {
            if (num[j] % num[i] == 0) {
                ansc[i] = num[j];
                found = true;
                break;
            }
        }
        if (!found) ansc[i] = num[i];
    }

    long long int ans = 0;
    for (int i = 1; i <= N; i++) ans += ansb[i] * ansc[i];
    printf("%lld\n", ans);

    return 0;
}                                 
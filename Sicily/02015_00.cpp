// Problem#: 2015
// Submission#: 3370598
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
using namespace std;

char text[10000];

int main() {

    //std::ios::sync_with_stdio(false);

    int N, M, num[1005], ans;

    while (scanf("%d", &N) && N) {
        gets(text);
        gets(text);
        int cal = 0;
        int p = 0;
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] == ' ') {
                num[p++] = cal;
                cal = 0;
            } else {
                cal = cal * 10 + text[i] - '0';
            }
        }
        num[p] = cal;
        int S = 0;
        for (int i = 0; i < N; i++) S += num[i];
        scanf("%d", &M);
        int L = 0, B = S;
        while (L <= B) {
            int mid = (L + B) / 2;
            int sum = 0;
            for (int i = 0; i < N; i++) sum += min(mid, num[i]);
            if (M * mid > sum) B = mid - 1;
            else {
                L = mid + 1;
                ans = mid;
            }
        }
        printf("%d\n", ans);
    }

    //cin >> N;

    return 0;
}                                 
// Problem#: 1376
// Submission#: 3384776
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
using namespace std;

const int MAX_N = 100005;

int n[MAX_N];
int N, M;

inline bool isOK(int mid) {
    int m = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        if (sum + n[i] <= mid) sum += n[i];
        else {
            m++;
            sum = n[i];
            if (sum > mid || m > M) return false;
        }
    }
    return m + 1 <= M;
}

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {
        cin >> N >> M;
        if (cin.eof()) break;
        int maxL = N - (M - 1);
        int low = 10001, high = 0, mid;
        for (int i = 0; i < N; i++) {
            cin >> n[i];
            if (n[i] < low) low = n[i];
        }
        for (int i = 0; i < maxL; i++) high += n[i];
        int l, r;
        for (l = 0, r = maxL; r < N; r++, l++) {
            if (high - n[l] + n[r] > high) high = high - n[l] + n[r];
        }
        while (low < high) {
            mid = (low + high) / 2;
            if (isOK(mid)) high = mid;
            else low = mid + 1;
        }
        cout << high << endl;
    }

    return 0;
}                                 
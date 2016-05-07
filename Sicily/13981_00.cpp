// Problem#: 13981
// Submission#: 3681917
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[1005];
int ans = 0;

int binarySearchIncreaseLastSmaller(int l, int r, int target) {  // 在不下降的序列中寻找恰好比target小于等于的数出现位置，也即最后一个比target小于等于的数出现的位置
    if (n == 0) return -1;
    while (l < r - 1) {
        int m = l + ((r - l) >> 1);
        if (num[m] <= target) l = m;
        else r = m - 1;
    }
    if (num[r] <= target) return r;
    else if (num[l] <= target) return l;
    else return n;
}

int binarySearchIncreaseFirstBigger(int l, int r, int target) {  // 在不下降的序列中寻找恰好比target大于等于的数出现位置，也即第一个比target大于等于的数出现的位置
    if (n == 0) return -1;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (num[m] < target) l = m + 1;
        else r = m;
    }
    if (num[r] >= target) return r;
    else return -1;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int lowerBound = 2 * num[j] - num[i];
            int upperBound = lowerBound + (num[j] - num[i]);
            int ls = binarySearchIncreaseLastSmaller(j + 1, n - 1, upperBound);
            if (ls >= n) continue;
            int fb = binarySearchIncreaseFirstBigger(j + 1, n - 1, lowerBound);
            if (fb <= j) break;
            ans += ls - fb + 1;
        }
    }
    cout << ans << endl;

    return 0;
}                                 
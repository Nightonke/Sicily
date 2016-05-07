// Problem#: 13983
// Submission#: 3681817
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

struct cow {
    int g, d;
    cow(int g = 0, int d = 0) {
        this->g = g;
        this->d = d;
    }
};

bool cmp(const cow & c1, const cow & c2) {
    if (c1.g == c2.g) return c1.d < c2.d;
    else return c1.g > c2.g;
}

cow c[10005];
bool used[10005];

int haveTime(int d) {
    for (int i = d; i > 0; i--) if (!used[i]) return i;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i].g >> c[i].d;
    sort(c, c + n, cmp);
    int t = 4, ans = 0;
    for (int i = 0; i < n; i++) {
        int feedDay = haveTime(c[i].d);
        if (feedDay) {
            used[feedDay] = true;
            ans += c[i].g;
        }
    }
    cout << ans << endl;

    return 0;
}                                 
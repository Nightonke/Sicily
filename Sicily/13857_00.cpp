// Problem#: 13857
// Submission#: 3620020
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int n;

inline bool is_closed(int & a, int & b) {
    if (a < b) {
        return b - a <= 2 || a + n - b <= 2;
    } else {
        return a - b <= 2 || b + n - a <= 2;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, c, d, e, f, ans = 0;
    cin >> n >> a >> b >> c >> d >> e >> f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if ((is_closed(a, i) && is_closed(b, j) && is_closed(c, k)) || (is_closed(d, i) && is_closed(e, j) && is_closed(f, k))) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}                                 
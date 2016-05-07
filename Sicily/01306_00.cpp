// Problem#: 1306
// Submission#: 2590399
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m, i, a[100001];
    while (cin >> n >> m && n != 0) {
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << a[0];
        for (i = m; i < n; i = i + m) {
            cout << ' ' << a[i];
        }
        cout << endl;
    }
    return 0;
}                                 
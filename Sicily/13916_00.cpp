// Problem#: 13916
// Submission#: 3638792
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, min_x = 101, min_y = 101, max_x = 0, max_y = 0;
    cin >> n;
    while (n--) {
        int tx, ty;
        cin >> tx >> ty;
        min_x = min(tx, min_x);
        max_x = max(tx, max_x);
        min_y = min(ty, min_y);
        max_y = max(ty, max_y);
    }
    cout << max(max_x - min_x, max_y - min_y) * max(max_x - min_x, max_y - min_y) << endl;
    return 0;
}                                 
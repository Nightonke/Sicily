// Problem#: 14261
// Submission#: 3672490
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;
    
    while (caseNum--) {
        int n, m = 0, ans = 1;
        string a, b;
        cin >> n >> a >> b;
        bool isOK['z' + 1];
        for (int i = 'a'; i <= 'z'; i++) isOK[i] = false;
        for (int i = a.size() - 1; i >= 0; i--) isOK[a[i]] = true;
        for (int i = b.size() - 1; i >= 0; i--) isOK[b[i]] = false;
        for (int i = 'a'; i <= 'z'; i++) if (isOK[i]) m++;
        for (int i = 0; i < n; i++, ans %= 1007) ans *= m;
        cout << ans << endl;
    }

    return 0;
}                                 
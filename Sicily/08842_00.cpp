// Problem#: 8842
// Submission#: 3544131
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<string, int> m;
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        m[temp] = i;
    }
    int pos[2505];
    for (int i = 0; i < N; i++) {
        cin >> temp;
        pos[i] = m[temp];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (pos[i] < pos[j]) ans++;
        }
    }
    cout << ans << '/' << N * (N - 1) / 2 << endl;

    return 0;
}                                 
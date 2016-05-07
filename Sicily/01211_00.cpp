// Problem#: 1211
// Submission#: 2725788
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

int dp[105][105][105];

struct connect{
    int sp, ep;
}is_connected[10500];

void dping(int max_cities, int max_days, int max_connect) {
    int i, j, k;
    for (i = 2; i <= max_days; i++) {
        for (j = 1; j <= max_cities; j++) {
            for (k = 0; k < max_connect; k++) {
                dp[i][j][is_connected[k].ep] += dp[i - 1][j][is_connected[k].sp];
            }
        }
    }
}

int main() {
    int i, n, m, l, a, b, num_connect;
    cin >> n >> m >> l;
    
    num_connect = m;
    for (i = 0; i < m; i++) {
        cin >> is_connected[i].sp >> is_connected[i].ep;
        dp[1][is_connected[i].sp][is_connected[i].ep] = 1;
    }
    cin >> m;
    dping(n, l, num_connect);
    while (m--) {
        cin >> a >> b;
        cout << dp[l][a][b] << endl;
    }
    return 0;
}                                 
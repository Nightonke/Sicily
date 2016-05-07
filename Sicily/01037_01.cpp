// Problem#: 1037
// Submission#: 2723574
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

char words[605][11];
bool is_i_after_j[605][605];
int num[605][605];

void is_i_connect_j(int m, int each_length) {
    int j, i, k;
    bool is_connect;
    memset(is_i_after_j, false, sizeof(is_i_after_j));
    for (j = 0; j < m; j++) {
        for (i = 0; i < m; i++) {
            is_connect = true;
            for (k = 1; k < each_length; k++) {
                if (words[i][k - 1] != words[j][k]) {
                    is_connect = false;
                    break;
                }
            }
            if (is_connect)
                is_i_after_j[j][i] = true;
        }
    }
}

int dp(int max_num, int m) {
    int i, k, j, ans;
    memset(num, 0, sizeof(num));
    for (i = 0; i < m; i++) {
        num[1][i] = 1;
    }
    for (k = 2; k <= max_num; k++) {
        for (j = 0; j < m; j++) {
            for (i = 0; i < m; i++) {
                if (is_i_after_j[j][i])
                    num[k][i] += num[k - 1][j];
            }
        }
    }
    for (ans = 0, i = 0; i < m; i++) {
        ans += num[max_num][i];
    }
    return ans;
}

int main() {
    int m, l, n, i, each_length, max_num;
    while (cin >> n >> l >> m, n) {
        memset(words, '\0', sizeof(words));
        for (i = 0; i < m; i++) {
            cin >> words[i];
        }
        each_length = strlen(words[0]);
        is_i_connect_j(m, each_length);
        max_num = l - each_length + 1;
        cout << dp(max_num, m) << endl;
    }
    return 0;
}                                 
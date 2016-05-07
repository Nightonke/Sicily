// Problem#: 1822
// Submission#: 3342033
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

const long long MOD = 1000000007;

int main() {

    //std::ios::sync_with_stdio(false);

    int caseNum;
    scanf("%d\n", &caseNum);

    while (caseNum--) {
        int N;
        char f[45][45];
        bool dp[100][100];
        scanf("%d\n", &N);
        for (int i = 0; i < N; i++) {
            char temp[100];
            gets(temp);
            for (int j = 0; j < N; j++) f[i][j] = temp[2 * j];;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 2 * N; i++) dp[i][i + 1] = 1;
        for (int l = 2; l <= N; l++) {
            for (int i = 0; i + l < 2 * N; i++) {
                for (int j = i + 1; j < i + l; j++) {
                    if (dp[i][j] && dp[j][i + l]) {
                        int x = (i + N) % N;
                        int y = (j + N) % N;
                        int z = (i + l + N) % N;
                        if (f[x][y] == '1' || f[z][y] == '1') dp[i][l + i] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) printf("%d\n", dp[i][i + N]);
        printf("\n");
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
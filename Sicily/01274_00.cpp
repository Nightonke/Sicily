// Problem#: 1274
// Submission#: 3014392
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
using namespace std;

#define MAX_WIDTH 50

struct p {
    int ii;
    int jj;
    p() {}
    p(int i, int j) {
        ii = i;
        jj = j;
    }
};

long long int way[MAX_WIDTH][MAX_WIDTH];
int step[MAX_WIDTH][MAX_WIDTH];
bool vis[MAX_WIDTH][MAX_WIDTH];

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {

        int n;

        cin >> n;

        if (n == -1) break;

        for (int i = 0; i < n; i++) {

            string s;

            cin >> s;

            for (int j = 0; j < n; j++) {

                step[i][j] = s[j] - '0';

            }

        }

        memset(way, 0, sizeof(way));
        way[0][0] = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (step[i][j] == 0) continue;

                int next_i = i + step[i][j], next_j = j + step[i][j];

                if (next_i < n) {
                    
                    way[next_i][j] += way[i][j];

                }

                if (next_j < n) {
                    
                    way[i][next_j] += way[i][j];

                }

            }

        }

        cout << way[n - 1][n - 1] << endl;

    }

    //getchar();
    //getchar();
    return 0;
}                                 
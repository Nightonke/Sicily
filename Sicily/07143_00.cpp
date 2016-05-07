// Problem#: 7143
// Submission#: 2751841
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string.h>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stack>
#include <math.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        char dir[35] = {0};
        long long i_min = 0, j_min = 0, i_max, j_max;
        scanf("%d %s", &n, dir);
        i_max = (long long)pow(2, n) - 1;
        j_max = (long long)pow(2, n) - 1;
        for (int i = 0; i < n; i++) {
            if (dir[i] == '0') {
                i_max = i_min + (i_max - i_min) / 2;
                j_max = j_min + (j_max - j_min) / 2;
            } else if (dir[i] == '1') {
                i_max = i_min + (i_max - i_min) / 2;
                j_min = j_max - (j_max - j_min) / 2;
            } else if (dir[i] == '2') {
                i_min = i_max - (i_max - i_min) / 2;
                j_max = j_min + (j_max - j_min) / 2;
            } else {
                i_min = i_max - (i_max - i_min) / 2;
                j_min = j_max - (j_max - j_min) / 2;
            }
        }
        printf("%lld %lld\n", i_min, j_min);
    }
    return 0;
}                                 
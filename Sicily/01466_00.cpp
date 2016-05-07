// Problem#: 1466
// Submission#: 3316720
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
using namespace std;

const int MAX_N = 10000;

int main() {

    //std::cout.sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    double xy[MAX_N][2];
    char temp;
    for (int i = 0; i < n; i++) {
        scanf("%lf%c%lf", &xy[i][0], &temp, &xy[i][1]);
    }
    double ans = 0;
    for (int i = 1; i < n; i++) ans += (xy[i][1] + xy[i - 1][1]) * (xy[i][0] - xy[i - 1][0]) / 2;
    printf("%.2lf to %.2lf: %.4lf\n", xy[0][0], xy[n - 1][0], ans);

    return 0;
}                                 
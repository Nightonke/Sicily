// Problem#: 1004
// Submission#: 3135831
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

#define MAX 10005
#define DEV 1e-6
#define INF 99999

vector<double> line[MAX];  // k, b, x1, y1, x2, y2, x1 <= x2

inline bool doubleIsSame(double a, double b) {
    return fabs(a - b) < DEV;
}

bool cmp(vector<double> a, vector<double> b) {
    if (!doubleIsSame(a[0], b[0])) return a[0] < b[0];
    else {
        if (a[0] == INF) {
            if (!doubleIsSame(a[1], b[1])) return a[1] < b[1];
            if (!doubleIsSame(a[3], b[3])) return a[3] < b[3];
            return a[5] < b[5];
        } else {
            if (!doubleIsSame(a[1], b[1])) return a[1] < b[1];
            if (!doubleIsSame(a[2], b[2])) return a[2] < b[2];
            return a[4] < b[4];
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        for (int i = 0; i < n; i++) {
            line[i].resize(6);
            double x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2 || (x1 == x2 && y1 > y2)) {
                swap(x1, x2);
                swap(y1, y2);
            }
            line[i][2] = x1;
            line[i][3] = y1;
            line[i][4] = x2;
            line[i][5] = y2;
            if (x1 != x2) {
                line[i][0] = (y2 - y1) / (x2 - x1);
                line[i][1] = y1 - line[i][0] * x1;
            } else {
                line[i][0] = INF;
                line[i][1] = x1;
            }
        }
        sort(line, line + n, cmp);
        int ans = 1;
        double x = line[0][4], y = line[0][5];
        for (int i = 1; i < n; i++) {
            if (!doubleIsSame(line[i][0], line[i - 1][0]) || !doubleIsSame(line[i][1], line[i - 1][1])) {
                ans++;
                x = line[i][4];
                y = line[i][5];
            } else if ((line[i][0] != INF && x < line[i][2]) || (line[i][0] == INF && y < line[i][3])) {
                ans++;
                x = line[i][4];
                y = line[i][5];
            } else if ((line[i][0] != INF && x < line[i][4]) || (line[i][0] == INF && y < line[i][5])) {
                x = line[i][4];
                y = line[i][5];
            }
        }
        cout << ans << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
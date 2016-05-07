// Problem#: 1693
// Submission#: 3420596
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <math.h>
#include <list>
using namespace std;

const int MAX_N = 55;

const int d[3][3] = {0, 0, 1, 0, 1, 0, 1, 0, 0};
int n[17];
bool cube[3][3][3];

bool isOK(int x, int y, int z) {
    return 0 <= x && x < 3 && 0 <= y && y < 3 && 0 <= z && z < 3 && !cube[x][y][z];
}

bool search(int x, int y, int z, int dir, int flag, int step) {
    if (step >= 17) return true;
    int tx = x, ty = y, tz = z, i, k;
    for (k = 1; k < n[step]; k++) {
        tx += flag * d[dir][0];
        ty += flag * d[dir][1];
        tz += flag * d[dir][2];
        if (!isOK(tx, ty, tz)) break;
    }
    if (k < n[step]) return false;
    else {
        tx = x;
        ty = y;
        tz = z;
        for (k = 1; k < n[step]; k++) {
            tx += flag * d[dir][0];
            ty += flag * d[dir][1];
            tz += flag * d[dir][2];
            cube[tx][ty][tz] = true;
        }
        if (search(tx, ty, tz, (dir + 1) % 3, 1, step + 1) || search(tx, ty, tz, (dir + 1) % 3, -1, step + 1) || search(tx, ty, tz, (dir + 2) % 3, 1, step + 1) || search(tx, ty, tz, (dir + 2) % 3, -1, step + 1)) return true;
        tx = x;
        ty = y;
        tz = z;
        for (k = 1; k < n[step]; k++) {
            tx += flag * d[dir][0];
            ty += flag * d[dir][1];
            tz += flag * d[dir][2];
            cube[tx][ty][tz] = 0;
        }
        return false;
    }
}

bool check(int x, int y, int z, int dir, int flag) {
    memset(cube, false, sizeof(cube));
    cube[x][y][z] = true;
    return search(x, y, z, dir, flag, 0);
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int sum = 0;
        for (int i = 0; i < 17; i++) {
            cin >> n[i];
            sum += n[i];
        }
        if (sum == 43 && (check(0, 0, 0, 0, 1) || check(1, 0, 1, 0, 1) || check(1, 0, 1, 1, 1))) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}                                 
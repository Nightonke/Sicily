// Problem#: 1005
// Submission#: 3149112
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

#define MAX_SUM 1100

int d[25][MAX_SUM];  // d[i][j]表示当有i个骰子时和为j的方案数
int require[15][2];  // require[i][0]表示要求的第i个和，require[i][1]表示这个和的次数
int ans[15];  // 存放答案数组
int n;  // 已经有n个骰子已知
int r;  // 要求的和的个数
int f;  // 未知的骰子的面数
bool possible;  // 在深搜之前判断求出解的可能性
bool found;  // 深搜是否找到了解
int Min;  // 前n个骰子的和的最小值
int Max;  // 前n个骰子的和的最大值

void make() {
    memset(d, 0, sizeof(d));
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        d[1][temp] += 1;  // 这里原本写的是d[1][temp] = 1，结果WA了好久，因为骰子的面有可能有相同值
    }
    for (int i = 2; i <= n; i++) {  // 利用动态规划先求出n个骰子的和的方案数情况
        cin >> m;
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            for (int k = 0; k < MAX_SUM; k++) {
                if (d[i - 1][k] != 0) {
                    d[i][k + temp] += d[i - 1][k];  // 第i个骰子和为k+temp的方案数等于第i-1个骰子和为k的方案数的总和
                }
            }
        }
    }
    cin >> f;
    cin >> r;
    for (int i = 0; i < r; i++) {
        cin >> require[i][0] >> require[i][1];
    }
    for (int i = 0; i < MAX_SUM; i++) {
        if (d[n][i]) {
            Min = i;
            break;
        }
    }
    for (int i = MAX_SUM - 1; i >= 0; i--) {
        if (d[n][i]) {
            Max = i;
            break;
        }
    }
    for (int i = 0; i < r; i++) {  // 如果要求的和比前n个骰子所能达到的最大和+50（第n+1个骰子的最大值）还大，则不可能
        if (require[i][1] != 0 && require[i][0] > Max + 50) {
            possible = false;
            return;
        }
    }
}

void DFS(int pos, int last) {

    if (pos == f) {
        for (int i = 0; i < r; i++) {
            if (require[i][1] != 0) return;
        }
        found = true;
        return;
    }
    // 这里深搜的剪枝非常巧妙
    for (int i = last; i <= 50; i++) {
        for (int j = 0; j < r; j++) {
            if (require[j][1] != 0 && Min + i > require[j][0]) return;  // 如果第j个要求的和还有次数（因为在此前的深搜次数会减少）并且前n个骰子的最小和+i（第n+1个骰子的可能值）大于第j个要求的和，由于此后的骰子的可能值必然大于等于i，所以不可能，则返回
        }
        ans[pos] = i;
        bool goOn = true;
        for (int j = 0; j < r; j++) {
            if (require[j][0] - i > 0) {
                require[j][1] -= d[n][require[j][0] - i];
                if (require[j][1] < 0) goOn = false;  // 注意方案数是刚刚好，多一个少一个都不行
            }
        }
        if (goOn) DFS(pos + 1, i);
        if (found) return;
        for (int j = 0; j < r; j++) {  // 如果此方向深搜失败还原
            if (require[j][0] - i > 0) {
                require[j][1] += d[n][require[j][0] - i];
            }
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> n;
        if (!n) break;
        possible = true;
        found = false;
        make();
        if (possible) DFS(0, 1);
        if (possible && found) {
            cout << "Final die face values are";
            for (int i = 0; i < f; i++) {
                cout << " " << ans[i];
            }
            cout << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
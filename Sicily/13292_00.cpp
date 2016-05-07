// Problem#: 13292
// Submission#: 3520300
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
#include <set>
using namespace std;

int record[5];
double ansMax, ansMin;
int minScore[5] = {60, 70, 75, 80, 85};
int cScore[5] = {9, 4, 4, 4, 15};
double GPAi[5] = {2.0, 2.5, 3.0, 3.5, 4.0};
int n;

inline bool canComplete(int rest) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        if (record) {
            rest -= cScore[i] * record[i];
            sum += record[i];
        }
    }
    return rest <= 0 && sum == n;
}

inline double cal() {
    double d = 0;
    for (int i = 0; i < 5; i++) d += GPAi[i] * record[i];
    return d / n;
}

void dfs(int pos, int rest) {
    if (pos == 5) {
        if (canComplete(rest)) {
            double newAns = cal();
            ansMax = (newAns > ansMax ? newAns : ansMax);
            ansMin = (newAns < ansMin ? newAns : ansMin);
            return;
        }
        return;
    }
    for (int i = 0; i * minScore[pos] <= rest; i++) {
        int temp = record[pos];
        record[pos] = i;
        dfs(pos + 1, rest - i * minScore[pos]);
        record[pos] = temp;
    }
}

int main() {

    //std::ios::sync_with_stdio(false);

    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        int aver;
        scanf("%d%d", &aver, &n);
        memset(record, 0, sizeof(record));
        ansMax = -1;
        ansMin = 100000000;
        dfs(0, aver * n);
        printf("%.4lf %.4lf\n", ansMin, ansMax);
    }

    return 0;
}                                 
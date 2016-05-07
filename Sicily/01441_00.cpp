// Problem#: 1441
// Submission#: 3311152
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
using namespace std;

const double ERR = 0.001;
const int MAX_N = 10005;
const double PI = 3.14159265358979323846;

int N, F;
double v[MAX_N];
int r[MAX_N];

bool possible(double now) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        int j;
        for (j = 1; j * now <= v[i]; j++);
        counter += j - 1;
        if (counter >= F) return true;
    }
    return false;
}

int main() {

    //std::cout.sync_with_stdio(false);

    int caseNum;
    scanf("%d", &caseNum);

    while (caseNum--) {
        scanf("%d%d", &N, &F);
        double maxPie = -1;
        for (int i = 0; i < N; i++) {
            scanf("%d", &r[i]);
            v[i] = PI * r[i] * r[i];
            maxPie = max(maxPie, v[i]);
        }

        F++;
        sort(v, v + N);
        double low = 0, high = maxPie;

        while (high - low >= ERR) {
            double mid = (high + low) / 2;
            if (possible(mid)) low = mid;
            else high = mid;
        }

        printf("%.4lf\n", low);


    }


    return 0;
}                                 
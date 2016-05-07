// Problem#: 1526
// Submission#: 3462177
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

const double PI = 3.14159265358979323846264338327950288;

double angel2PI(double a) {
    return PI * a / 180;
}

struct treDPoint {
    double x, y, z;
    treDPoint(double xx = 0, double yy = 0, double zz = 0) {
        x = xx;
        y = yy;
        z = zz;
    }
};

bool judge(double Aea, double Bea, double Aaa, double Baa) {
    return 0 < Aea && Aea < 90 && 0 < Bea && Bea < 90 && 0 < Aaa && Aaa < 90 && 90 < Baa && Baa < 180;
}

double dis(treDPoint M, treDPoint N) {
    return sqrt((M.x - N.x) * (M.x - N.x) + (M.y - N.y) * (M.y - N.y) + (M.z - N.z) * (M.z - N.z));
}

int main() {

    //std::ios::sync_with_stdio(false);
    
    int caseNum;
    scanf("%d", &caseNum);
    int counter = 1;

    treDPoint A, B;
    double d, l, Ha, Hb, eD;

    scanf("%lf%lf%lf%lf%lf", &d, &l, &A.z, &B.z, &eD);
    A.x = -d / 2;
    B.x = d / 2;

    while (caseNum--) {
        double Aea, Bea, Aaa, Baa;
        scanf("%lf%lf%lf%lf", &Aea, &Bea, &Aaa, &Baa);
        if (!judge(Aea, Bea, Aaa, Baa)) {
            printf("%d DISQUALIFIED\n", counter);
            counter++;
            continue;
        }

        double x = (d / 2 * (tan(angel2PI(180 - Baa)) - tan(angel2PI(Aaa)))) / (tan(angel2PI(Aaa)) + tan(angel2PI(180 - Baa)));
        double y = x * tan(angel2PI(Aaa)) + d / 2 * tan(angel2PI(Aaa));
        double z = 0;
        treDPoint floorPoint(x, y, z);
        double h1 = tan(angel2PI(Aea)) * dis(floorPoint, treDPoint(A.x, A.y, 0));
        double h2 = tan(angel2PI(Bea)) * dis(floorPoint, treDPoint(B.x, A.y, 0));
        h1 += A.z;
        h2 += B.z;

        if (fabs(h1 - h2) > eD) {
            printf("%d ERROR\n", counter);
            counter++;
            continue;
        }

        printf("%d %.0lf\n", counter, (h1 + h2) / 2);
        counter++;
    }

    return 0;
}                                 
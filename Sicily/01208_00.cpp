// Problem#: 1208
// Submission#: 3461283
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

const double ERR = 0.000001;
const double PI = 3.14159265358979323846264338327950288;

inline bool isSame(double d1, double d2) {
    return fabs(d1 - d2) < ERR;
}

double angel2PI(double a) {
    return PI / 180 * a;
}

struct treDPoint {
    double x, y, z;
    treDPoint(double xx = 0, double yy = 0, double zz = 0) {
        x = xx;
        y = yy;
        z = zz;
    }
};

treDPoint getP(treDPoint A, treDPoint B,  treDPoint C, treDPoint D) {
    double H = B.x - A.x;
    double I = B.y - A.y;
    double J = B.z - A.z;
    double K = D.x - C.x;
    double L = D.y - C.y;
    double M = D.z - C.z;
    double N = H * I * L - I * I * K - J * J * K + H * J * M;
    double O = H * H * L - H * I * K - I * J * M + J * J * L;
    double P = H * J * K - H * H * M - I * I * M + I * J * L;
    double Q = -A.x * N + A.y * O - A.z * P;
    double k = (O * C.y - N * C.x - P * C.z - Q) / (N * K - O * L + P * M);
    return treDPoint(K * k + C.x, L * k + C.y, M * k + C.z);
}

int main() {

    //std::ios::sync_with_stdio(false);
    
    int caseNum;
    scanf("%d", &caseNum);
    int counter = 1;

    treDPoint A(-50, 0), B(50, 0), C, D;

    scanf("%lf%lf", &A.z, &B.z);

    while (caseNum--) {
        double Aea, Bea, Aaa, Baa;
        scanf("%lf%lf%lf%lf", &Aea, &Bea, &Aaa, &Baa);
        C.x = 1 + A.x;
        C.y = tan(angel2PI(Aaa)) + A.y;
        C.z = tan(angel2PI(Aea)) / cos(angel2PI(Aaa)) + A.z;
        D.x = -1 + B.x;
        D.y = tan(angel2PI(180 - Baa)) + B.y;
        D.z = tan(angel2PI(Bea)) / cos(angel2PI(180 - Baa)) + B.z;
        
        treDPoint M = getP(A, C, B, D);
        treDPoint N = getP(B, D, A, C);

        printf("%d: %.0lf\n", counter, (M.z + N.z) / 2);
        counter++;
    }

    return 0;
}                                 
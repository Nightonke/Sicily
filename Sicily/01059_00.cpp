// Problem#: 1059
// Submission#: 3460143
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

inline double dis(double ax, double ay, double bx, double by) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

inline bool isSame(double d1, double d2) {
    return fabs(d1 - d2) < ERR;
}

int main() {

    //std::ios::sync_with_stdio(false);
    
    int caseNum;
    scanf("%d", &caseNum);

    while (caseNum--) {
        pair<double, double> A, B, C, D, G, E, J, L, M, O;
        scanf("%lf%lf%lf%lf%lf%lf", &A.first, &A.second, &B.first, &B.second, &C.first, &C.second);

        //for D
        bool KabExist = (!isSame(B.first, A.first));
        double Kab;
        if (KabExist) {  // Kab exist
            Kab = (B.second - A.second) / (B.first - A.first);
            if (isSame(Kab, 0)) {  // Kad does not exist
                D.first = A.first;
                double p1, p2;
                p1 = A.second + fabs(B.first - A.first);
                p2 = A.second - fabs(B.first - A.first);
                if (dis(D.first, p1, C.first, C.second) > dis(D.first, p2, C.first, C.second)) D.second = p1;
                else D.second = p2;
            } else {  // Kad exist
                double Kad = -1 / Kab;
                double Bad = A.second - A.first * Kad;
                double a = Kad * Kad + 1;
                double b = 2 * Kad * Bad - 2 * A.second * Kad - 2 * A.first;
                double c = A.first * A.first + A.second * A.second - 2 * A.second * Bad + Bad * Bad - dis(A.first, A.second, B.first, B.second) * dis(A.first, A.second, B.first, B.second);
                double p1, p2;
                p1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                p2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                if (dis(p1, Kad * p1 + Bad, C.first, C.second) > dis(p2, Kad * p2 + Bad, C.first, C.second)) D.first = p1;
                else D.first = p2;
                D.second = Kad * D.first + Bad;
            }
        } else {
            D.second = A.second;
            double p1, p2;
            p1 = A.first + dis(A.first, A.second, B.first, B.second);
            p2 = A.first - dis(A.first, A.second, B.first, B.second);
            if (dis(p1, D.second, C.first, C.second) > dis(p2, D.second, C.first, C.second)) D.first = p1;
            else D.first = p2;
        }
        
        // for G
        bool KacExist = (!isSame(C.first, A.first));
        double Kac;
        if (KacExist) {  // Kac exist
            Kac = (C.second - A.second) / (C.first - A.first);
            if (isSame(Kac, 0)) {  // Kag does not exist
                G.first = A.first;
                double p1, p2;
                p1 = A.second + fabs(C.first - A.first);
                p2 = A.second - fabs(C.first - A.first);
                if (dis(G.first, p1, B.first, B.second) > dis(G.first, p2, B.first, B.second)) G.second = p1;
                else G.second = p2;
            } else {  // Kag exist
                double Kag = -1 / Kac;
                double Bag = A.second - A.first * Kag;
                double a = Kag * Kag + 1;
                double b = 2 * Kag * Bag - 2 * A.second * Kag - 2 * A.first;
                double c = A.first * A.first + A.second * A.second - 2 * A.second * Bag + Bag * Bag - dis(A.first, A.second, C.first, C.second) * dis(A.first, A.second, C.first, C.second);
                double p1, p2;
                p1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                p2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                if (dis(p1, Kag * p1 + Bag, B.first, B.second) > dis(p2, Kag * p2 + Bag, B.first, B.second)) G.first = p1;
                else G.first = p2;
                G.second = Kag * G.first + Bag;
            }
        } else {
            G.second = A.second;
            double p1, p2;
            p1 = A.first + dis(A.first, A.second, C.first, C.second);
            p2 = A.first - dis(A.first, A.second, C.first, C.second);
            if (dis(p1, G.second, B.first, B.second) > dis(p2, G.second, B.first, B.second)) G.first = p1;
            else G.first = p2;
        }

        // for E
        KabExist = (!isSame(B.first, A.first));
        Kab;
        if (KabExist) {  // Kab exist
            Kab = (B.second - A.second) / (B.first - A.first);
            if (isSame(Kab, 0)) {  // Kbe does not exist
                E.first = B.first;
                double p1, p2;
                p1 = B.second + fabs(B.first - A.first);
                p2 = B.second - fabs(B.first - A.first);
                if (dis(E.first, p1, C.first, C.second) > dis(E.first, p2, C.first, C.second)) E.second = p1;
                else E.second = p2;
            } else {  // Kbe exist
                double Kbe = -1 / Kab;
                double Bbe = B.second - B.first * Kbe;
                double a = Kbe * Kbe + 1;
                double b = 2 * Kbe * Bbe - 2 * B.second * Kbe - 2 * B.first;
                double c = B.first * B.first + B.second * B.second - 2 * B.second * Bbe + Bbe * Bbe - dis(A.first, A.second, B.first, B.second) * dis(A.first, A.second, B.first, B.second);
                double p1, p2;
                p1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                p2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                if (dis(p1, Kbe * p1 + Bbe, C.first, C.second) > dis(p2, Kbe * p2 + Bbe, C.first, C.second)) E.first = p1;
                else E.first = p2;
                E.second = Kbe * E.first + Bbe;
            }
        } else {
            E.second = B.second;
            double p1, p2;
            p1 = B.first + dis(A.first, A.second, B.first, B.second);
            p2 = B.first - dis(A.first, A.second, B.first, B.second);
            if (dis(p1, E.second, C.first, C.second) > dis(p2, E.second, C.first, C.second)) E.first = p1;
            else E.first = p2;
        }

        // for J
        bool KbcExist = (!isSame(B.first, C.first));
        double Kbc;
        if (KbcExist) {  // Kbc exist
            Kbc = (B.second - C.second) / (B.first - C.first);
            if (isSame(Kbc, 0)) {  // Kbj does not exist
                J.first = B.first;
                double p1, p2;
                p1 = B.second + fabs(B.first - C.first);
                p2 = B.second - fabs(B.first - C.first);
                if (dis(J.first, p1, A.first, A.second) > dis(J.first, p2, A.first, A.second)) A.second = p1;
                else J.second = p2;
            } else {  // Kbj exist
                double Kbj = -1 / Kbc;
                double Bbj = B.second - B.first * Kbj;
                double a = Kbj * Kbj + 1;
                double b = 2 * Kbj * Bbj - 2 * B.second * Kbj - 2 * B.first;
                double c = B.first * B.first + B.second * B.second - 2 * B.second * Bbj + Bbj * Bbj - dis(C.first, C.second, B.first, B.second) * dis(C.first, C.second, B.first, B.second);
                double p1, p2;
                p1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                p2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                if (dis(p1, Kbj * p1 + Bbj, A.first, A.second) > dis(p2, Kbj * p2 + Bbj, A.first, A.second)) J.first = p1;
                else J.first = p2;
                J.second = Kbj * J.first + Bbj;
            }
        } else {
            J.second = B.second;
            double p1, p2;
            p1 = B.first + dis(C.first, C.second, B.first, B.second);
            p2 = B.first - dis(C.first, C.second, B.first, B.second);
            if (dis(p1, J.second, C.first, C.second) > dis(p2, J.second, C.first, C.second)) J.first = p1;
            else J.first = p2;
        }

        // for L
        L.first = (D.first + G.first) / 2;
        L.second = (D.second + G.second) / 2;

        // for M
        M.first = (E.first + J.first) / 2;
        M.second = (E.second + J.second) / 2;

        // for O
        if (isSame(L.first, A.first)) { // Kla does not exist
            O.first = A.first;
            double Kbm = (B.second - M.second) / (B.first - M.first);
            double Bbm = B.second - B.first * Kbm;
            O.second = O.first * Kbm + Bbm;
        } else if (isSame(M.first, B.first)) {  // Kbm does not exist
            O.first = B.first;
            double Kla = (A.second - L.second) / (A.first - L.first);
            double Bla = A.second - A.first * Kla;
            O.second = O.first * Kla + Bla;
        } else {
            double Kbm = (B.second - M.second) / (B.first - M.first);
            double Bbm = B.second - B.first * Kbm;
            double Kla = (A.second - L.second) / (A.first - L.first);
            double Bla = A.second - A.first * Kla;
            O.first = (Bla - Bbm) / (Kbm - Kla);
            O.second = O.first * Kla + Bla;
        }

        printf("%.4lf %.4lf\n", (isSame(O.first, 0) ? 0 : O.first), (isSame(O.second, 0) ? 0 : O.second));

    }

    return 0;
}                                 
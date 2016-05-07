// Problem#: 1237
// Submission#: 2727630
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct pail {
    double b, w, all;
};

int main() {
    
    int step;
    double c, differance, tolerance = 0.00001, rate;
    pail pailb, pailw, b_to_w, w_to_b;
    
    while (scanf("%lf%lf%lf", &pailb.b, &pailw.w, &c) && pailb.b && pailw.w && c) {
        rate = pailb.b / pailw.w;
        pailb.b *= 16;
        pailb.w = 0;
        pailb.all = pailb.b + pailb.w;
        pailw.w *= 16;
        pailw.b = 0;
        pailw.all = pailw.b + pailw.w;
        differance = pailb.b > pailw.w ? pailb.b - pailw.w : pailw.w - pailb.b;
        step = 0;
        
        while (fabs(pailb.b / pailb.w - rate) >= tolerance || fabs(pailw.b / pailw.w - rate) >= tolerance) {
            
            //from pailb
            b_to_w.b = pailb.b / pailb.all * c;
            b_to_w.w = pailb.w / pailb.all * c;
            pailb.b -= b_to_w.b;
            pailb.w -= b_to_w.w;
            pailb.all -= c;
            
            //to pailw
            pailw.b += b_to_w.b;
            pailw.w += b_to_w.w;
            pailw.all = pailw.b + pailw.w;
            
            //from pailw
            w_to_b.b = pailw.b / pailw.all * c;
            w_to_b.w = pailw.w / pailw.all * c;
            pailw.b -= w_to_b.b;
            pailw.w -= w_to_b.w;
            pailw.all -= c;
            
            //to pailb
            pailb.b += w_to_b.b;
            pailb.w += w_to_b.w;
            pailb.all = pailb.b + pailb.w;
            
            //cal
            step++;
        }
        
        printf("%d\n", step);
    }
    return 0;
}                                 
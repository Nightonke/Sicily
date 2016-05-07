// Problem#: 2711
// Submission#: 2854162
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
  public:
    Complex(int a, int b) {
        re = a;
        im = b;
    }
    friend ostream& operator<<(ostream& out, Complex& in) {
        out << "(" << in.re << "," << in.im << ")" << endl;
        return out;
    }
    int re, im;
};

class ComplexAdd {
  public:
    int aa, bb;
    ComplexAdd(int a, int b) {
        aa = a;
        bb = b;
    }
    void operator() (Complex& in) {
        in.re += aa;
        in.im += bb;
    }
};

#endif                                 
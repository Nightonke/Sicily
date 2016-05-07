// Problem#: 2712
// Submission#: 3376187
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
using namespace std;
class sortAlgorithm {
public:
    virtual void sort(int p[], int sz) = 0 ;
    virtual ~sortAlgorithm() {}
};

class simpleSelection:public sortAlgorithm {
    void sort(int p[], int sz) {}
};

class bubleSort:public sortAlgorithm {
    void sort(int p[], int sz) {}
};
 
class sortArray {
    int *p;
    int size;
    sortAlgorithm *sa;
    friend ostream& operator<<(ostream & s, sortArray & a) {
        for (int i = 0; i < a.size; i++) {
            if (i) s << " ";
            s << a.p[i];
        }
        s << endl;
        return s;
    }
public:
    sortArray(int a[], int n) {
        if (n) p = new int[n];
        else p = NULL;
        size = n;
        for (int i = 0; i < n; i++) p[i] = a[i];
    }
    ~sortArray() {
        if (p) delete[] p;
        size = 0;
    }
    void setParam(int a[], int n) {
        if (p) delete[] p;
        p = new int[n];
        size = n;
        for (int i = 0; i < n; i++) p[i] = a[i];
    }
    void setAlgorithm(sortAlgorithm * sp) {
        sa = sp;
    }
    void sortIt() {
        std::sort(p, p + size);
    }
};                                 
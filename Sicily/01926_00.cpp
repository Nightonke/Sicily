// Problem#: 1926
// Submission#: 3279975
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
class NumCal {
    int *p;    // 数组首地址
    int size; // 数组size
public:
    int sum() {
        int s = 0;
        for (int i = 0; i < size; i++) s += *(p + i);
        return s;
    }
    NumCal() {
        p = new int[1000000];
        size = 0;
    }
    NumCal(int *new_p, int new_size) {
        delete []p;
        p = new int[new_size];
        for (int i = 0; i < new_size; i++) {
            p[i] = new_p[i];
        }
        size = new_size;
    }
};                                 
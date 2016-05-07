// Problem#: 2710
// Submission#: 3375538
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
class numCal {
public:
    numCal(int a[], int n) {
        if (n == 0) arr = NULL;
        else arr = new int[n];
        size = n;
        for (int i = 0; i < size; i++) arr[i] = a[i];
    }
     numCal(const numCal & an) {
        if (an.size == 0) arr = NULL;
        else arr = new int[an.size];
        size = an.size;
        for (int i = 0; i < size; i++) arr[i] = an.arr[i];
     }
     ~numCal() {
         if (arr) delete[] arr;
         arr = NULL;
         size = 0;
     }
     int sum() {
         int s = 0;
         for (int i = 0; i < size; i++) s += arr[i];
         return s;
     }
     numCal & operator=(const numCal & an) {
         if (arr) delete[] arr;
         arr = NULL;
         arr = new int[an.size];
         size = an.size;
         for (int i = 0; i < size; i++) arr[i] = an.arr[i];
         return *this;
     }
     numCal& operator++() {
         for (int i = 0; i < size; i++) arr[i]++;
         return *this;
     }
     numCal operator++(int) {
         numCal an(*this);
         for (int i = 0; i < size; i++) arr[i]++;
         return an;
     }
private:
    int size;
    int *arr;
};                                 
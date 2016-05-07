// Problem#: 2319
// Submission#: 3324715
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <vector>
using namespace std;

template<typename T>
bool binSearch(vector<T> & table, int low, int high, const T & target) {
    if (low > high) return false;
    int mid = (low + high) / 2;
    if (target < table[mid]) return binSearch(table, low, mid - 1, target);
    else if (target > table[mid]) return binSearch(table, mid + 1, high, target);
    else return true;
}                                 
// Problem#: 13915
// Submission#: 3638790
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int main() {
    int n, k = 2;
    long long int sum = 0, temp;
    cin >> n >> sum;
    cout << sum;
    while (--n) {
        cin >> temp;
        cout << " " << temp * k - sum;
        sum = temp * (k++);
    }
    cout << endl;
    return 0;
}                                 
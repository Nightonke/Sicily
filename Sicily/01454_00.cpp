// Problem#: 1454
// Submission#: 3277799
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
using namespace std;

long long int P;

bool isPrime(long long int p) {
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) return false;
    }
    return true;
}

long long int power(long long int a, long long int p) {
    if (p == 0) return 1;
    if (p % 2) {
        return (a * power(a, p - 1)) % P;
    } else {
        long long int temp = power(a, p / 2) % P;
        return (temp * temp) % P;
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        long long a;
        cin >> P >> a;
        if (a == 0 && P == 0) break;
        if (!isPrime(P) && power(a, P) % P == a) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}                                 
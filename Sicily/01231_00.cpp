// Problem#: 1231
// Submission#: 3294427
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
using namespace std;

const int primeNum = 1000005;

bool isNotPrime[primeNum];
int prime[100000];
int pNum = 0;

void makePrime() {

    for (int i = 2; i < primeNum; i++) {
        if (!isNotPrime[i]) {
            prime[pNum++] = i;
            for (int j = 2 * i; j < primeNum; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}

bool isMod(string & key, int p) {
    int r = 0, s = key.size();
    for (int i = 0; i < s; i++) {
        r = (r * 10 + key[i] - '0') % p;
    }
    return r == 0;
}

int main() {

    std::ios::sync_with_stdio(false);

    makePrime();

    while (1) {

        string key;
        int least, i;

        cin >> key >> least;
        if (key == "0" && least == 0) break;

        for (i = 0; i < pNum && prime[i] < least; i++) {
            if (isMod(key, prime[i])) {
                cout << "BAD " << prime[i] << endl;
                break;
            }
        }
        if (prime[i] >= least) cout << "GOOD" << endl;
    }

    return 0;
}                                 
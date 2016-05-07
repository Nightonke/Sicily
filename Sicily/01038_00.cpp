// Problem#: 1038
// Submission#: 3238022
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

const int MAX = 1000001;
int ans[MAX];
int Bn[MAX];
inline int gap(int m) {

}
int small[MAX];
inline int quot(int m) {


}
void init() {

    int i, j, n, k, B, p;

    ans[1] = 1;
    ans[2] = 2;

    for (i = 2; i < MAX; i++) Bn[i] = i;
    Bn[2] = 4;

    for (i = 2; i < MAX; i++) {
        if (small[i] == 0) {
            for (j = i; j < MAX; j += i) {
                if (small[j] == 0) small[j] = i;
            }
        }
    }

    k, B = 2;
    for (n = 2; n < MAX; n++) {
        k = B;
        B = MAX;
        while (k != 1) {
            p = small[k];

            while (ans[Bn[p]] != 0 && Bn[p] + p < MAX) Bn[p] += p;

            if (Bn[p] < B) B = Bn[p];

            while (k % p == 0) k /= p;
        }
        ans[B] = n + 1;
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    init();

    int pos;

    while (1) {
    
        cin >> pos;
        if (pos == 0) break;
        cout << "The number " << pos << " appears in location " << ans[pos] << "." << endl;

    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
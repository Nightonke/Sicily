// Problem#: 1873
// Submission#: 3344924
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

int main() {

    std::ios::sync_with_stdio(false);
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int temp;
        cin >> temp;
        long long fi2 = 2;
        long long fi1 = 3;
        long long f = fi1 + fi2;
        bool lose = false;
        if (temp == fi2 || temp == fi1 || temp == 1) lose = true;
        while (temp >= f) {
            if (temp == f) {
                lose = true;
                break;
            }
            fi2 = fi1;
            fi1 = f;
            f = fi1 + fi2;
        }
        cout << (lose ? "YES" : "NO") << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
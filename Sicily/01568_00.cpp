// Problem#: 1568
// Submission#: 3319961
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

    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        cout << (n >= 5 ? n : (n == 4 ? 2 : 1)) << endl;
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 
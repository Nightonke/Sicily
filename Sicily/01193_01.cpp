// Problem#: 1193
// Submission#: 3175280
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1193
// Submission#: 3175075
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
        int man[1005];
        int n, s, b;
        cin >> n >> s >> b;
        int Max = -1;
        bool gogogo = false;
        if (b % n == 0) gogogo = true;
        for (int i = 0; i < n; i++) {
            int f, box;
            cin >> f >> box;
            if (gogogo) {
                if (box && s + s - f > Max) Max = s + s - f;
                if (!box && f > Max) Max = f;
            } else {
                if (box) man[i] = s - f + s;
                else man[i] = f;
            }
        }
        if (!gogogo) sort(man, man + n);
        if (b % n == 0) cout << (b / n - 1) * 2 * s + Max + s << endl;
        else cout << b / n * 2 * s + man[b % n - 1] + s << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
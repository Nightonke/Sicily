// Problem#: 1418
// Submission#: 3238449
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
#include <set>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int a, b, c, d, e, temp;
        set<int> A, B, C, D, E, Ans;
        cin >> a >> b >> c >> d >> e;
        while (a--) cin >> temp, A.insert(temp);
        while (b--) cin >> temp, B.insert(temp);
        while (c--) cin >> temp, C.insert(temp);
        while (d--) cin >> temp, D.insert(temp);
        while (e--) cin >> temp, E.insert(temp);
        // A C D
        for (set<int>::iterator ia = A.begin(); ia != A.end(); ia++) {
            for (set<int>::iterator ic = C.begin(); ic != C.end(); ic++) {
                for (set<int>::iterator id = D.begin(); id != D.end(); id++) {
                    if (*ia + *ic + *id >= 0 && Ans.find(*ia + *ic + *id) == Ans.end()) Ans.insert(*ia + *ic + *id);
                }
            }
        }
        // A B D
        for (set<int>::iterator ia = A.begin(); ia != A.end(); ia++) {
            for (set<int>::iterator ib = B.begin(); ib != B.end(); ib++) {
                for (set<int>::iterator id = D.begin(); id != D.end(); id++) {
                    if (*ia + *ib + *id >= 0 && Ans.find(*ia + *ib + *id) == Ans.end()) Ans.insert(*ia + *ib + *id);
                }
            }
        }
        // D E
        for (set<int>::iterator id = D.begin(); id != D.end(); id++) {
            for (set<int>::iterator ie = E.begin(); ie != E.end(); ie++) {
                if (*id + *ie >= 0 && Ans.find(*id + *ie) == Ans.end()) Ans.insert(*id + *ie);
            }
        }
        cout << Ans.size() << endl;
    }
        
    //getchar();
    //getchar();
    
    return 0;
}                                 
// Problem#: 1860
// Submission#: 3343303
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
        string s;
        cin >> s;
        int l = s.size();
        char minC = 'Z';
        for (int i = 0; i < l; i++) {
            if (minC > s[i]) {
                minC = s[i];
                if (minC == 'A') break;
            }
        }
        list<vector<int> > v;
        for (int i = 0; i < l; i++) {
            if (s[i] == minC) {
                v.push_back(vector<int>(1, i));
            }
        }

        int counter = 1;
        while (v.size() > 1 && counter < l && counter + v.size() <= l) {
            char minC = 'Z';
            for (list<vector<int> >::iterator iter = v.begin(); iter != v.end(); iter++) {
                int last = (*iter)[iter->size() - 1];
                int next = last + 1;
                if (next == l) next = 0;
                if (s[next] < minC) {
                    minC = s[next];
                    if (minC == 'A') break;
                }
            }
            for (list<vector<int> >::iterator iter = v.begin(); iter != v.end(); ) {
                int last = (*iter)[iter->size() - 1];
                int next = last + 1;
                if (next == l) next = 0;
                if (s[next] != minC) {
                    list<vector<int> >::iterator del = iter;
                    iter++;
                    v.erase(del);
                } else {
                    iter->push_back(next);
                    iter++;
                }
            }
            counter++;
        }

        string ans;
        int pos = (*(v.begin()))[0];
        for (int i = 0; i < l; i++) {
            ans.push_back(s[pos]);
            pos = pos + 1;
            if (pos == l) pos = 0;
        }
        cout << ans << endl;
        
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 
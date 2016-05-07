// Problem#: 1938
// Submission#: 2758733
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <queue>
#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

string to_up(string a) {
    for (int i = 0; i < (int)a.size(); i++) {
        a[i] = a[i] >= 'a' ? a[i] - ('a' - 'A') : a[i];
    }
    return a;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    
    string temp;
    
    int counter, case_num, n_list, n_sent;
    
    cin >> case_num;
    while (case_num--) {
        map<string, bool> list;
        map<string, bool> :: iterator ll;
        counter = 0;
        cin >> n_list >> n_sent;
        while (n_list--) {
            cin >> temp;
            temp = to_up(temp);
            list.insert(pair<string, bool>(temp, true));
        }
        while (n_sent--) {
            cin >> temp;
            temp = to_up(temp);
            if (list.find(temp) != list.end()) {
                (*(list.find(temp))).second = false;
            }
        }
        for (ll = list.begin(); ll != list.end(); ll++) {
            if ((*ll).second == true) {
                counter++;
            }
        }
        cout << counter << endl;
    }
        
    return 0;
}                                 
// Problem#: 1366
// Submission#: 3305864
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
using namespace std;

int main() {

    std::cout.sync_with_stdio(false);
    
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int l, m;
        cin >> l >> m;
        l *= 100;
        int car, allCar = 0;
        int ans = 0;
        bool atLeft = true;
        string pos;

        queue<int> ll, rr;

        while (m--) {
            cin >> car >> pos;
            if (pos == "left") ll.push(car);
            else rr.push(car);
        }

        while (1) {
            while (!ll.empty() && ll.front() + allCar <= l) {
                allCar += ll.front();
                ll.pop();
            }
            allCar = 0;
            ans++;
            if (ll.empty() && rr.empty()) break;
            while (!rr.empty() && rr.front() + allCar <= l) {
                allCar += rr.front();
                rr.pop();
            }
            allCar = 0;
            ans++;
            if (ll.empty() && rr.empty()) break;
        }

        cout << ans << endl;
    }

    return 0;
}                                 
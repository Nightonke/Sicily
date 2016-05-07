// Problem#: 2506
// Submission#: 3275461
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    long long int Oria, Orib;

    cin >> Oria >> Orib >> caseNum;

    while (caseNum--) {

        long long int a = Oria, b = Orib;
        long long int counter = 1;
        long long int ans;
        long long int k;
        cin >> k;

        while (1) {

            if (counter == k) {
                ans = a;
                break;
            }

            if (a == b) {

                if ((k - counter + 1) % 3 == 0) {
                    ans = 0;
                    break;
                } else {
                    ans = a;
                    break;
                }

            } else if (b != 0 && a / b >= 2) {

                long long int sureNum = a / b / 2 * 3;

                if (counter <= k && k <= counter + sureNum) {
                    if ((k - counter) % 3 == 0) {
                        ans = a - (k - counter) / 3 * b * 2;
                        break;
                    } else if ((k - counter) % 3 == 1) {
                        ans = b;
                        break;
                    } else {
                        if (a - (k - counter) / 3 * b * 2 > b) ans = a - (k - counter) / 3 * b * 2 - b;
                        else ans = b - (a - (k - counter) / 3 * b * 2);
                        break;
                    }

                } else {

                    counter += a / b / 2 * 3 + 1;
                    long long int temp = b;
                    if (a - sureNum / 3 * b * 2 > temp) b = a - sureNum / 3 * b * 2 - temp;
                    else b = temp - (a - sureNum / 3 * b * 2);
                    a = temp;
                }
        
            } else {
            
                long long int next;
                if (a > b) next = a - b;
                else next = b - a;
                a = b;
                b = next;
                counter++;

            }

        }

        cout << ans << endl;

    }

    return 0;
}                                 
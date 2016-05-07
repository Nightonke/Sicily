// Problem#: 11159
// Submission#: 3054857
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
using namespace std;

#define INF 2000000000

int main() {

    //std::ios::sync_with_stdio(false);

    int n;

    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    long long int sum = 0;

    for (int i = 0; i < n; i++) {
        
        cin >> a[i] >> b[i];

        sum += b[i];

    }

    double up = 10000000.0, down = 0;
    bool impossible = false;

    for (int i = 0; i < n - 1; i++) {

        if (b[i + 1] - b[i] > 0) {

            double newUp = double(sum * (long long)(a[i] - a[i + 1])) / (double)(b[i + 1] - b[i]);

            if (newUp < up) up = newUp;

        } else if (b[i + 1] - b[i] < 0) {

            double newDown = double(sum * (long long)(a[i] - a[i + 1])) / (double)(b[i + 1] - b[i]);

            if (newDown > down) down = newDown;

        } else if (a[i] < a[i + 1]) {

            cout << -1 << endl;
            return 0;

        }

    }

    if (down <= up)
        printf("%lf\n", (up + down) / 2);
    else
        cout << -1 << endl;

    //getchar();
    //getchar();
    
    return 0;
}                                 
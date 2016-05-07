// Problem#: 1363
// Submission#: 3305310
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
using namespace std;

const int MAX_H = 1000005;

int H[MAX_H];
int num[MAX_H];

int main() {

    std::cout.sync_with_stdio(false);
    
    for (int i = 5; i < 1000; i += 4)
        for (int j = i; j * i < MAX_H; j += 4)
            H[i * j] = H[i] + H[j] + 1;

    for (int i = 25; i < MAX_H; i++) num[i] = (H[i] == 1) + num[i - 1];

    while (1) {
        int temp;
        cin >> temp;
        if (temp == 0) break;
        cout << temp << " " << num[temp] << endl;
    }

    return 0;
}                                 
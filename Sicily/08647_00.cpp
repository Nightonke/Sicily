// Problem#: 8647
// Submission#: 2746916
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main() {
    int n, i, j, temp;
    vector<int> hash[13];
    while (cin >> n && n) {
        memset(hash, 0, sizeof(hash));
        for (i = 0; i < n; i++) {
            cin >> temp;
            hash[temp % 13].push_back(temp);
        }
        
        for (i = 0; i < 13; i++) {
            cout << i << '#';
            if (hash[i].size() == 0)
                cout << "NULL";
            for (j = 0; j < (int)hash[i].size(); j++) {
                if (j != (int)hash[i].size() - 1)
                    cout << hash[i][j] << ' ';
                else
                    cout << hash[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}                                 
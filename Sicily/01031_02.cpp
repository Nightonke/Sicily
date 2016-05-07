// Problem#: 1031
// Submission#: 2775819
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define INF 99999999
#define MAX 115 * 2

int total_num_of_name, mapp[MAX][MAX];
char num_of_name[MAX][MAX];

int min(int a, int b) {
    return a > b ? b : a;
}

void Floyd_Warshall() {
    int i, j, k;
    for (i = 0; i < MAX; i++) {
        mapp[i][i] = 0;
    }
    for (k = 0; k < total_num_of_name; k++) {
        for (i = 0; i < total_num_of_name; i++) {
            for (j = 0; j < total_num_of_name; j++) {
                mapp[i][j] = min(mapp[i][j], mapp[i][k] + mapp[k][j]);
            }
        }
    }
}

int main() {
    
    std::ios::sync_with_stdio(false);
    
    int case_num, n, dis;
    string temp_f, temp_t;
    cin >> case_num;
    
    while (case_num--) {
        cin >> n;
        
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                mapp[i][j] = INF;
            }
        }
        total_num_of_name = 0;
        map<string, int> m;
        
        while (n--) {
            cin >> temp_f >> temp_t >> dis;
            if (m.find(temp_f) == m.end()) {
                m[temp_f] = total_num_of_name++;
            }
            if (m.find(temp_t) == m.end()) {
                m[temp_t] = total_num_of_name++;
            }
            mapp[m[temp_f]][m[temp_t]] = dis < mapp[m[temp_f]][m[temp_t]] ? dis : mapp[m[temp_f]][m[temp_t]];
            mapp[m[temp_t]][m[temp_f]] = dis < mapp[m[temp_t]][m[temp_f]] ? dis : mapp[m[temp_t]][m[temp_f]];
        }
        
        cin >> temp_f >> temp_t;
        if (temp_f == temp_t) {
            cout << 0 << endl;
            continue;
        }
        
        if (m.find(temp_f) == m.end() || m.find(temp_t) == m.end()) {
            cout << -1 << endl;
            continue;
        }
        
        Floyd_Warshall();
        
        cout << (mapp[m[temp_f]][m[temp_t]] >= INF ? -1 : mapp[m[temp_f]][m[temp_t]]) << endl;

    }
    return 0;
}                                 
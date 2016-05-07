// Problem#: 1031
// Submission#: 2775864
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

int Dijkstra(int start_point, int end_point) {
    
    int dis_from_sp[MAX];
    fill(dis_from_sp, dis_from_sp + total_num_of_name, INF);
    bool used_point[MAX];
    fill(used_point, used_point + total_num_of_name, false);
    dis_from_sp[start_point] = 0;
    
    while (1) {
        int v = -1;
        for (int i = 0; i < total_num_of_name; i++) {
            if (!used_point[i] && (v == -1 || dis_from_sp[i] < dis_from_sp[v]))
                v = i;
        }
        
        if (v == -1)
            break;
        
        used_point[v] = true;
        for (int i = 0; i < total_num_of_name; i++) {
            dis_from_sp[i] = min(dis_from_sp[i], dis_from_sp[v] + mapp[v][i]);
        }
    }
    return dis_from_sp[end_point];
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
        
        for (int i = 0; i < total_num_of_name; i++) {
            mapp[i][i] = 0;
        }
        
        int ans = Dijkstra(m[temp_f], m[temp_t]);
        
        cout << (ans < INF ? ans : -1) << endl;
    }
    return 0;
}                                 
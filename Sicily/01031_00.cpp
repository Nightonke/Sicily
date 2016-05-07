// Problem#: 1031
// Submission#: 2776268
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999999
#define MAX 115 * 2

int total_num_of_name;

struct edges {
    int to;
    int diss;
    edges(int new_to, int new_diss): to(new_to), diss(new_diss){}
};

vector<edges> e[MAX];

typedef pair<int, int> p;

int Dijkstra(int start_point, int end_point) {
    
    int dis_from_sp[MAX];
    fill(dis_from_sp, dis_from_sp + total_num_of_name, INF);
    dis_from_sp[start_point] = 0;
    
    priority_queue<p, vector<p>, greater<p> > q;
    q.push(p(0, start_point));
    
    while (!q.empty()) {
        p temp_p = q.top();
        q.pop();
        int pos = temp_p.second;
        
        if (dis_from_sp[pos] < temp_p.first)
            continue;
        
        for (int i = 0; i < (int)e[pos].size(); i++) {
            edges new_edge = e[pos][i];
            
            if (dis_from_sp[new_edge.to] > dis_from_sp[pos] + new_edge.diss) {
                
                dis_from_sp[new_edge.to] = dis_from_sp[pos] + new_edge.diss;
                
                q.push(p(dis_from_sp[new_edge.to], new_edge.to));
            }
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
        total_num_of_name = 0;
        map<string, int> m;
        for (int i = 0; i < MAX; i++) {
            e[i].clear();
        }
         
        while (n--) {
            cin >> temp_f >> temp_t >> dis;
            if (m.find(temp_f) == m.end()) {
                m[temp_f] = total_num_of_name++;
            }
            if (m.find(temp_t) == m.end()) {
                m[temp_t] = total_num_of_name++;
            }
            e[m[temp_f]].push_back(edges(m[temp_t], dis));
            e[m[temp_t]].push_back(edges(m[temp_f], dis));
        }
        
        for (int i = 0; i < total_num_of_name; i++) {
            int j;
            for (j = 0; j < (int)e[i].size(); j++) {
                if (e[i][j].to == i) {
                    e[i][j] = edges(i, 0);
                    break;
                }
            }
            if (j >= (int)e[i].size())
                e[i].push_back(edges(i, 0));
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
        
        int ans = Dijkstra(m[temp_f], m[temp_t]);
        
        cout << (ans < INF ? ans : -1) << endl;
    }
    return 0;
}                                 
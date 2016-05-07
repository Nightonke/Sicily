// Problem#: 1024
// Submission#: 2740092
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
using namespace std;

struct Road {
    int to, distance;
    Road(int new_to, int new_distance) {
        to = new_to;
        distance = new_distance;
    }
};

vector<Road> roads[10001];
bool vis[10001];
int longest_road, n;

void dfs(int from, int dis) {
    if (dis > longest_road)
        longest_road = dis;
    vis[from] = true;
    
    for (int i = 0; i < (int)roads[from].size(); i++) {
        if (!vis[roads[from][i].to] && roads[from][i].distance != 0) {
            dfs(roads[from][i].to, dis + roads[from][i].distance);
        }
    }
}

int main() {
    int k, i, temp_from, temp_to, new_distance;
    while (cin >> n >> k) {
        longest_road = 0;
        memset(vis, false, sizeof(vis));
        memset(roads, 0, sizeof(roads));
        for (i = 0; i < n - 1; i++) {
            cin >> temp_from >> temp_to >> new_distance;
            roads[temp_from].push_back(Road(temp_to, new_distance));
            roads[temp_to].push_back(Road(temp_from, new_distance));
        }
        dfs(k, 0);
        cout << longest_road << endl;
    }
    return 0;
}                                 
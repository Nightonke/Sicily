// Problem#: 9017
// Submission#: 2749144
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

#define INF 100000000
int w, h;
int map[65][65], min_num, exit_i, exit_j;
int dist[65][65];
int to_i[4] = {0, 2, 0, -2};
int to_j[4] = {2, 0, -2, 0};
bool is_ok, vis[65][65];

typedef pair<int, int> P;

void make_map(int w, int h) {
    int i, j;
    memset(map, 0, sizeof(map));
    
    for (i = 0; i <= 2 * h; i++) {
        if (i == 0 || i == 2 * h) {
            for (j = 0; j <= 2 * w; j++) {
                map[i][j] = 1;
            }
        } else {
            map[i][0] = map[i][2 * w] = 1;
        }
    }
    map[0][1] = map[2 * h][2 * w - 1] = 0;
    
    for (i = 1; i <= 2 * h - 1; i++) {
        if (i % 2 == 1) {
            for (j = 0; j < w - 1; j++) {
                scanf("%d", &map[i][2 * j + 2]);
            }
        } else {
            for (j = 0; j < w; j++) {
                scanf("%d", &map[i][2 * j + 1]);
            }
        }
    }
    
    /*for (i = 2; i < 2 * h; i += 2) {
        for (j = 1; j < 2 * w; j++) {
            if (map[i - 1][j] == 1 && map[i + 1][j] == 1)
                map[i][j] = 1;
            if (map[i][j - 1] == 1 && map[i][j + 1] == 1)
                map[i][j] = 1;
        }
    }
    for (i = 2; i < 2 * h; i += 2) {
        for (j = 1; j < 2 * w; j++) {
            if (map[i - 1][j] == 1 && map[i][j - 1] == 1)
                map[i][j] = 1;
            if (map[i + 1][j] == 1 && map[i][j - 1] == 1)
                map[i][j] = 1;
            if (map[i - 1][j] == 1 && map[i][j + 1] == 1)
                map[i][j] = 1;
            if (map[i + 1][j] == 1 && map[i][j + 1] == 1)
                map[i][j] = 1;
        }
    }
    */
    exit_i = 2 * h - 1;
    exit_j = 2 * w - 1;
}

int bfs() {
    queue<P> que;
    for (int i = 0; i < 65; i++) {
        for (int j = 0; j < 65; j++) {
            dist[i][j] = INF;
        }
    }
    que.push(P(1, 1));
    dist[1][1] = 0;
    
    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == exit_i && p.second == exit_j)
            break;
        
        for (int i = 0; i < 4; i++) {
            int toi = p.first + to_i[i];
            int toj = p.second + to_j[i];
            
            if (1 <= toi && toi < 2 * h && 1 <= toj && toj < 2 * w && map[(toi + p.first) / 2][(toj + p.second) / 2] == 0 && map[toi][toj] == 0 && dist[toi][toj] == INF) {
                que.push(P(toi, toj));
                dist[toi][toj] = dist[p.first][p.second] + 1;
            }
        }
    }
    return dist[exit_i][exit_j] + 1;
}

int main() {
    int i, j, dis; 
    while (scanf("%d%d", &w, &h) && w && h) {
        make_map(w, h);
        /*
        for (i = 0; i <= 2 * h; i++) {
            for (j = 0; j <= 2 * w; j++) {
                printf("%d", map[i][j]);
            }
            printf("\n");
        }
        */
        min_num = 99999999;
        is_ok = false;
        memset(vis, false, sizeof(vis));
        vis[1][1] = true;
        dis = bfs();
        if (dis == INF + 1)
            printf("0\n");
        else
            printf("%d\n", dis);
    }
    return 0;
}                                 
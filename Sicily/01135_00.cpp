// Problem#: 1135
// Submission#: 2779386
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 101

int min_time[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];
char map[MAX][MAX];
int h, w, max_fly;

int dir[4][2] = {-1,  0,
                  1,  0,
                  0, -1,
                  0,  1};

struct step {
    int ii;
    int jj;
    int rest_oil;
    step(int new_ii, int new_jj, int new_rest_oil) {
        ii = new_ii;
        jj = new_jj;
        rest_oil = new_rest_oil;
    }
};

int min(int a, int b) {
    return a > b ? b : a;
}

bool is_valid(int i, int j) {
    if (i < 0 || i > h - 1 || j < 0 || j > w - 1 || map[i][j] == 'L')
        return false;
    return true;
}

void BFS() {
    queue<step> q;
    q.push(step(0, 0, max_fly));
    memset(min_time, 0x7f7f7f, sizeof(min_time));
    memset(vis, 0, sizeof(vis));
    min_time[0][0][max_fly] = 0;
    int next_ii, next_jj;
    
    while (!q.empty()) {
        
        step temp = q.front();
        q.pop();
        
        if (temp.ii == h - 1 && temp.jj == w - 1) {
            printf("%d\n", min_time[h - 1][w - 1][0]);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            
            for (int j = 2; j <= temp.rest_oil; j++) {
                next_ii = temp.ii + dir[i][0] * j;
                next_jj = temp.jj + dir[i][1] * j;
                if (!is_valid(next_ii, next_jj) || vis[next_ii][next_jj][temp.rest_oil - j])
                    continue;
                min_time[next_ii][next_jj][temp.rest_oil - j] = min(min_time[next_ii][next_jj][temp.rest_oil - j], min_time[temp.ii][temp.jj][temp.rest_oil] + 1);
                vis[next_ii][next_jj][temp.rest_oil - j] = true;
                q.push(step(next_ii, next_jj, temp.rest_oil - j));
            }
            
            next_ii = temp.ii + dir[i][0];
            next_jj = temp.jj + dir[i][1];
            if (!is_valid(next_ii, next_jj) || vis[next_ii][next_jj][temp.rest_oil])
                continue;
            min_time[next_ii][next_jj][temp.rest_oil] = min(min_time[next_ii][next_jj][temp.rest_oil], min_time[temp.ii][temp.jj][temp.rest_oil] + 1);
            vis[next_ii][next_jj][temp.rest_oil] = true;
            q.push(step(next_ii, next_jj, temp.rest_oil));
        }
    }
    
    printf("impossible\n");
}

int main() {
    scanf("%d %d %d\n", &h, &w, &max_fly);
    for (int i = 0; i < h; i++) {
        gets(map[i]);
    }
    BFS();
    return 0;
}                                 
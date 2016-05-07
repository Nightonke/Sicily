// Problem#: 2002
// Submission#: 2758645
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 755

bool map[MAX][MAX];
bool vis[MAX][MAX];
int w, h;

struct point {
    int ii, jj;
};

int dfs(int start_i, int start_j) {
    queue<point> q;
    point temp_p, temp_p_last;
    temp_p.ii = start_i;
    temp_p.jj = start_j;
    vis[start_i][start_j] = true;
    q.push(temp_p);
    int counter = 0;
    
    while (!q.empty()) {
        temp_p = q.front();
        q.pop();
        map[temp_p.ii][temp_p.jj] = false;
        counter++;
        
        if (temp_p.jj < w - 1 && map[temp_p.ii][temp_p.jj + 1] && !vis[temp_p.ii][temp_p.jj + 1]) {
            temp_p_last.ii = temp_p.ii;
            temp_p_last.jj = temp_p.jj + 1;
            q.push(temp_p_last);
            vis[temp_p.ii][temp_p.jj + 1] = true;
        }
        
        if (temp_p.ii < h - 1 && map[temp_p.ii + 1][temp_p.jj] && !vis[temp_p.ii + 1][temp_p.jj]) {
            temp_p_last.ii = temp_p.ii + 1;
            temp_p_last.jj = temp_p.jj;
            q.push(temp_p_last);
            vis[temp_p.ii + 1][temp_p.jj] = true;
        }
        
        if (temp_p.ii < h - 1 && temp_p.jj < w - 1 && map[temp_p.ii + 1][temp_p.jj + 1] && !vis[temp_p.ii + 1][temp_p.jj + 1]) {
            temp_p_last.ii = temp_p.ii + 1;
            temp_p_last.jj = temp_p.jj + 1;
            q.push(temp_p_last);
            vis[temp_p.ii + 1][temp_p.jj + 1] = true;
        }
        
        if (temp_p.ii > 0 && temp_p.jj < w - 1 && map[temp_p.ii - 1][temp_p.jj + 1] && !vis[temp_p.ii - 1][temp_p.jj + 1]) {
            temp_p_last.ii = temp_p.ii - 1;
            temp_p_last.jj = temp_p.jj + 1;
            q.push(temp_p_last);
            vis[temp_p.ii - 1][temp_p.jj + 1] = true;
        }
        
        if (temp_p.ii > 0 && map[temp_p.ii - 1][temp_p.jj] && !vis[temp_p.ii - 1][temp_p.jj]) {
            temp_p_last.ii = temp_p.ii - 1;
            temp_p_last.jj = temp_p.jj;
            q.push(temp_p_last);
            vis[temp_p.ii - 1][temp_p.jj] = true;
        }
        
        if (temp_p.jj > 0 && map[temp_p.ii][temp_p.jj - 1] && !vis[temp_p.ii][temp_p.jj - 1]) {
            temp_p_last.ii = temp_p.ii;
            temp_p_last.jj = temp_p.jj - 1;
            q.push(temp_p_last);
            vis[temp_p.ii][temp_p.jj - 1] = true;
        }
        
        if (temp_p.ii > 0 && temp_p.jj > 0 && map[temp_p.ii - 1][temp_p.jj - 1] && !vis[temp_p.ii - 1][temp_p.jj - 1]) {
            temp_p_last.ii = temp_p.ii - 1;
            temp_p_last.jj = temp_p.jj - 1;
            q.push(temp_p_last);
            vis[temp_p.ii - 1][temp_p.jj - 1] = true;
        }
        
        if (temp_p.ii < h - 1 && temp_p.jj > 0 && map[temp_p.ii + 1][temp_p.jj - 1] && !vis[temp_p.ii + 1][temp_p.jj - 1]) {
            temp_p_last.ii = temp_p.ii + 1;
            temp_p_last.jj = temp_p.jj - 1;
            q.push(temp_p_last);
            vis[temp_p.ii + 1][temp_p.jj - 1] = true;
        }
    }
    return counter;
}
    
int main() {
    int i, j, max, temp_num;
    char temp[755];
    scanf("%d%d\n", &w, &h);
    for (i = 0; i < h; i++) {
        gets(temp);
        for (j = 0; j < w; j++) {
            if (temp[j] == '.') {
                map[i][j] = true;
            }
        }
    }
    for (i = 0, max = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (map[i][j]) {
                temp_num = dfs(i, j);
                max = temp_num > max ? temp_num : max;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}                                 
// Problem#: 1781
// Submission#: 2761318
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int n;
bool vis[505][505];

struct point {
    int ii;
    int jj;
};

point sp, ep;

int bfs() {
    
    if (sp.ii == ep.ii && sp.jj == ep.jj)
        return 0;
    
    queue<point> q;
    q.push(sp);
    point temp, temp_next;
    int step = 0;
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            vis[i][j] = false;
        }
    }
    
    while (!q.empty()) {
        step++;
        int size = q.size();
        while (size--) {
            temp = q.front();
            q.pop();
            
            if (temp.ii > 1 && temp.jj < n - 1 && !vis[temp.ii - 2][temp.jj + 1]) {
                temp_next.ii = temp.ii - 2;
                temp_next.jj = temp.jj + 1;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
            
            if (temp.ii > 0 && temp.jj < n - 2 && !vis[temp.ii - 1][temp.jj + 2]) {
                temp_next.ii = temp.ii - 1;
                temp_next.jj = temp.jj + 2;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
            
            if (temp.ii < n - 1 && temp.jj < n - 2 && !vis[temp.ii + 1][temp.jj + 2]) {
                temp_next.ii = temp.ii + 1;
                temp_next.jj = temp.jj + 2;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
            
            if (temp.ii < n - 2 && temp.jj < n - 1 && !vis[temp.ii + 2][temp.jj + 1]) {
                temp_next.ii = temp.ii + 2;
                temp_next.jj = temp.jj + 1;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
            
            if (temp.ii < n - 2 && temp.jj > 0 && !vis[temp.ii + 2][temp.jj - 1]) {
                temp_next.ii = temp.ii + 2;
                temp_next.jj = temp.jj - 1;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
            
            if (temp.ii < n - 1 && temp.jj > 1 && !vis[temp.ii + 1][temp.jj - 2]) {
                temp_next.ii = temp.ii + 1;
                temp_next.jj = temp.jj - 2;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
            
            if (temp.ii > 0 && temp.jj > n - 1 && !vis[temp.ii - 1][temp.jj - 2]) {
                temp_next.ii = temp.ii - 1;
                temp_next.jj = temp.jj - 2;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
            
            if (temp.ii > 1 && temp.jj > 0 && !vis[temp.ii - 2][temp.jj - 1]) {
                temp_next.ii = temp.ii - 2;
                temp_next.jj = temp.jj - 1;
                if (temp_next.ii == ep.ii && temp_next.jj == ep.jj) {
                    return step;
                }
                vis[temp_next.ii][temp_next.jj] = true;
                q.push(temp_next);
            }
        }
    }
    return -1;
}
    
    
    
int main() {
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d", &n);
        scanf("%d%d%d%d", &sp.ii, &sp.jj, &ep.ii, &ep.jj);
        printf("%d\n", bfs());
    }
    return 0;
}                                 
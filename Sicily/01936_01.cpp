// Problem#: 1936
// Submission#: 2759108
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1936
// Submission#: 2758901
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <queue>
#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
#define MAX 8

bool map[MAX][MAX];
bool vis[MAX][MAX];
int all_ans[MAX * MAX + 5][MAX * MAX + 5];

struct point {
    int ii;
    int jj;
};

point start, end;

bool the_same_point(point a, point b) {
    return a.ii == b.ii && a.jj == b.jj;
}

void output(int ans) {
    printf("To get from %c%d to %c%d takes %d knight moves.\n", start.jj + 'a', start.ii + 1, end.jj + 'a', end.ii + 1, ans);
    all_ans[start.ii * 10 + start.jj][end.ii * 10 + end.jj] = ans;
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    queue<point> q;
    q.push(start);
    int size, step = 0;
    point temp, temp_next;
    while (!q.empty()) {
        step++;
        size = q.size();
        while (size--) {
            temp = q.front();
            q.pop();
            
            if (temp.ii > 1 && temp.jj > 0 && !vis[temp.ii - 2][temp.jj - 1]) {
                temp_next.ii = temp.ii - 2;
                temp_next.jj = temp.jj - 1;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
            
            if (temp.ii > 1 && temp.jj < 7 && !vis[temp.ii - 2][temp.jj + 1]) {
                temp_next.ii = temp.ii - 2;
                temp_next.jj = temp.jj + 1;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
            
            if (temp.ii > 0 && temp.jj < 6 && !vis[temp.ii - 1][temp.jj + 2]) {
                temp_next.ii = temp.ii - 1;
                temp_next.jj = temp.jj + 2;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
            
            if (temp.ii < 7 && temp.jj < 6 && !vis[temp.ii + 1][temp.jj + 2]) {
                temp_next.ii = temp.ii + 1;
                temp_next.jj = temp.jj + 2;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
            
            if (temp.ii < 6 && temp.jj < 7 && !vis[temp.ii + 2][temp.jj + 1]) {
                temp_next.ii = temp.ii + 2;
                temp_next.jj = temp.jj + 1;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
            
            if (temp.ii < 6 && temp.jj > 0 && !vis[temp.ii + 2][temp.jj - 1]) {
                temp_next.ii = temp.ii + 2;
                temp_next.jj = temp.jj - 1;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
            
            if (temp.ii < 7 && temp.jj > 1 && !vis[temp.ii + 1][temp.jj - 2]) {
                temp_next.ii = temp.ii + 1;
                temp_next.jj = temp.jj - 2;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
            
            if (temp.ii > 0 && temp.jj > 1 && !vis[temp.ii - 1][temp.jj - 2]) {
                temp_next.ii = temp.ii - 1;
                temp_next.jj = temp.jj - 2;
                if (the_same_point(temp_next, end)) {
                    output(step);
                }
                q.push(temp_next);
                vis[temp_next.ii][temp_next.jj] = true;
            }
        }
    }
}
            

int main() {
    int case_num;
    scanf("%d\n", &case_num);
    char temp[5];
    while (case_num--) {
        scanf("%s", temp);
        start.ii = temp[1] - '0' - 1;
        start.jj = temp[0] - 'a';
        scanf("%s", temp);
        end.ii = temp[1] - '0' - 1;
        end.jj = temp[0] - 'a';
        if (the_same_point(start, end)) {
            output(0);
        } else {
            bfs();
        }
    }
    return 0;
}                                 
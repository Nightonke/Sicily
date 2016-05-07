// Problem#: 1401
// Submission#: 2822462
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

//0-e, 1-s, 2-w, 3-n;

int best_dir_for_l_go[4][4] = {3, 0, 1, 2, 0, 1, 2, 3, 1, 2, 3, 0, 2, 3, 0, 1};
int best_dir_for_r_go[4][4] = {1, 0, 3, 2, 2, 1, 0, 3, 3, 2, 1, 0, 0, 3, 2, 1};
int move_dir[4][3] = {0, 1, 0, 0, -1, 2, 1, 0, 1, -1, 0, 3};
int s_i, s_j, e_i, e_j, s_dir;
int h, w;
char mapp[45][45];

struct man {
    int ii;
    int jj;
    int num;
    int dir;
    man(){};
    man(int i, int j, int n, int d) {
        ii = i;
        jj = j;
        num = n;
        dir = d;
    }
};

bool is_ok(man m) {
    return m.ii == e_i && m.jj == e_j;
}

bool can_go(int next_dir, man m) {
    if (next_dir == 0) {
        return mapp[m.ii][m.jj + 1] == '.';
    } else if (next_dir == 1) {
        return mapp[m.ii + 1][m.jj] == '.';
    } else if (next_dir == 2) {
        return mapp[m.ii][m.jj - 1] == '.';
    } else {
        return mapp[m.ii - 1][m.jj] == '.';
    }
}

bool can_go_2(int i, int j) {
    return mapp[i][j] == '.';
}

void left_go() {
    man m;
    m.ii = s_i;
    m.jj = s_j;
    m.num = 1;
    m.dir = s_dir;
    while (!is_ok(m)) {
        for (int i = 0; i < 4; i++) {
            if (can_go(best_dir_for_l_go[m.dir][i], m)) {
                if (best_dir_for_l_go[m.dir][i] == 0) {
                    m.jj++;
                } else if (best_dir_for_l_go[m.dir][i] == 1) {
                    m.ii++;
                } else if (best_dir_for_l_go[m.dir][i] == 2) {
                    m.jj--;
                } else {
                    m.ii--;
                }
                m.dir = best_dir_for_l_go[m.dir][i];
                m.num++;
                break;
            }
        }
    }
    printf("%d ", m.num);
}

void right_go() {
    man m;
    m.ii = s_i;
    m.jj = s_j;
    m.num = 1;
    m.dir = s_dir;
    while (!is_ok(m)) {
        for (int i = 0; i < 4; i++) {
            if (can_go(best_dir_for_r_go[m.dir][i], m)) {
                if (best_dir_for_r_go[m.dir][i] == 0) {
                    m.jj++;
                } else if (best_dir_for_r_go[m.dir][i] == 1) {
                    m.ii++;
                } else if (best_dir_for_r_go[m.dir][i] == 2) {
                    m.jj--;
                } else {
                    m.ii--;
                }
                m.dir = best_dir_for_r_go[m.dir][i];
                m.num++;
                break;
            }
        }
    }
    printf("%d ", m.num);
}

void BFS() {
    queue<man> q;
    q.push(man(s_i, s_j, 1, 0));
    man temp_m;
    
    while (!q.empty()) {
        temp_m = q.front();
        q.pop();
        if (is_ok(temp_m)) {
            printf("%d\n", temp_m.num);
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (can_go_2(temp_m.ii + move_dir[i][0], temp_m.jj + move_dir[i][1])) {
                q.push(man(temp_m.ii + move_dir[i][0], temp_m.jj + move_dir[i][1], temp_m.num + 1, 0));
                mapp[temp_m.ii + move_dir[i][0]][temp_m.jj + move_dir[i][1]] = '#';
            }
        }
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        memset(mapp, '\0', sizeof(mapp));
        s_i = -1;
        e_i = -1;
        scanf("%d %d\n", &w, &h);
        for (int i = 0; i < h; i++) {
            gets(mapp[i]);
            for (int j = 0; j < w && s_i == -1; j++) {
                if (mapp[i][j] == 'S') {
                    s_i = i;
                    s_j = j;
                    break;
                }
            }
            for (int j = 0; j < w && e_i == -1; j++) {                
                if (mapp[i][j] == 'E') {
                    e_i = i;
                    e_j = j;
                    mapp[i][j] = '.';
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (mapp[s_i + move_dir[i][0]][s_j + move_dir[i][1]] == '.') {
                s_dir = move_dir[i][2];
                break;
            }
        }
        left_go();
        right_go();
        BFS();
    }
    return 0;
}                                 
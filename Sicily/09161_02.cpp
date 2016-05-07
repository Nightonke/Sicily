// Problem#: 9161
// Submission#: 2816454
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int used[505][505];
char mapp[505][505];
char dir[5] = "URDL";
int max = 0;
char max_dir = 'U';
int sp_i, sp_j, h, w;
bool indefinition = false;
char now_dir = 'U';

struct step {
    char dir;
    int ii;
    int jj;
    int num;
    step(char d, int i, int j, int n) {
        dir = d;
        ii = i;
        jj = j;
        num = n;
    }
};

bool is_valid(int i, int j) {
    if (i < 0 || j < 0 || i >= h || j >= w || mapp[i][j] == 'C') {
        return false;
    }
    return true;
}

bool visit(int i, int j, char dirr) {
    if (dir[used[i][j] - 1] == dirr) {
        return true;
    }
    return false;
}

void gogogo(int i) {
    memset(used, 0, sizeof(used));
    step go(dir[i], sp_i - 1, sp_j - 1, 0);
    now_dir = go.dir;
    for (int j = 0; j < 4; j++) {
        if (go.dir == dir[j]) {
            used[go.ii][go.jj] = j + 1;
        }
    }
    while (1) {
        if (go.dir == 'U') {
            go.ii--;
        } else if (go.dir == 'R') {
            go.jj++;
        } else if (go.dir == 'D') {
            go.ii++;
        } else {
            go.jj--;
        }
        go.num++;
        if (used[go.ii][go.jj] && visit(go.ii, go.jj, go.dir)) {
            printf("%c\n", now_dir);
            indefinition = true;
            break;
        }
        if (go.dir == 'U') {
            used[go.ii][go.jj] = 1;
        } else if (go.dir == 'R') {
            used[go.ii][go.jj] = 2;
        } else if (go.dir == 'D') {
            used[go.ii][go.jj] = 3;
        } else {
            used[go.ii][go.jj] = 4;
        }
        if (!is_valid(go.ii, go.jj)) {
            break;
        }
        if (mapp[go.ii][go.jj] == '\\') {
            if (go.dir == 'U') {
                go.dir = 'L';
            } else if (go.dir == 'R') {
                go.dir = 'D';
            } else if (go.dir == 'D') {
                go.dir = 'R';
            } else {
                go.dir = 'U';
            }
        } else if (mapp[go.ii][go.jj] == '/') {
            if (go.dir == 'U') {
                go.dir = 'R';
            } else if (go.dir == 'R') {
                go.dir = 'U';
            } else if (go.dir == 'D') {
                go.dir = 'L';
            } else {
                go.dir = 'D';
            }
        }
    }
    if (go.num > max) {
        max = go.num;
        max_dir = now_dir;
    }
}
    
int main() {
    scanf("%d %d\n", &h, &w);
    for (int i = 0; i < h; i++) {
        gets(mapp[i]);
    }
    scanf("%d %d", &sp_i, &sp_j);
    for (int i = 0; i < 4; i++) {
        gogogo(i);
        if (indefinition) {
            printf("Voyager\n");
            return 0;
        }
    }
    printf("%c\n%d\n", max_dir, max);
    return 0;
}                                 
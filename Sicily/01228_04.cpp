// Problem#: 1228
// Submission#: 2827469
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

//0->east, 1->south, 2->west, 3->north

int robots, w, h, moves;
bool mapp[101][101];

struct Robot {
    int ii;
    int jj;
    int dir;
};

Robot r[105];

int find_robot(int i, int j, int this_robot) {
    for (int k = 1; k <= robots; k++) {
        if (r[k].ii == i && r[k].jj == j && k != this_robot) {
            return k;
        }
    }
}

int move(int r_num, char control, int times) {
    int s_i = r[r_num].ii;
    int s_j = r[r_num].jj;
    if (control == 'F') {
        if (r[r_num].dir == 0) {
            for (int i = 0; i < times; i++) {
                r[r_num].jj++;
                if (mapp[r[r_num].ii][r[r_num].jj] && r[r_num].jj < w) {
                    return find_robot(r[r_num].ii, r[r_num].jj, r_num);
                }
                if (r[r_num].jj == w) {
                    return -1;
                }
            }
            mapp[r[r_num].ii][r[r_num].jj] = 1;
            mapp[s_i][s_j] = 0;
        } else if (r[r_num].dir == 1) {
            for (int i = 0; i < times; i++) {
                r[r_num].ii--;
                if (mapp[r[r_num].ii][r[r_num].jj] && r[r_num].ii >= 0) {
                    return find_robot(r[r_num].ii, r[r_num].jj, r_num);
                }
                if (r[r_num].ii == -1) {
                    return -1;
                }
            }
            mapp[r[r_num].ii][r[r_num].jj] = 1;
            mapp[s_i][s_j] = 0;
        } else if (r[r_num].dir == 2) {
            for (int i = 0; i < times; i++) {
                r[r_num].jj--;
                if (mapp[r[r_num].ii][r[r_num].jj] && r[r_num].jj >= 0) {
                    return find_robot(r[r_num].ii, r[r_num].jj, r_num);
                }
                if (r[r_num].jj == -1) {
                    return -1;
                }
            }
            mapp[r[r_num].ii][r[r_num].jj] = 1;
            mapp[s_i][s_j] = 0;
        } else {
            for (int i = 0; i < times; i++) {
                r[r_num].ii++;
                if (mapp[r[r_num].ii][r[r_num].jj] && r[r_num].ii < h) {
                    return find_robot(r[r_num].ii, r[r_num].jj, r_num);
                }
                if (r[r_num].ii == h) {
                    return -1;
                }
            }
            mapp[r[r_num].ii][r[r_num].jj] = 1;
            mapp[s_i][s_j] = 0;
        }
    } else if (control == 'L') {
        r[r_num].dir = (r[r_num].dir + 104 - times) % 4;
    } else {
        r[r_num].dir = (r[r_num].dir + times) % 4;
    }
    return -2;
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        memset(mapp, 0, sizeof(mapp));
        scanf("%d%d%d%d", &w, &h, &robots, &moves);
        for (int i = 1; i <= robots; i++) {
            char temp;
            scanf("%d %d %c", &r[i].jj, &r[i].ii, &temp);
            r[i].jj--;
            r[i].ii--;
            mapp[r[i].ii][r[i].jj] = 1;
            if (temp == 'E') {
                r[i].dir = 0;
            } else if (temp == 'S') {
                r[i].dir = 1;
            } else if (temp == 'W') {
                r[i].dir = 2;
            } else {
                r[i].dir = 3;
            }
        }
        bool is_end = false;
        int r_num, times;
        char control;
        while (moves--) {
            scanf("%d %c %d", &r_num, &control, &times);
            int result = move(r_num, control, times);
            if (result == -1) {
                printf("Robot %d crashes into the wall\n", r_num);
                is_end = true;
                break;
            } else if (result != -2) {
                printf("Robot %d crashes into robot %d\n", r_num, result);
                is_end = true;
                break;
            }
        }
        if (!is_end) {
            printf("OK\n");
        } else {
            for (int i = 0; i < moves; i++) {
                scanf("%d %c %d", &r_num, &control, &times);
            }
        }
    }
    return 0;
}                                 
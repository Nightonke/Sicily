// Problem#: 1228
// Submission#: 2827476
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

//0->east, 1->south, 2->west, 3->north

short robots, w, h, moves;
bool mapp[101][101];

struct Robot {
    short ii;
    short jj;
    short dir;
};

Robot r[101];

short find_robot(short i, short j, short this_robot) {
    for (short k = 1; k <= robots; k++) {
        if (r[k].ii == i && r[k].jj == j && k != this_robot) {
            return k;
        }
    }
}

short move(short r_num, char control, short times) {
    short s_i = r[r_num].ii;
    short s_j = r[r_num].jj;
    if (control == 'F') {
        if (r[r_num].dir == 0) {
            for (short i = 0; i < times; i++) {
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
            for (short i = 0; i < times; i++) {
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
            for (short i = 0; i < times; i++) {
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
            for (short i = 0; i < times; i++) {
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
    short case_num;
    scanf("%hd", &case_num);
    while (case_num--) {
        memset(mapp, 0, sizeof(mapp));
        scanf("%hd%hd%hd%hd", &w, &h, &robots, &moves);
        for (short i = 1; i <= robots; i++) {
            char temp;
            scanf("%hd %hd %c", &r[i].jj, &r[i].ii, &temp);
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
        short r_num, times;
        char control;
        while (moves--) {
            scanf("%hd %c %hd", &r_num, &control, &times);
            short result = move(r_num, control, times);
            if (result == -1) {
                printf("Robot %hd crashes into the wall\n", r_num);
                is_end = true;
                break;
            } else if (result != -2) {
                printf("Robot %hd crashes into robot %hd\n", r_num, result);
                is_end = true;
                break;
            }
        }
        if (!is_end) {
            printf("OK\n");
        } else {
            for (short i = 0; i < moves; i++) {
                scanf("%hd %c %hd", &r_num, &control, &times);
            }
        }
    }
    return 0;
}                                 
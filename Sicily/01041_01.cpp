// Problem#: 1041
// Submission#: 4001263
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string.h>
using namespace std;

int h, w, n, counter = 1;
char room[25][25];
char re[25][25];
int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
int edge[4];

bool isValid(int pi, int pj) {
    return 0 <= pi && pi < h && 0 <= pj && pj < w && room[pi][pj] == ' ';
}

bool moveBox(int d, int pi, int pj) {
    int ni = pi + dir[d][0], nj = pj + dir[d][1];
    if (isValid(ni, nj)) {
        room[ni][nj] = room[pi][pj];
        room[pi][pj] = ' ';
        return true;
    }
    else {
        if (0 <= ni && ni < h && 0 <= nj && nj < w) {
            if (moveBox(d, ni, nj)) {
                room[ni][nj] = room[pi][pj];
                room[pi][pj] = ' ';
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
}

void record() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            re[i][j] = room[i][j];
        }
    }
}

void moveBack() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            room[i][j] = re[i][j];
        }
    }
}

void move(int d, int step) {
    for (int i = 1; i <= step; i++) {
        int walli, wallj;
        if (d == 0 || d == 2) {
            walli = edge[d] + i * dir[d][0];
            record();
            for (int j = 0; j < edge[1]; j++) {
                if (room[walli][j] != ' ') {
                    if (moveBox(d, walli, j)) {
                        // move successfully
                    }
                    else {
                        // fail
                        moveBack();
                        return;
                    }
                }
            }
        }
        else {
            wallj = edge[d] + i * dir[d][1];
            record();
            for (int j = 0; j < edge[0]; j++) {
                if (room[j][wallj] != ' ') {
                    if (moveBox(d, j, wallj)) {
                        // move successfully
                    }
                    else {
                        moveBack();
                        // fail
                        return;
                    }
                }
            }
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        cin >> h >> w;
        if (!h && !w) break;

        edge[0] = h;
        edge[1] = w;
        edge[2] = edge[3] = -1;

        memset(room, ' ', sizeof(room));

        cin >> n;
        for (int i = 0; i < n; i++) {
            int pi, pj;
            cin >> pi >> pj;
            room[pi][pj] = 'A' + i;
        }

        while (1) {
            char order[6];
            int step;
            cin >> order;
            if (strcmp(order, "left") == 0) {
                cin >> step;
                move(1, step);
            }
            else if (strcmp(order, "right") == 0) {
                cin >> step;
                move(3, step);
            }
            else if (strcmp(order, "up") == 0) {
                cin >> step;
                move(0, step);
            }
            else if (strcmp(order, "down") == 0) {
                cin >> step;
                move(2, step);
            }
            else if (strcmp(order, "done") == 0) {
                break;
            }
        }

        cout << "Data set " << counter << " ends with boxes at locations";
        counter++;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (room[j][k] != ' ') {
                    cout << " (" << j << "," << k << ")";
                }
            }
        }
        
        cout << ".\n";
    }

    return 0;
}                                 
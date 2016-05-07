// Problem#: 9358
// Submission#: 2811050
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

char mapp[11][11], new_map[11][11];
int h, w, min_h, min_w, max_h, max_w;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

bool is_sea(int i, int j) {
    if (i < 0 || j < 0 || i >= h || j >= w || mapp[i][j] == '.')
        return true;
    return false;
}

bool is_all_sea(bool is_col, int sp, int ep, int num) {
    if (is_col) {
        for (int i = sp; i < ep; i++) {
            if (new_map[i][num] == 'X') {
                return false;
            }
        }
        return true;
    } else {
        for (int i = sp; i < ep; i++) {
            if (new_map[num][i] == 'X') {
                return false;
            }
        }
        return true;
    }
}

void minimize_map() {
    for (int i = min_h; i < max_h; i++) {
        if (is_all_sea(0, min_w, max_w, i)) {
            min_h++;
        } else {
            break;
        }
    }
    for (int i = max_h - 1; i >= min_h; i--) {
        if (is_all_sea(0, min_w, max_w, i)) {
            max_h--;
        } else {
            break;
        }
    }
    for (int i = min_w; i < max_w; i++) {
        if (is_all_sea(1, min_h, max_h, i)) {
            min_w++;
        } else {
            break;
        }
    }
    for (int i = max_w - 1; i >= min_w; i--) {
        if (is_all_sea(1, min_h, max_h, i)) {
            max_w--;
        } else {
            break;
        }
    }
}

int main() {
    
    scanf("%d %d\n", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", mapp[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mapp[i][j] == 'X') {
                int counter = 0;
                for (int k = 0; k < 4; k++) {
                    if (is_sea(i + dir[k][0], j + dir[k][1])) {
                        counter++;
                    }
                }
                if (counter >= 3) {
                    new_map[i][j] = '.';
                } else {
                    new_map[i][j] = 'X';
                }
            } else {
                new_map[i][j] = '.';
            }
        }
    }
    max_h = h;
    max_w = w;
    min_h = 0;
    min_w = 0;
    minimize_map();
    for (int i = min_h; i < max_h; i++) {
        for (int j = min_w; j < max_w; j++) {
            printf("%c", new_map[i][j]);
        }
        printf("\n");
    }
    return 0;
}                                 
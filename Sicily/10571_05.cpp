// Problem#: 10571
// Submission#: 2809763
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char mapp[51][51];
int r, s;
int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
bool used[51][51];

bool is_valid(int ii, int jj) {
    if (ii < 0 || jj < 0 || ii >= r || jj >= s || used[ii][jj] || mapp[ii][jj] == '.')
        return false;
    return true;
}

int is_valid_num(int ii, int jj) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        int temp_ii = ii + dir[i][0];
        int temp_jj = jj + dir[i][1];
        if (is_valid(temp_ii, temp_jj))
            counter++;
    }
    return counter;
}

int main() {
    scanf("%d%d\n", &r, &s);
    for (int i = 0; i < r; i++) {
        gets(mapp[i]);
    }
    int pos_ii, pos_jj;
    int max_valid = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            if (mapp[i][j] == '.' && max_valid < 8 && is_valid_num(i, j) > max_valid) {
                max_valid = is_valid_num(i, j);
                pos_ii = i;
                pos_jj = j;
            }
        }
    }
    if (max_valid != -1) {
        mapp[pos_ii][pos_jj] = 'o';
    }
    int counter = 0;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            if (mapp[i][j] == 'o') {
                for (int k = 0; k < 8; k++) {
                    int temp_ii = i + dir[k][0];
                    int temp_jj = j + dir[k][1];
                    if (is_valid(temp_ii, temp_jj)) {
                        counter++;
                    }
                }
                used[i][j] = true;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}                                 
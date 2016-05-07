// Problem#: 10571
// Submission#: 2809767
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1}, r, s, mapp[51][51];
bool is_valid(int ii, int jj) {
    if (ii < 0 || jj < 0 || ii >= r || jj >= s || !mapp[ii][jj])
        return false;
    return true;
}
int is_valid_num(int ii, int jj) {
    int counter = 0, i;
    for (i = 0; i < 8; i++)
        if (is_valid(ii + dir[i][0], jj + dir[i][1]))
            counter++;
    return counter;
}
int main() {
    int i, j, k, pos_ii, pos_jj, max_valid = -1, counter = 0;
    scanf("%d%d\n", &r, &s);
    char temp[51];
    for (i = 0; i < r; i++) {
        gets(temp);
        for (j = 0; j < s; j++)
            if (temp[j] == '.')
                mapp[i][j] = 0;
            else
                mapp[i][j] = 1;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < s; j++)
            if (mapp[i][j] == 0 && max_valid < 8 && is_valid_num(i, j) > max_valid) {
                max_valid = is_valid_num(i, j);
                pos_ii = i;
                pos_jj = j;
            }
    if (max_valid + 1)
        mapp[pos_ii][pos_jj] = 1;
    for (i = 0; i < r; i++)
        for (j = 0; j < s; j++)
            if (mapp[i][j]) {
                for (k = 0; k < 8; k++)
                    if (is_valid(i + dir[k][0], j + dir[k][1]))
                        counter++;
                mapp[i][j] = 0;
            }
    printf("%d\n", counter);
    return 0;
}                                 
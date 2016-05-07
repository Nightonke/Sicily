// Problem#: 1162
// Submission#: 2741119
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <stdio.h>
using namespace std;



char ans[10][10];
bool num_in_row[10][10], num_in_col[10][10], num_in_blo[10][10];
bool is_ok;
int blank_num, blank_pos_x[85], blank_pos_y[85], blank_pos_blo[85];

int find_block(int x, int y) {
    int block[10][10] = 
    {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 2, 2, 2, 3, 3, 3,
    0, 1, 1, 1, 2, 2, 2, 3, 3, 3,
    0, 1, 1, 1, 2, 2, 2, 3, 3, 3,
    0, 4, 4, 4, 5, 5, 5, 6, 6, 6,
    0, 4, 4, 4, 5, 5, 5, 6, 6, 6,
    0, 4, 4, 4, 5, 5, 5, 6, 6, 6,
    0, 7, 7, 7, 8, 8, 8, 9, 9, 9,
    0, 7, 7, 7, 8, 8, 8, 9, 9, 9,
    0, 7, 7, 7, 8, 8, 8, 9, 9, 9
    };
    return block[x][y];
}

void dfs(int blank_now) {
    if (is_ok == true)
        return;
    if (blank_now == blank_num) {
        is_ok = true;
        return;
    }
    for (int possible = 1; possible <= 9; possible++) {
        if (!num_in_row[blank_pos_x[blank_now]][possible] && 
            !num_in_col[blank_pos_y[blank_now]][possible] &&
            !num_in_blo[blank_pos_blo[blank_now]][possible]) {
                
                ans[blank_pos_x[blank_now]][blank_pos_y[blank_now]] = possible + '0';
                num_in_row[blank_pos_x[blank_now]][possible] = true;
                num_in_col[blank_pos_y[blank_now]][possible] = true;
                num_in_blo[blank_pos_blo[blank_now]][possible] = true;
                dfs(blank_now + 1);
                
                if (is_ok)
                    return;
                
                num_in_row[blank_pos_x[blank_now]][possible] = false;
                num_in_col[blank_pos_y[blank_now]][possible] = false;
                num_in_blo[blank_pos_blo[blank_now]][possible] = false;
        }
    }
}


int main() {
    int case_num, i, j;
    cin >> case_num;
    while (case_num--) {
        blank_num = 0;
        is_ok = false;
        memset(num_in_row, false, sizeof(num_in_row));
        memset(num_in_col, false, sizeof(num_in_col));
        memset(num_in_blo, false, sizeof(num_in_blo));
        for (i = 1; i <= 9; i++) {
            char temp[10];
            cin >> temp;
            for (j = 1; j <= 9; j++) {
                if (temp[j - 1] == '0') {
                    blank_pos_x[blank_num] = i;
                    blank_pos_y[blank_num] = j;
                    blank_pos_blo[blank_num] = find_block(i, j);
                    blank_num++;
                } else {
                    ans[i][j] = temp[j - 1];
                    num_in_row[i][temp[j - 1] - '0'] = true;
                    num_in_col[j][temp[j - 1] - '0'] = true;
                    num_in_blo[find_block(i, j)][temp[j - 1] - '0'] = true;
                }
            }
        }
        dfs(0);
        
        for (i = 1; i <= 9; i++) {
            for (j = 1; j <= 9; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
        
    return 0;
}                                 
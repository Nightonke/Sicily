// Problem#: 1407
// Submission#: 2797031
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

char BOX[1005][15];//
int prev_h;
int w, h_each_b;
int each_box[100];//
int box_num;

bool can_move_down(int h_of_below_p[]) {//
    for (int i = 0; i < w; i++) {
        if (h_of_below_p[i] == 0 || BOX[h_of_below_p[i] - 1][i] == 'X')//
            return false;
    }
    return true;
}

void move(int h_of_below_p[]) {//
    int temp_h;
    for (int i = 0; i < w; i++) {
        for (temp_h = h_of_below_p[i]; BOX[temp_h][i] == 'X'; temp_h++) {//
            BOX[temp_h - 1][i] = BOX[temp_h][i];
        }
        BOX[temp_h - 1][i] = '.';//
    }
}

bool all_point(int now_h) {//
    for (int i = 0; i < w; i++) {
        if (BOX[now_h - 1][i] == 'X')
            return false;
    }
    return true;
}

void fill_in_BOX(int h_each_p) {
    int k = prev_h - 1 + h_each_p;
    for (int i = 0; i < h_each_p; i++) {//
        scanf("%s", BOX[k]);
        k--;
    }
    
    int h_of_below_p[10];//
    for (int i = 0; i < w; i++) {
        h_of_below_p[i] = prev_h;//
    }
    for (int i = 0; i < w; i++) {//
        while (BOX[h_of_below_p[i]][i] == '.')
            h_of_below_p[i]++;
    }
    
    while (can_move_down(h_of_below_p)) {//
        move(h_of_below_p);
        for (int i = 0; i < w; i++) {
            h_of_below_p[i]--;//
        }
    }
    
    int now_h = prev_h + h_each_p;//
    while (all_point(now_h))//
        now_h--;
    
    if (now_h > h_each_b) {//
        each_box[box_num++] = prev_h;//
        for (int i = 0; i < w; i++) {//
            for (int j = h_of_below_p[i] - 1; j >= 0; j--) {
                BOX[j][i] = '.';
            }
        }
        
        while (can_move_down(h_of_below_p)) {//
            move(h_of_below_p);
            for (int i = 0; i < w; i++) {
                h_of_below_p[i]--;
            }
        }
        prev_h = h_each_p;//
    } else if (now_h < h_each_b) {
        prev_h = now_h;//
    } else {
        for (int i = 0; i < w; i++) {//
            for (int j = 0; j <= h_each_b; j++) {
                BOX[j][i] = '.';
            }
        }
        each_box[box_num++] = now_h;//
        prev_h = 0;//
    }
}

bool BOX_is_empty() {
    for (int i = 0; i < w; i++) {//
        if (BOX[0][i] == 'X')
            return false;
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d%d%d", &n, &w, &h_each_b) && n && w && h_each_b) {
        for (int i = 0; i < 1005; i++) {
            for (int j = 0; j < w; j++) {
                BOX[i][j] = '.';
            }
        }
        int h_each_p;//
        prev_h = 0;//
        box_num = 0;//
        for (int i = 0; i < n; i++) {
            scanf("%d", &h_each_p);
            fill_in_BOX(h_each_p);//
        }
        if (!BOX_is_empty())//
            each_box[box_num++] = prev_h;
        for (int i = 0; i < box_num; i++) {//
            if (i != 0)
                printf(" ");
            printf("%d", each_box[i]);
        }
        printf("\n");
    }
    return 0;
}                                 
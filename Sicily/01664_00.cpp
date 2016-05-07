// Problem#: 1664
// Submission#: 2698495
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int is_finish;

bool is_ok_1(int su[10][10], int posx, int posy) {
    int i, j, k = 0, t[10];
    for (j = posx * 3; j < posx * 3 + 3; j++) {
        for (i = posy * 3; i < posy * 3 + 3; i++) {
            t[k++] = su[i][j];
        }
    }
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 9; j++) {
            if (t[i] == t[j] && t[i] != 0 && t[j] != 0)
                return false;
        }
    }
    return true;
}

bool is_ok(int su[10][10], int x, int y, int num) {
    int posx, posy, k, i, j, t[10];
    su[y][x] = num;
    posx = x / 3;
    posy = y / 3;
    if (!is_ok_1(su, posx, posy))
        return false;
    k = 0;
    for (i = 0; i < 9; i++) {
        t[k++] = su[i][x];
    }
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 9; j++) {
            if (t[i] == t[j] && t[i] != 0 && t[j] != 0)
                return false;
        }
    }
    k = 0;
    for (i = 0; i < 9; i++) {
        t[k++] = su[y][i];
    }
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 9; j++) {
            if (t[i] == t[j] && t[i] != 0 && t[j] != 0)
                return false;
        }
    }
    return true;
}

void dfs(int left, int su[10][10]) {
    int i, j, k;
    if (is_finish)
        return;
    if (left == 0) {
        is_finish = 1;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                printf("%d", su[i][j]);
            }
            printf("\n");
        }
    }
    for (i = 0; i < 9 && !is_finish; i++) {
        for (j = 0; j < 9 && !is_finish; j++) {
            if (su[i][j] == 0) {
                for (k = 1; k <= 9 && !is_finish; k++) {
                    if (is_ok(su, j, i, k)) {
                        su[i][j] = k;
                        dfs(left - 1, su);
                    }
                }
            }
        }
    }
}

int main() {
    int blank_line_control = 0, su[10][10], n, i, j;
    char t;
    scanf("%d", &n);
    while (n--) {
        is_finish = 0;
        if (blank_line_control) {
            printf("\n");
        }
        blank_line_control = 1;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%c", &t);
                if (t >= '0' && t <= '9')
                    su[i][j] = t - '0';
                else
                    j--;
            }
        }
        dfs(5, su);
        if (!is_finish)
            printf("Could not complete this grid.\n");
    }
    return 0;
}                                 
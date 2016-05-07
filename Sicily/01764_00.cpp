// Problem#: 1764
// Submission#: 2762686
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char box[6][8] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."};
    
int main() {
    char pic[1000][1000];
    int map[55][55];
    int w, l, i, j, h, key_point_i, key_point_j, max_height_pic, max_width_pic, t1, t2;
    while (~scanf("%d%d", &w, &l)) {
        for (i = 0; i < w; i++) {
            for (j = 0; j < l; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        memset(pic, '.', sizeof(pic));
        max_height_pic = 0;
        max_width_pic = 0;
        for (i = 0; i < w; i++) {
            for (j = 0; j < l; j++) {
                for (h = 0; h < map[i][j]; h++) {
                    key_point_i = (w - i - 1) * 2 + h * 3;
                    key_point_j = j * 4 + (w - i - 1) * 2;
                    if (key_point_i + 5 > max_height_pic)
                        max_height_pic = key_point_i + 5;
                    if (key_point_j + 6 > max_width_pic)
                        max_width_pic = key_point_j + 6;
                    for (t1 = 5; t1 >= 0; t1--) {
                        for (t2 = 0; t2 <= 6; t2++) {
                            if (box[t1][t2] != '.')
                                pic[key_point_i + 5 - t1][key_point_j + t2] = box[t1][t2];
                        }
                    }
                }
            }
        }
        for (i = max_height_pic; i >= 0; i--) {
            for (j = 0; j <= max_width_pic; j++) {
                printf("%c", pic[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}                                 
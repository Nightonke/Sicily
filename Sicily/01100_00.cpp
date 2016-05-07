// Problem#: 1100
// Submission#: 2800676
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int string_to_num(char point_char) {
    if (point_char == '0') {
        return 0;
    } else if (point_char == '1') {
        return 15;
    } else if (point_char == '3') {
        return 30;
    } else if (point_char == '4') {
        return 40;
    }
}

int finish_set(int a, int b, int set_num) {
    if (a < 6 && b < 6)
        return set_num;
    else if (a - b >= 2 || b - a >= 2)
        return set_num + 1;
    else
        return set_num;
}

void output(char a[], char b[], int ab[2][4], int now_set_num) {
    if (now_set_num >= 3) {
        int ap = 0, bp = 0;
        for (int i = 0; i < 3; i++) {
            if (ab[0][i] > ab[1][i])
                ap++;
            else
                bp++;
        }
        if (ap > bp)
            printf("%s won\n", a);
        else
            printf("%s won\n", b);
    } else if (now_set_num <= 1) {
        printf("Match in progress\n");
    } else if (now_set_num == 2) {
        int ap = 0, bp = 0;
        for (int i = 0; i < 2; i++) {
            if (ab[0][i] > ab[1][i])
                ap++;
            else
                bp++;
        }
        if (ap == bp)
            printf("Match in progress\n");
        else if (ap == 0)
            printf("%s won\n", b);
        else if (bp == 0)
            printf("%s won\n", a);
    }
}

int main() {
    
    char player_a[100], player_b[100];
    
    while (scanf("%s", player_a) && strcmp(player_a, "quit")) {
        
        bool server_is_a = true;
        scanf("%s", player_b);
        char point_s[10], point_r[10];
        int point_s_game = 0, point_r_game = 0;
        int ab_point[2][4];
        int now_set_num = 0;
        memset(ab_point, 0, sizeof(ab_point));
        
        while (scanf("%s", point_s) && strcmp(point_s, "done")) { // a match
            
            if ('0' <= point_s[0] && point_s[0] <= '9') {
                point_s_game = string_to_num(point_s[0]);
                scanf("%s", point_r);
                point_r_game = string_to_num(point_r[0]);
            } else if (!strcmp(point_s, "deuce")) {
                point_s_game = point_r_game = 40;
            } else if (!strcmp(point_s, "ad-in")) {
                point_s_game = 99;
            } else if (!strcmp(point_s, "ad-out")) {
                point_r_game = 99;
            } else if (!strcmp(point_s, "game")) {
                if ((point_s_game > point_r_game) ^ server_is_a) {
                    ab_point[1][now_set_num]++;
                } else {
                    ab_point[0][now_set_num]++;
                }
                now_set_num = finish_set(ab_point[0][now_set_num], ab_point[1][now_set_num], now_set_num);
                server_is_a = !server_is_a;
            }
            
        }
        
        if (!strcmp(point_s, "done")) {
            printf("%s-%s\n", player_a, player_b);
            for (int i = 0; ab_point[0][i] || ab_point[1][i]; i++) {
                if (i != 0)
                    printf(" ");
                printf("%d-%d", ab_point[0][i], ab_point[1][i]);
            }
            printf("\n");
            output(player_a, player_b, ab_point, now_set_num);
            printf("\n");
        }
        
    }
    return 0;
}                                 
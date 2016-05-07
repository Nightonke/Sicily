// Problem#: 1031
// Submission#: 2775789
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#define INF 99999999
#define MAX 115 * 2

int total_num_of_name, map[MAX][MAX];
char num_of_name[MAX][MAX];

int min(int a, int b) {
    return a > b ? b : a;
}

void make_map(char f[], char t[], int dis) {
    int i, t_num, f_num;
    
    for (i = 0; i < total_num_of_name; i++) {
        if (strcmp(f, num_of_name[i]) == 0) {
            f_num = i;
            break;
        }
    }
    if (i >= total_num_of_name) {
        f_num = total_num_of_name;
        strcpy(num_of_name[total_num_of_name++], f);
    }
    
    for (i = 0; i < total_num_of_name; i++) {
        if (strcmp(t, num_of_name[i]) == 0) {
            t_num = i;
            break;
        }
    }
    if (i >= total_num_of_name) {
        t_num = total_num_of_name;
        strcpy(num_of_name[total_num_of_name++], t);
    }
    
    map[f_num][t_num] = dis < map[f_num][t_num] ? dis : map[f_num][t_num];
    map[t_num][f_num] = dis < map[t_num][f_num] ? dis : map[t_num][f_num];
}

int find_num(char a[]) {
    for (int i = 0; i < total_num_of_name; i++) {
        if (strcmp(a, num_of_name[i]) == 0)
            return i;
    }
    return -1;
}

void Floyd_Warshall() {
    int i, j, k;
    for (i = 0; i < MAX; i++) {
        map[i][i] = 0;
    }
    for (k = 0; k < total_num_of_name; k++) {
        for (i = 0; i < total_num_of_name; i++) {
            for (j = 0; j < total_num_of_name; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
}

int main() {
    int case_num, n, dis, f_num, t_num;
    char temp_f[MAX], temp_t[MAX];
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d", &n);
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                map[i][j] = INF;
            }
        }
        memset(num_of_name, '\0', sizeof(num_of_name));
        total_num_of_name = 0;
        while (n--) {
            memset(temp_f, '\0', sizeof(temp_f));
            memset(temp_t, '\0', sizeof(temp_t));
            scanf("%s %s %d", temp_f, temp_t, &dis);
            make_map(temp_f, temp_t, dis);
        }
        scanf("%s%s", &temp_f, &temp_t);
        if (strcmp(temp_f, temp_t) == 0) {
            printf("0\n");
            continue;
        }
        f_num = find_num(temp_f);
        t_num = find_num(temp_t);
        if (f_num == -1 || t_num == -1) {
            printf("-1\n");
            continue;
        }
        Floyd_Warshall();
        printf("%d\n", map[f_num][t_num] >= INF ? -1 : map[f_num][t_num]);

    }
    return 0;
}                                 
// Problem#: 1396
// Submission#: 2804179
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int case_num;
    scanf("%d", &case_num);
    while (case_num--) {
        int m, n;
        scanf("%d%d", &m, &n);
        char from[20][9], to[20][9];
        bool used[20];
        int from_pos, to_pos;
        for (int i = 0; i < m; i++) {
            scanf("%s", from[i]);
            used[i] = false;
            to[i][0] = '\0';
        }
        while (n--) {
            scanf("%d%d", &from_pos, &to_pos);
            strcpy(to[to_pos - 1], from[from_pos - 1]);
            used[from_pos - 1] = true;
        }
        for (int i = 0, j = 0; i < m; i++) {
            if (!used[i]) {
                for (; j < m; j++) {
                    if (to[j][0] == '\0') {
                        strcpy(to[j], from[i]);
                        j++;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (i) {
                printf(" ");
            }
            printf("%s", to[i]);
        }
        printf("\n");
    }
    return 0;
}                                 
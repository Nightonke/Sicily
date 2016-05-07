// Problem#: 1155
// Submission#: 2572755
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, n, r[201][201], i, temp1, temp2, kongzhi, k, j;
    while (scanf("%d", &t), t) {
        scanf("%d", &n);
        memset(r, 0, sizeof(r));
        for (i = 0; i < n; i++) {
            scanf("%d %d", &temp1, &temp2);
            r[temp1][temp2] = 1;
        }
        kongzhi = 1;
        for (k = 0; k < t && kongzhi; k++) {
            for (i = 0; i < t && kongzhi; i++) {
                for (j = 0; j < t && kongzhi; j++) {
                    if (r[i][k] == 1 && r[k][j] == 1)
                        r[i][j] = 1;
                    if (r[0][t - 1] == 1)
                        kongzhi = 0;
                }
            }
        }
        if (!kongzhi)
            printf("I can post the letter\n");
        else
            printf("I can't post the letter\n");
    }
    return 0;
}                                 
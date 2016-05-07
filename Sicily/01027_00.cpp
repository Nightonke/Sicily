// Problem#: 1027
// Submission#: 2452672
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, i, j, k;
    char a[30][20], b[30][20], mj[30][20], name[30][20], zj[20];
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        k = 0;
        for (i = 0; i < n; i++)
            scanf("%s %s", &a[i], &b[i]);
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++) {
                if (strcmp(b[j], b[i]) == 0 && strcmp(b[j], "no use") != 0) {
                    strcpy(name[k], a[i]);
                    strcpy(mj[k], a[j]);
                    k = k + 1;
                    strcpy(b[j], "no use");
                    strcpy(b[i], "no use");
                    break;
                }
            }
        for (i = 0; i < n / 2; i++)
            for (j = 0; j < n / 2 - 1; j++) {
                if (strcmp(name[j], name[j + 1]) > 0) {
                    strcpy(zj, name[j + 1]);
                    strcpy(name[j + 1], name[j]);
                    strcpy(name[j], zj);
                    strcpy(zj, mj[j + 1]);
                    strcpy(mj[j + 1], mj[j]);
                    strcpy(mj[j], zj);
                }
            }
        for (i = 0; i < n / 2; i++)
            printf("%s is the MaJia of %s\n", mj[i], name[i]);
        printf("\n");
    }
    return 0;
}                                 
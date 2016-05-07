// Problem#: 1177
// Submission#: 2583926
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i = 0, j, flag;
    float a[1000][3];
    char c, b[1000][100], d[1000][100];
    while (1) {
        scanf("%f", &a[i][0]);
        if (a[i][0] == -1)
            break;
        scanf("%s %f ", b[i], &a[i][1]);
        j = 0;
        while (1) {
            c = getchar();
            if (c == '\n')
                break;
            d[i][j++] = c;
        }
        i++;
    }
    flag = 0;
    for (j = 0; j < i; j++) {
        if (a[j][0] / a[j][1] >= 0.01) {
            printf("%s %.1f %s %.0f%%\n", d[j], a[j][0], b[j], 100 * a[j][0] / a[j][1]);
        }
        if (a[j][0] / a[j][1] < 0.01)
            flag = 1;
    }
    if (flag) {
        printf("Provides no significant amount of:\n");
        for (j = 0; j < i; j++)
            if (a[j][0] / a[j][1] < 0.01)
                printf("%s\n", d[j]);
    }
    return 0;
}                                 
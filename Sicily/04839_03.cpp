// Problem#: 4839
// Submission#: 2813882
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int a[10001][4];

int main() {
    int n, t1, t2, i, j;
    char temp[40];
    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
        gets(temp);
        t1 = t2 = 0;
        for (j = 0; temp[j] != ' '; j++) {
            a[i][0] = a[i][0] * 10 + temp[j] - '0';
        }
        j++;
        for (; temp[j] != ' '; j++) {
            a[i][1] = a[i][1] * 10 + temp[j] - '0';
        }
        j++;
        for (; temp[j] != ' '; j++) {
            t1 = t1 * 10 + temp[j] - '0';
        }
        j++;
        for (; temp[j] != '\0'; j++) {
            t2 = t2 * 10 + temp[j] - '0';
        }
        a[i][2] = a[i][0] + t1;
        a[i][3] = a[i][1] + t2;
    }
    int px, py;
    scanf("%d%d", &px, &py);
    for (i = n - 1; i >= 0; i--) {
        if (a[i][0] <= px && px <= a[i][2] && a[i][1] <= py && py <= a[i][3]) {
            printf("%d\n", i + 1);
            break;
        }
    }
    if (i < 0) {
        printf("-1\n");
    }
    return 0;
}                                 
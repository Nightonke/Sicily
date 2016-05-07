// Problem#: 4839
// Submission#: 2813877
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int a[10001][4];

int main() {
    int n, t1, t2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a[i][0], &a[i][1], &t1, &t2);
        a[i][2] = a[i][0] + t1;
        a[i][3] = a[i][1] + t2;
    }
    int px, py, i;
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
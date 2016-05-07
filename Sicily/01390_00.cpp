// Problem#: 1390
// Submission#: 2454789
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int length, i, j, k, m, kongzhi;
    char a[100], b[100][3];
    while (1) {
        scanf("%s", a);
        if (a[0] == '*')
            break;
        length = strlen(a);
        kongzhi = 0;
        if (length == 1 || length == 2 || (length == 3) && (a[0] != a[1])) {
            printf("%s is surprising.\n", a);
            continue;
        }
        for (i = 0; i < length - 2 && kongzhi == 0; i++) {
            k = 0;
            for (j = 0; j < length - i - 1; j++) {
                b[k][0] = a[j];
                b[k][1] = a[j + i + 1];
                k++;
            }
            for (j = 0; j < length - i - 2 && kongzhi == 0; j++)
                for (m = j + 1; m < length - i - 1 && kongzhi == 0; m++) {
                    if (b[j][0] == b[m][0] && b[j][1] == b[m][1]) {
                        printf("%s is NOT surprising.\n", a);
                        kongzhi = 1;
                    }
                }
        }
        if (kongzhi == 0)
            printf("%s is surprising.\n", a);
    }
    return 0;
}                                 
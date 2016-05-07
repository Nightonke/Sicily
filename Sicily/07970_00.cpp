// Problem#: 7970
// Submission#: 2462530
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {
    int i, t, length, wide, k, j;
    char b[110][110], a[10010];
    scanf("%d\n", &t);
    while (t--) {
        gets(a);
        length = strlen(a);
        wide = (int)sqrt(length);
        k = 0;
        for (i = 0; i < wide; i++)
            for (j = 0; j < wide; j++) {
                b[i][j] = a[k];
                k++;
            }
        for (j = wide - 1; j >= 0; j--)
            for (i = 0; i < wide; i++) {
                printf("%c", b[i][j]);
            }
        printf("\n");
    }
    return 0;
}                                 
// Problem#: 1372
// Submission#: 2453488
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int i, t, length, j;
    char a[110][110];
    scanf("%d", &t);
    for (i = 0; i < t; i++)
        scanf("%s", &a[i]);
    for (i = 0; i < t; i++) {
        if (a[i][0] == 'a' || a[i][0] == 'e' || a[i][0] == 'i' || a[i][0] == 'o' || a[i][0] == 'u') {
            strcat(a[i], "cow");
        }
        else {
            length = strlen(a[i]);
            a[i][length] = a[i][0];
            for (j = 0; j < length; j++) {
                a[i][j] = a[i][j + 1];
            }
            a[i][length] = '\0';
            strcat(a[i], "ow");
        }
        printf("%s\n", a[i]);
    }
    return 0;
}                                 
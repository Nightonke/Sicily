// Problem#: 2405
// Submission#: 2470137
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int length, i, j, kongzhi;
    char a[10000], b[10000];
    while (1) {
        kongzhi = 0;
        gets(a);
        if (a[0] == '#')
            break;
        length = strlen(a);
        j = length - 1;
        for (i = 0; i < length; i++) {
            b[i] = a[j];
            j--;
            if (b[i] != 'b' && b[i] != 'd' && b[i] != 'q' && b[i] != 'p' && b[i] != 'i' && b[i] != 'o' && b[i] != 'v' && b[i] != 'w' && b[i] != 'x') {
                printf("INVALID\n");
                kongzhi = 1;
                break;
            }
            if (b[i] == 'd') {
                b[i] = 'b';
                continue;
            }
            if (b[i] == 'b') {
                b[i] = 'd';
                continue;
            }
            if (b[i] == 'q') {
                b[i] = 'p';
                continue;
            }
            if (b[i] == 'p') {
                b[i] = 'q';
                continue;
            }
        }
        if (kongzhi == 0) {
        for (i = 0; i < length; i++)
            printf("%c", b[i]);
        printf("\n");
        }
    }
    return 0;
}                                 
// Problem#: 1324
// Submission#: 2362977
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    int n, score = 0, i = 1;
    char c;
    scanf("%d", &n);
    n = n + 1;
    while (n--) {
        c = getchar();
        if (c == '\n')
            continue;
        while (1) {
            if (c == 'O') {
            score = score + i;
            i++;}
        if (c == 'X')
            i = 1;
        c = getchar();
        if (c == '\n')
            break;
        }
        printf("%d\n", score);
        score = 0;
        i = 1;
    }
    return 0;
}                                 
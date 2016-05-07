// Problem#: 1530
// Submission#: 2521538
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    char a;
    while (1) {
        a = getchar();
        if (a == '#')
            break;
        if (a == ' ') {
            printf("%%20");
            continue;
        }
        if (a == '!') {
            printf("%%21");
            continue;
        }
        if (a == '$') {
            printf("%%24");
            continue;
        }
        if (a == '%') {
            printf("%%25");
            continue;
        }
        if (a == '(') {
            printf("%%28");
            continue;
        }
        if (a == ')') {
            printf("%%29");
            continue;
        }
        if (a == '*') {
            printf("%%2a");
            continue;
        }
        printf("%c", a);
        
    }
    return 0;
}                                 
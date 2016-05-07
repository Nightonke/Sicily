// Problem#: 14513
// Submission#: 3732655
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {

    int d = 0, j = 0;
    char c;

    while (~scanf("%c", &c))
        if (c == '\n') {
            while (~scanf("%c", &c) && c != '\n') d++;
            printf(d > j ? "no\n" : "go\n");
            d = j = 0;
        }
        else j++;

    return 0;
}                                 
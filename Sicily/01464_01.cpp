// Problem#: 1464
// Submission#: 2592974
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int judge(int top, int bottom) {
    int ntop, nbottom;
    ntop = top / 10;
    nbottom = bottom % 100;
    if (top * nbottom == ntop * bottom && top % 10 == bottom / 100 && top != bottom)
        return 1;
    return 0;
}

int main() {
    int top, bottom;
    for (top = 100; top < 1000; top++) {
        for (bottom = 100; bottom < 1000; bottom++) {
            if (judge(top, bottom) == 1)
                printf("%d / %d = %d / %d\n", top, bottom, top / 10, bottom % 100);
        }
    }
    return 0;
}                                 
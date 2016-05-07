// Problem#: 1746
// Submission#: 2521202
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int x1, y1, x2, y2, maxx, maxy, minx, miny, counter, i, j;
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
        maxx = max(x1, x2);
        maxy = max(y1, y2);
        minx = min(x1, x2);
        miny = min(y1, y2);
        counter = 0;
        for (i = minx; i <= maxx; i++) {
            for (j = miny; j <= maxy; j++) {
                if ((y1 - j) * (x2 - i) == (y2 - j) * (x1 - i) && (!(i == x1 && j == y1)) && (!(i == x2 && j == y2)))
                    counter++;
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 
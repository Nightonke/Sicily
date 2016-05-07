// Problem#: 1795
// Submission#: 2380156
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    double d1, d2, d3;
    int t, n, x, y, counter = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &x, &y);
            d1 = sqrt((x - 30)*(x - 30)+(y - 30)*(y - 30));
            d2 = sqrt((x - 100)*(x - 100)+(y - 30)*(y - 30));
            d3 = sqrt((x - 170)*(x - 170)+(y - 30)*(y - 30));
            if (d1 < 20)
                counter = counter + 1;
            if (d2 < 10)
                counter = counter + 2;
            if (d3 < 5)
                counter = counter + 3;
        }
        printf("%d\n", counter);
        counter = 0;
    }
    return 0;
}                                 
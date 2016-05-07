// Problem#: 2660
// Submission#: 3593148
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

int main() {
    int w, h;
    while (scanf("%d%d", &w, &h), w) printf("%.0lf\n", sqrt(9.0 * h * h + w * w));
    return 0;
}                                 
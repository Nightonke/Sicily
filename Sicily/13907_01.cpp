// Problem#: 13907
// Submission#: 3660104
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    int a1, b1, a2, b2, a3, b3, a4, b4;
    double g = 0, e = 0;
    scanf("%d%d%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3, &a4, &b4);
    for (int i = a1; i <= b1; i++)
        for (int j = a2; j <= b2; j++) g += i + j;
    for (int i = a3; i <= b3; i++)
        for (int j = a4; j <= b4; j++) e += i + j;
    printf(g / ((b1 - a1 + 1) * (b2 - a2 + 1)) > e / ((b4 - a4 + 1) * (b3 - a3 + 1)) ? "Gunnar\n" : (g / ((b1 - a1 + 1) * (b2 - a2 + 1)) < e / ((b4 - a4 + 1) * (b3 - a3 + 1)) ? "Emma\n" : "Tie\n"));
    return 0;
}                                 
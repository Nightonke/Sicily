// Problem#: 1153
// Submission#: 3996813
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int r[64] = {
        28, 18,  1, 11, 21,  6, 16, 31, 
        37, 47, 64, 54, 44, 59, 49, 34, 
        51, 57, 42, 36, 53, 63, 48, 38, 
        23,  8, 14, 29, 12,  2, 17, 27, 
        10,  4, 19, 25, 35, 41, 58, 52, 
        46, 61, 55, 40, 30, 24,  7, 13, 
         3,  9, 26, 20,  5, 15, 32, 22, 
        39, 56, 62, 45, 60, 50, 33, 43}, n;
    while (scanf("%d", &n) && n+1) {
        for (int i = 0; i < 64; i++) {
            if (r[i] == n) {
                for (int j = 0; j < 64; j++) {
                    if (j) printf(" ");
                    printf(" %d", r[(i + j) % 64]);
                }
                break;
            }
        }
    }
    return 0;
}                                 
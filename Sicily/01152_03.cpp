// Problem#: 1152
// Submission#: 2798932
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int r[60] = {1, 14, 25, 21, 29, 18, 5, 16, 27, 19, 8, 4, 12, 23, 10, 6, 17, 30, 22, 26, 13, 2, 15, 28, 24, 11, 3, 7, 20, 9, 1, 14, 25, 21, 29, 18, 5, 16, 27, 19, 8, 4, 12, 23, 10, 6, 17, 30, 22, 26, 13, 2, 15, 28, 24, 11, 3, 7, 20, 9}, n, j;
    while (scanf("%d", &n) && n != -1) {
        for (int i = 0; i < 30; i++) {
            if (n == r[i]) {
                printf("%d", r[i]);
                j = i + 1;
                while (j < i + 30) {
                    
                    printf(" %d", r[j]);
                    j++;
                    
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}                                 
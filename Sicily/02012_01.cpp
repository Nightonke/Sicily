// Problem#: 2012
// Submission#: 2753897
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, i, j, temp_num, king, max;
    char temp[1001];
    while (~scanf("%d\n", &n)) {
        for (i = 0, max = 0, king = 0; i < n; i++) {
            gets(temp);
            for (j = 0, temp_num = 0; j < n; j++) {
                if (temp[j] & 1)
                    temp_num++;
            }
            if (temp_num > max) {
                max = temp_num;
                king = i;
            }
        }
        printf("%d\n", king + 1);
    }
    return 0;
}                                 
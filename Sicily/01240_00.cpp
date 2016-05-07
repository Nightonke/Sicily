// Problem#: 1240
// Submission#: 2795986
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    char num[15];
    while (gets(num)) {
        if (num[0] == '0')
            break;
        printf("%s: ", num);
        int base = pow(9, strlen(num) - 1);
        int sum = 0;
        for (int i = 0; num[i] != '\0'; i++) {
            if (num[i] > '4')
                num[i]--;
            sum += (num[i] - '0') * base;
            base /= 9;
        }
        printf("%d\n", sum);
    }
    return 0;
}                                 
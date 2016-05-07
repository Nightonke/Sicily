// Problem#: 1761
// Submission#: 2699266
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int temp, i;
    char a[20];
    while (scanf("%s", a) == 1) {
        temp = ((a[0] - '0') * 1 + (a[2] - '0') * 2 + (a[3] - '0') * 3 + (a[4] - '0') * 4 + (a[6] - '0') * 5 + (a[7] - '0') * 6 + (a[8] - '0') * 7 + (a[9] - '0') * 8 + (a[10] - '0') * 9) % 11;
        if (temp == 10 && a[12] == 'X') {
            printf("Right\n");
            continue;
        }
        else if (temp == 10 && a[12] != 'X') {
            for (i = 0; i < 12; i++) {
                printf("%c", a[i]);
            }
            printf("X\n");
            continue;
        }
        else if (temp != 10 && temp == a[12] - '0') {
            printf("Right\n");
            continue;
        }
        else if (temp != 10 && temp != a[12] - '0') {
            for (i = 0; i < 12; i++) {
                printf("%c", a[i]);
            }
            printf("%d\n", temp);
            continue;
        }
    }
    return 0;
}                                 
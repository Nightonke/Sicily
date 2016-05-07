// Problem#: 9456
// Submission#: 2772464
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char a[100005];

int main() {
    int right = 0, left = 0;
    gets(a);
    for (int i = 0; i < (int)strlen(a); i++) {
        if (a[i] == '(') {
            left++;
        } else {
            left--;
        }
        if (left < 0) {
            right++;
            left = 0;
        }
    }
    if (right == 0) {
        if (left == 0) {
            printf("0\n");
        } else if (left > 0) {
            printf("%d\n", left / 2);
        }
    } else {
        if (left == 0) {
            printf("%d\n", right / 2);
        } else if (left > 0) {
            if (left == right) {
                if (left % 2 == 0) {
                    printf("%d\n", left);
                } else {
                    printf("%d\n", left + 1);
                }
            } else {
                if (left % 2 == 0) {
                    printf("%d\n", left / 2 + right / 2);
                } else {
                    printf("%d\n", (left - 1) / 2 + (right - 1) / 2 + 2);
                }
            }
        }
    }
    return 0;
}                                 
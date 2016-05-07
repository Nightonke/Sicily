// Problem#: 4868
// Submission#: 2811605
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    char num[15];
    int head;
    scanf("%s", &num);
    if (num[0] == '-') {
        printf("-");
        head = 1;
    } else {
        head = 0;
    }
    char new_num[15];
    int i, j = 0;
    for (i = (int)strlen(num) - 1; i >= head; i--) {
        new_num[j++] = num[i];
    }
    new_num[j] = '\0';
    if (new_num[0] == '0' && new_num[1] == '\0') {
        printf("0");
    } else {
        for (i = 0; i < j; i++) {
            if (new_num[i] != '0') {
                break;
            }
        }
        for (; i < j; i++) {
            printf("%c", new_num[i]);
        }
    }
    printf("\n");
    return 0;
}                                 
// Problem#: 5295
// Submission#: 2815705
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char temp[1005];

int go_what(int sp) {
    for (int i = sp - 1; i >= 3; i--) {
        if (temp[i - 3] == 'W' && temp[i - 2] == 'h' && temp[i - 1] == 'a' && temp[i] == 't') {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    gets(temp);
    for (int i = 0; i < (int)strlen(temp); i++) {
        if (temp[i] == '?') {
            int what_pos = go_what(i);
            printf("Forty-two");
            for (int j = what_pos; j < i; j++) {
                printf("%c", temp[j]);
            }
            printf(".\n");
        }
    }
    return 0;
}                                 
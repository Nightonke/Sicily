// Problem#: 5295
// Submission#: 2815712
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

char temp[1005];
int i, j, k, what_pos;

int main() {
    gets(temp);
    for (i = 0; temp[i] - '\0'; i++)
        if (temp[i] == '?') {
            for (k = i - 1; k>= 3; k--)
                if (temp[k - 3] == 'W' && temp[k - 2] == 'h' && temp[k - 1] == 'a' && temp[k] == 't') {
                    what_pos = k + 1;
                    break;
                }
            printf("Forty-two");
            for (j = what_pos; j < i; j++)
                printf("%c", temp[j]);
            printf(".\n");
        }
    return 0;
}                                 
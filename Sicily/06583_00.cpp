// Problem#: 6583
// Submission#: 2651916
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int judge(char s[]) {
    if (s[0] == '>' && s[1] == '\0')
    return 1;
    if (s[0] == '>' && s[1] == '=')
    return 2;
    if (s[0] == '<' && s[1] == '\0')
    return 3;
    if (s[0] == '<' && s[1] == '=')
    return 4;
    if (s[0] == '=' && s[1] == '=')
    return 5;
    if (s[0] == '!' && s[1] == '=')
    return 6;
}

void print(int i, int counter, int a, int b) {
    printf ("Case %d: ", counter);
    if (i == 1) {
        if (a > b)
        printf("true\n");
        else
        printf("false\n");
    }
    if (i == 2) {
        if (a >= b)
        printf("true\n");
        else
        printf("false\n");
    }
    if (i == 3) {
        if (a < b)
        printf("true\n");
        else
        printf("false\n");
    }
    if (i == 4) {
        if (a <= b)
        printf("true\n");
        else
        printf("false\n");
    }
    if (i == 5) {
        if (a == b)
        printf("true\n");
        else
        printf("false\n");
    }
    if (i == 6) {
        if (a != b)
        printf("true\n");
        else
        printf("false\n");
    }
}
            
int main() {
    int counter = 0, a, b;
    char s[3];
    while (1) {
        counter++;
        s[0] = s[1] = '\0';
        scanf("%d %s %d", &a, s, &b);
        if (s[0] == 'E')
        break;
        print(judge(s), counter, a, b);
    }
    return 0;
}                                 
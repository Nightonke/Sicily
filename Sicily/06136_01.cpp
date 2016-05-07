// Problem#: 6136
// Submission#: 2811354
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char temp[5][501];
int num[5];

void judge(int col) {
    int counter = 0;
    for (int i = 1; i <= 4; i++) {
        if (temp[i][col] == '*') {
            counter++;
        }
    }
    num[counter]++;
}

int main() {
    int h, w;
    scanf("%d %d\n", &h, &w);
    memset(num, 0, sizeof(num));
    while (h--) {
        for (int i = 0; i < 5; i++) {
            gets(temp[i]);
        }
        for (int i = 0; i < w; i++) {
            judge(i * 5 + 1);
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i)
            printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}                                 
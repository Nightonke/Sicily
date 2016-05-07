// Problem#: 1924
// Submission#: 3718636
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

short sg[1005];

void init() {
    for (int i = 0; i < 1001; i++) {
        int temp = i << 1;
        int count = 0;
        while (temp) {
            if (temp & 1) count++;
            temp >>= 1;
        }
        sg[i] = (i << 1) + (count & 1);
    }
}

int main() {

    init();

    int CaseNum;
    scanf("%d\n", &CaseNum);

    while (CaseNum--) {
        int Ans = 0, k = 0;
        char text[2005];
        gets(text);
        gets(text);
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] == 'H') Ans ^= sg[k++];
            if (text[i] == 'T') k++;
        }
        printf(Ans ? "Alice\n" : "Bob\n");
    }

    return 0;
}                                 
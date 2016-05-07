// Problem#: 14460
// Submission#: 3716570
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>

char C2I[26][5];

int main() {

    char Letter[10][6] = { "\0", "\0", "abc\0", "def\0", "ghi\0", "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz"};
    
    for (int i = 1; i <= 9; i++) {
        int temp;
        scanf("%d", &temp);
        for (int j = 0; Letter[temp][j] != '\0'; j++) {
            for (int k = 0; k <= j; k++) C2I[Letter[temp][j] - 'a'][k] = i + '0';
        }
    }

    char Text[105], PreNum = -1;
    scanf("%s", Text);

    for (int i = 0; Text[i] != '\0'; i++) {
        if (C2I[Text[i] - 'a'][0] == PreNum) printf("#");
        printf("%s", C2I[Text[i] - 'a']);
        PreNum = C2I[Text[i] - 'a'][0];
    }
    printf("\n");

    return 0;
}                                 
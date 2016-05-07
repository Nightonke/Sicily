// Problem#: 1323
// Submission#: 2490533
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int lengtha, lengthb, middlea, i, j, middleb, emptya, emptyb;
    char a[1000], outputa[1000], b[1000], outputb[1000];
    while (gets(a) != NULL) {
        gets(b);
        emptya = emptyb = 0;
        lengtha = strlen(a);
        middlea = lengtha % 2 == 0 ? lengtha / 2 : lengtha / 2 + 1;
        for (i = 0; i < middlea; i++) {
            outputa[i] = a[middlea - i - 1];
        }
        j = 1;
        for (i = middlea; i < lengtha; i++) {
            outputa[i] = a[lengtha - j];
            j++;
        }
        outputa[i] = '\0';
        lengthb = strlen(b);
        middleb = lengthb % 2 == 0 ? lengthb / 2 : lengthb / 2 + 1;
        for (i = 0; i < middleb; i++) {
            outputb[i] = b[middleb - i - 1];
        }
        j = 1;
        for (i = middleb; i < lengthb; i++) {
            outputb[i] = b[lengthb - j];
            j++;
        }
        outputb[i] = '\0';
        for (i = 0; i < lengtha; i++)
            if (a[i] == ' ')
                emptya++;
        for (i = 0; i < lengthb; i++)
            if (b[i] == ' ')
                emptyb++;
        if (b[0] != '\0' && emptyb != lengthb)
            printf("%s\n", outputb);
        if (a[0] != '\0' && emptya != lengtha)
            printf("%s\n", outputa);
    }
    return 0;
}                                 
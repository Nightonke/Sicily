// Problem#: 1543
// Submission#: 2595338
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int length, i, counter;
    char a[100];
    while (gets(a)) {
        length = strlen(a);
        counter = 0;
        for (i = 0; i < length; i++) {
            if (a[i] == ']') {
                counter--;
                if (counter < 0) {
                    printf("[");
                    counter++;
                }
            }
            if (a[i] == '[') {
                counter++;
                if (counter < 0)
                    printf("[");
            }
        }
        printf("%s", a);
        memset(a, '\0', sizeof(a));
        for (i = 0; i < counter; i++)
            printf("]");
        printf("\n");
    }
    return 0;
}                                 
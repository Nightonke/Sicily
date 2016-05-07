// Problem#: 1624
// Submission#: 2496491
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int counter = 1, t, length, i;
    char encode[10000], corres[27];
    scanf("%d\n", &t);
    while (t--) {
        printf("%d ", counter);
        counter++;
        gets(encode);
        gets(corres);
        length = strlen(encode);
        for (i = 0; i < length; i++) {
            if (encode[i] >= 'A' && encode[i] <= 'Z') {
                printf("%c", corres[encode[i] - 'A']);
            }
            else
                printf("%c", encode[i]);
        }
        printf("\n");
    }
    return 0;
}                                 
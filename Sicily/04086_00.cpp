// Problem#: 4086
// Submission#: 2368920
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    int t, a, b, c, i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);
        for(i = 10; i <= 100; i++) {
            if ((i % 3 == a) && (i % 5 == b) && (i % 7 == c))
                break;}
        if (i <= 100)
            printf("%d\n", i);
        if (i > 100)
            printf("No answer\n");
    }
    return 0;
}                                 
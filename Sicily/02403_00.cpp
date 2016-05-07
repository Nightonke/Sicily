// Problem#: 2403
// Submission#: 2462031
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    char c;
    int y, n, p, a, counter;
    y = n = p = a = counter = 0;
    c = getchar();
    while (c != '#') {
        if (c == '\n') {
            if (2 * a >= counter)
                printf("need quorum\n");
            if (2 * a < counter) {
                if (y > n)
                    printf("yes\n");
                if (y < n)
                    printf("no\n");
                if (y == n)
                    printf("tie\n");
            }
            y = n = p = a = counter = 0;
        }
        if (c == 'Y')
            y++;
        if (c == 'N')
            n++;
        if (c == 'A')
            a++;
        if (c == 'P')
            p++;
        if (c != '\n')
            counter++;
        c = getchar();
    }
    return 0;
}                                 
// Problem#: 1087
// Submission#: 2662454
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n), n) {
        if (n < 3)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}                                 
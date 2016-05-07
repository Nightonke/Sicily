// Problem#: 2683
// Submission#: 2451630
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n;
    while(1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        if(n % 2 == 0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}                                 
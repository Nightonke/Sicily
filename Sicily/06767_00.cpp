// Problem#: 6767
// Submission#: 2470814
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, length;
    char a[80000];
    scanf("%d\n", &t);
    while (t--) {
        gets(a);
        length = strlen(a);
        if (a[length / 2 - 1] == a[length / 2])
            printf("Do-it\n");
        else
            printf("Do-it-Not\n");
    }
    return 0;
}                                 
// Problem#: 2382
// Submission#: 2705018
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int length, i, is_ok;
    char a[1100];
    while (1) {
        memset(a, '\0', sizeof(a));
        gets(a);
        if (a[0] == '*' && a[1] == '\0')
            break;
        length = (int)strlen(a);
        for (i = 0, is_ok = 1; i < length; i++) {
            if (a[i] == ' ' && i != length - 1 && !(a[i + 1] == a[0] || a[i + 1] == a[0] - ('a' - 'A') || a[i + 1] == a[0] - ('A' - 'a'))) {
                is_ok = 0;
                break;
            }
        }
        if (is_ok)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}                                 
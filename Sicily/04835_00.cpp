// Problem#: 4835
// Submission#: 2701671
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int change(char c) {
    int ch[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    if (c >= 'A' && c <= 'Z')
        return ch[c - 65];
    else
        return ch[c - 97];
}

int main() {
    int t, length, i, b[25], is_ok;
    char a[25];
    scanf("%d", &t);
    while (t--) {
        memset(a, '\0', sizeof(a));
        scanf("%s", a);
        length = (int)strlen(a);
        for (i = 0; i < length; i++) {
            b[i] = change(a[i]);
        }
        is_ok = 1;
        for (i = 0; i <= length / 2 - 1; i++) {
            if (b[i] != b[length - 1 - i]) {
                is_ok = 0;
                break;
            }
        }
        if (is_ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}                                 
// Problem#: 1389
// Submission#: 2774523
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char a[85];

int calculate(char dir, int pos) {
    if (pos == 0 && dir == 'l')
        return 1;
    else if (pos == (int)strlen(a) - 1 && dir == 'r')
        return 1;
    else if (dir == 'l') {
        for (int i = pos - 1; i >= 0; i--) {
            if (a[i] == '.')
                return 1;
            else if (a[i] == '\\' || a[i] == '|')
                return 0;
        }
        return 1;
    } else if (dir == 'r') {
        for (int i = pos + 1; i < (int)strlen(a); i++) {
            if (a[i] == '.')
                return 1;
            else if (a[i] == '|' || a[i] == '/')
                return 0;
        }
        return 1;
    }
}

int main() {
    while (gets(a) && a[0] != '#') {
        float sum = 0;
        for (int i = 0; i < (int)strlen(a); i++) {
            if (a[i] == '.')
                sum += 1;
            else if (a[i] == '_')
                sum += 0;
            else if (a[i] == '/')
                sum += calculate('l', i);
            else if (a[i] == '\\')
                sum += calculate('r', i);
            else if (a[i] == '|')
                sum += 0.5 * calculate('l', i) + 0.5 * calculate('r', i);
        }
        int int_sum = sum * 100 / (float)strlen(a);
        printf("%d\n", int_sum);
        memset(a, '\0', sizeof(a));
    }
    return 0;
}                                 
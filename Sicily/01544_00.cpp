// Problem#: 1544
// Submission#: 2593587
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
char a[1000];
bool number[10];
int store[10];
int judge() {
    if (a[0] == '0')
        return 0;
    for (int i = 0; i < (int)strlen(a); i++)
        if (!number[a[i] - '0'])
            return 0;
    return 1;
}

int findbigger(int min, int n) {
    for (int i = 1; min + i < 10; i++) {
        if (number[min + i]) {
            return min + i;
        }
    }
}

int main() {
    int n, max, min, store[10], i, length, temp[1000], counter, l;
    char b[11];
    while (gets(b)) {
        memset(number, false, sizeof(number));
        memset(temp, 0, sizeof(temp));
        max = 0;
        min = 9;
        l = strlen(b);
        for (i = 0; i < l; i++) {
            number[b[i] - '0'] = true;
            if (b[i] - '0' > max)
                max = b[i] - '0';
            if (b[i] - '0' < min)
                min = b[i] - '0';
        }
        gets(a);
        if (!judge()) {
            printf("INVALID INPUT\n");
            continue;
        }
        length = strlen(a);
        for (i = 0; i < length; i++) {
            temp[i] = a[length - i - 1] - '0';
        }
        if (temp[0] < max) {
            temp[0] = findbigger(temp[0], n);
            for (i = length - 1; i >= 0; i--)
                printf("%d", temp[i]);
            printf("\n");
            continue;
        }
        counter = 0;
        for (i = 0; i < length; i++) {
            if (temp[i] < max) {
                temp[i] = findbigger(temp[i], n);
                break;
            }
            if (temp[i] >= max) {
                temp[i] = min;
                counter++;
            }
        }
        if (counter == length && temp[length] == 0) {
            if (min == 0)
                printf("%d", findbigger(min, n));
            else
                printf("%d", min);
        }
        for (i = length - 1; i >= 0; i--) {
            printf("%d", temp[i]);
        }
        printf("\n");
    }
    return 0;
}                                 
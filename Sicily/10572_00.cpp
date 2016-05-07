// Problem#: 10572
// Submission#: 2808715
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char a[1001], b[1001];
int length;
int half_length;
int counter;

void change() {
    char temp[1001];
    memset(temp, '\0', sizeof(temp));
    int i = 0;
    while (i < length) {
        temp[i / 2] = b[i];
        i++;
        if (i >= length)
            break;
        temp[length - i / 2 - 1] = b[i];
        i++;
    }
    strcpy(b, temp);
}

int main() {
    int n;
    scanf("%d", &n);
    memset(a, '\0', sizeof(a));
    memset(b, '\0', sizeof(b));
    scanf("%s", a);
    length = strlen(a);
    strcpy(b, a);
    change();
    counter = 1;
    while (strcmp(a, b)) {
        change();
        counter++;
    }
    n %= counter;
    while (n--) {
        change();
    }
    printf("%s\n", b);
    return 0;
}                                 
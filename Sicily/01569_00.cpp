// Problem#: 1569
// Submission#: 2596150
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

void print(char out, char end) {
    if (end >= 'A' && end <= 'Z')
        printf("%c", out - ('a' - 'A'));
    else
        printf("%c", out);
}

void abc(char end, int num) {
    int n;
    char out;
    if (end == 'A' || end == 'a') {
        n = 121;
    }
    if (end == 'B' || end == 'b') {
        n = 122;
    }
    if (end == 'C' || end == 'c') {
        n = 123;
    }
    n = (n - num) % 3;
    if (n == 1) {
        out = 'a';
    }
    if (n == 2) {
        out = 'b';
    }
    if (n == 0) {
        out = 'c';
    }
    print(out, end);
}

void def(char end, int num) {
    int n;
    char out;
    if (end == 'D' || end == 'd') {
        n = 121;
    }
    if (end == 'E' || end == 'e') {
        n = 122;
    }
    if (end == 'F' || end == 'f') {
        n = 123;
    }
    n = (n - num) % 3;
    if (n == 1) {
        out = 'd';
    }
    if (n == 2) {
        out = 'e';
    }
    if (n == 0) {
        out = 'f';
    }
    print(out, end);
}

void ghi(char end, int num) {
    int n;
    char out;
    if (end == 'G' || end == 'g') {
        n = 121;
    }
    if (end == 'H' || end == 'h') {
        n = 122;
    }
    if (end == 'I' || end == 'i') {
        n = 123;
    }
    n = (n - num) % 3;
    if (n == 1) {
        out = 'g';
    }
    if (n == 2) {
        out = 'h';
    }
    if (n == 0) {
        out = 'i';
    }
    print(out, end);
}

void jkl(char end, int num) {
    int n;
    char out;
    if (end == 'J' || end == 'j') {
        n = 121;
    }
    if (end == 'K' || end == 'k') {
        n = 122;
    }
    if (end == 'L' || end == 'l') {
        n = 123;
    }
    n = (n - num) % 3;
    if (n == 1) {
        out = 'j';
    }
    if (n == 2) {
        out = 'k';
    }
    if (n == 0) {
        out = 'l';
    }
    print(out, end);
}

void mno(char end, int num) {
    int n;
    char out;
    if (end == 'M' || end == 'm') {
        n = 121;
    }
    if (end == 'N' || end == 'n') {
        n = 122;
    }
    if (end == 'O' || end == 'o') {
        n = 123;
    }
    n = (n - num) % 3;
    if (n == 1) {
        out = 'm';
    }
    if (n == 2) {
        out = 'n';
    }
    if (n == 0) {
        out = 'o';
    }
    print(out, end);
}

void tuv(char end, int num) {
    int n;
    char out;
    if (end == 'T' || end == 't') {
        n = 121;
    }
    if (end == 'U' || end == 'u') {
        n = 122;
    }
    if (end == 'V' || end == 'v') {
        n = 123;
    }
    n = (n - num) % 3;
    if (n == 1) {
        out = 't';
    }
    if (n == 2) {
        out = 'u';
    }
    if (n == 0) {
        out = 'v';
    }
    print(out, end);
}

void pqrs(char end, int num) {
    int n;
    char out;
    if (end == 'P' || end == 'p') {
        n = 121;
    }
    if (end == 'Q' || end == 'q') {
        n = 122;
    }
    if (end == 'R' || end == 'r') {
        n = 123;
    }
    if (end == 'S' || end == 's') {
        n = 124;
    }
    n = (n - num) % 4;
    if (n == 1) {
        out = 'p';
    }
    if (n == 2) {
        out = 'q';
    }
    if (n == 3) {
        out = 'r';
    }
    if (n == 0) {
        out = 's';
    }
    print(out, end);
}

void wxyz(char end, int num) {
    int n;
    char out;
    if (end == 'W' || end == 'w') {
        n = 121;
    }
    if (end == 'X' || end == 'x') {
        n = 122;
    }
    if (end == 'Y' || end == 'y') {
        n = 123;
    }
    if (end == 'Z' || end == 'z') {
        n = 124;
    }
    n = (n - num) % 4;
    if (n == 1) {
        out = 'w';
    }
    if (n == 2) {
        out = 'x';
    }
    if (n == 3) {
        out = 'y';
    }
    if (n == 0) {
        out = 'z';
    }
    print(out, end);
}

int main() {
    int length, i;
    char a[101];
    while (gets(a)) {
        if (a[0] == '#')
            break;
        length = strlen(a);
        for (i = 0; i < length; i++) {
            if ((a[i] >= 'A' && a[i] <= 'C') || (a[i] >= 'a' && a[i] <= 'c'))
                abc(a[i], i + 1);
            if ((a[i] >= 'D' && a[i] <= 'F') || (a[i] >= 'd' && a[i] <= 'f'))
                def(a[i], i + 1);
            if ((a[i] >= 'G' && a[i] <= 'I') || (a[i] >= 'g' && a[i] <= 'i'))
                ghi(a[i], i + 1);
            if ((a[i] >= 'J' && a[i] <= 'L') || (a[i] >= 'j' && a[i] <= 'l'))
                jkl(a[i], i + 1);
            if ((a[i] >= 'M' && a[i] <= 'O') || (a[i] >= 'm' && a[i] <= 'o'))
                mno(a[i], i + 1);
            if ((a[i] >= 'P' && a[i] <= 'S') || (a[i] >= 'p' && a[i] <= 's'))
                pqrs(a[i], i + 1);
            if ((a[i] >= 'T' && a[i] <= 'V') || (a[i] >= 't' && a[i] <= 'v'))
                tuv(a[i], i + 1);
            if ((a[i] >= 'W' && a[i] <= 'Z') || (a[i] >= 'w' && a[i] <= 'z'))
                wxyz(a[i], i + 1);
        }
        printf("\n");
        memset(a, '\0', sizeof(a));
    }
    return 0;
}                                 
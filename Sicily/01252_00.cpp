// Problem#: 1252
// Submission#: 2586893
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char a[110];
int length, jp, js, lp, ls;

int judge_pre() {
    if (a[0] == 'a' && a[1] == 'n' && a[2] == 't' && a[3] == 'i') {
        lp = 4;
        return 1;
    }
    if (a[0] == 'p' && a[1] == 'o' && a[2] == 's' && a[3] == 't') {
        lp = 4;
        return 2;
    }
    if (a[0] == 'p' && a[1] == 'r' && a[2] == 'e') {
        lp = 3;
        return 3;
    }
    if (a[0] == 'r' && a[1] == 'e') {
        lp = 2;
        return 4;
    }
    if (a[0] == 'u' && a[1] == 'n') {
        lp = 2;
        return 5;
    }
    lp = 0;
    return 0;
}

int judge_suf() {
    if (length > 1 && a[length - 1] == 'r' && a[length - 2] == 'e') {
        ls = 2;
        return 1;
    }
    if (length > 2 && a[length - 1] == 'g' && a[length - 2] == 'n' && a[length - 3] == 'i') {
        ls = 3;
        return 2;
    }
    if (length > 2 && a[length - 1] == 'e' && a[length - 2] == 'z' && a[length - 3] == 'i') {
        ls = 3;
        return 3;
    }
    if (length > 0 && a[length - 1] == 's') {
        ls = 1;
        return 4;
    }
    if (length > 3 && a[length - 1] == 'n' && a[length - 2] == 'o' && a[length - 3] == 'i' && a[length - 4] == 't') {
        ls = 4;
        return 5;
    }
    ls = 0;
    return 0;
}

void print_pre(int i) {
    if (i == 0)
        return;
    if (i == 1)
        printf("against ");
    if (i == 2)
        printf("after ");
    if (i == 3)
        printf("before ");
    if (i == 4)
        return;
    if (i == 5)
        printf("not ");
}

void print_suf(int i) {
    if (i == 0)
        return;
    if (i == 1)
        printf("one who ");
    if (i == 2)
        printf("to actively ");
    if (i == 3)
        printf("change into ");
    if (i == 4)
        printf("multiple instances of ");
    if (i == 5)
        printf("the process of ");
}

void dig() {
    int i;
    for (i = lp; i < length - ls; i++)
        printf("%c", a[i]);
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        memset(a, '\0', sizeof(a));
        gets(a);
        length = strlen(a);
        jp = judge_pre();
        js = judge_suf();
        if (jp == 0 && js == 0) {
            printf("%s\n", a);
            continue;
        }
        print_pre(jp);
        print_suf(js);
        dig();
        if (js == 1)
            printf("s");
        if (js == 5)
            printf("ing");
        if (jp == 4)
            printf(" again");
        printf("\n");
    }
    return 0;
}                                 
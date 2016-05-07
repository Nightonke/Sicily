// Problem#: 1487
// Submission#: 2591803
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char a[100000], temp[100000], temp2[100000];
int p1, p2, p3;

void upper(int length) {
    int i;
    for (i = 0; i < length; i++) {
        temp[i] = temp[i] - ('a' - 'A');
    }
}

void strrev1(int length) {
    int i;
    char zj;
    for (i = 0; i <= (length - 1) / 2; i++) {
        zj = temp[i];
        temp[i] = temp[length - 1 - i];
        temp[length - 1 - i] = zj;
    }
}

void cut(int i) {
    int j;
    for (j = i; j < 99999; j++) {
        a[j] = a[j + 1];
    }
    a[j] = '\0';
}

void filleng(int i) {
    memset(temp, '\0', sizeof(temp));
    memset(temp2, '\0', sizeof(temp2));
    int j, k, k2, kind;
    kind = a[i + 1] - a[i - 1] - 1;
    if (p1 != 3) {
        for (j = 0; j < kind; j++) {
            for (k = j * p2; k < (j + 1) * p2; k++) {
                temp[k] = a[i - 1] + 1 + j;
            }
        }
        if (p1 == 2)
            upper(kind * p2);
        if (p3 == 2)
            strrev1(kind * p2);
    }
    if (p1 == 3) {
        for (j = 0; j < kind * p2; j++) {
            temp[j] = '*';
        }
    }
    k = 0;
    for (j = i + 1; j < 100000; j++) {
        temp2[k++] = a[j];
    }
    k = 0;
    for (j = i; j < i + kind * p2; j++) {
        a[j] = temp[k++];
    }
    k2 = 0;
    for (k = j; k < 100000; k++, k2++) {
        a[k] = temp2[k2];
    }
}

void fillnum(int i) {
    memset(temp, '\0', sizeof(temp));
    memset(temp2, '\0', sizeof(temp2));
    int j, k, k2, kind;
    kind = a[i + 1] - a[i - 1] - 1;
    if (p1 == 3) {
        for (j = 0; j < kind * p2; j++) {
            temp[j] = '*';
        }
    }
    if (p1 != 3) {
        for (j = 0; j < kind; j++) {
            for (k = j * p2; k < (j + 1) * p2; k++) {
                temp[k] = a[i - 1] + 1 + j;
            }
        }
        if (p3 == 2)
            strrev1(kind * p2);
    }
    k = 0;
    for (j = i + 1; j < 100000; j++) {
        temp2[k++] = a[j];
    }
    k = 0;
    for (j = i; j < i + kind * p2; j++) {
        a[j] = temp[k++];
    }
    k2 = 0;
    for (k = j; k < 100000; k++, k2++) {
        a[k] = temp2[k2];
    }
}
    
void solve(char a[]) {
    int length, i;
    length = strlen(a);
    for (i = 1; i < 99999; i++) {
        if (a[i] == '-' && (a[i - 1] == a[i + 1] - 1)) {
            cut(i);
        }
        if (a[i] == '-' && ((a[i + 1] >= '0' && a[i + 1] <= '9' && a[i - 1] >= '0' && a[i - 1] <= '9') || (a[i + 1] >= 'a' && a[i + 1] <= 'z' && a[i - 1] <= 'z' && a[i - 1] >= 'a')) && a[i + 1] > a[i - 1]) {
            if (a[i + 1] >= '0' && a[i + 1] <= '9')
                fillnum(i);
            if (a[i + 1] >= 'a' && a[i + 1] <= 'z')
                filleng(i);
        }
    }
}

int main() {
    int kongzhi = 0;
    while (scanf("%d %d %d\n", &p1, &p2, &p3) == 3) {
        memset(a, '\0', sizeof(a));
        gets(a);
        solve(a);
        if (kongzhi)
            printf("\n");
        kongzhi = 1;
        printf("%s\n", a);
    }
    return 0;
}                                 
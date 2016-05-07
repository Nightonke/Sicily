// Problem#: 1702
// Submission#: 2700518
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

struct word {
    char a[30];
    bool have_found;
};

word w[30];
char temp[110], check[100][110];

void work(int n) {
    int length, i, k = 0, j, u;
    memset(check, '\0', sizeof(check));
    length = (int)strlen(temp);
    temp[length] = ' ';
    length++;
    for (i = 0, k = 0; i < length; i++) {
        if ((temp[i] != ' ' && temp[i - 1] == ' ') || (temp[i] != ' ' && i == 0)) {
            for (u = 0, j = i; temp[j] != ' '; j++, u++) {
                check[k][u] = temp[j];
            }
            k++;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            if (strcmp(w[i].a, check[j]) == 0) {
                w[i].have_found = true;
            }
        }
    }
}

int main() {
    int counter = 0, t, i, n, m;
    scanf("%d", &t);
    while (t--) {
        counter++;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%s\n", w[i].a);
            w[i].have_found = false;
        }
        scanf("%d\n", &m);
        while (m--) {
            memset(temp, '\0', sizeof(temp));
            gets(temp);
            work(n);
        }
        printf("Test set %d:\n", counter);
        for (i = 0; i < n; i++) {
            if (w[i].have_found) {
                printf("%s is present\n", w[i].a);
            } else {
                printf("%s is absent\n", w[i].a);
            }
        }
        printf("\n");
    }
    return 0;
}                                 
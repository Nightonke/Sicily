// Problem#: 4495
// Submission#: 2702085
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int n;
char c[10];
bool has_printed[10];

void dfs(char a[]) {
    int i, temp;
    if (n == (int)strlen(a)) {
        printf("%s\n", a);
        return;
    }
    for (i = 0; i < n; i++) {
        if (!has_printed[i]) {
            has_printed[i] = true;
            temp = (int)strlen(a);
            a[temp] = c[i];
            dfs(a);
            a[temp] = '\0';
            a[temp] = '\0';
            has_printed[i] = false;
        }
    }
    return;
}

int main() {
    char a[10];
    scanf("%s", c);
    n = strlen(c);
    memset(a, '\0', sizeof(a));
    memset(has_printed, false, sizeof(has_printed));
    dfs(a);
    return 0;
}                                 